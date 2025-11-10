#!/usr/bin/env python3
"""Generate a control-flow graph in Graphviz DOT format from a TAC .x file."""

from __future__ import annotations

import argparse
import os
import re
import sys
from dataclasses import dataclass
from typing import Dict, List, Optional, Sequence, Tuple

LINE_RE = re.compile(r"^0x[0-9a-fA-F]+\s+(.*)$")


@dataclass
class Instruction:
    index: int
    text: str


@dataclass
class Block:
    name: str
    instructions: List[str]


class CFGBuilder:
    def __init__(self, instructions: Sequence[Instruction]):
        self.instructions = list(instructions)
        self.blocks: List[Block] = []
        self.label_to_block: Dict[str, Block] = {}

    def build(self) -> None:
        if not self.instructions:
            return

        starts = self._find_block_boundaries()
        for order, start in enumerate(starts):
            end = starts[order + 1] if order + 1 < len(starts) else len(self.instructions)
            block_ins = [ins.text for ins in self.instructions[start:end]]
            if not block_ins:
                continue
            block_name = self._derive_block_name(block_ins, order)
            block = Block(name=block_name, instructions=block_ins)
            self.blocks.append(block)
            for text in block_ins:
                if text.startswith("label "):
                    parts = text.split()
                    if len(parts) >= 2:
                        self.label_to_block[parts[1]] = block

    def _find_block_boundaries(self) -> List[int]:
        starts = {0}
        for idx, ins in enumerate(self.instructions):
            text = ins.text
            if text.startswith("label "):
                starts.add(idx)
                continue
            tokens = text.split()
            if not tokens:
                continue
            op = tokens[0]
            is_branch = False
            if op == "goto":
                is_branch = True
            elif op == "ifz" and "goto" in tokens:
                is_branch = True
            elif op in {"return", "end"}:
                is_branch = True
            if is_branch and idx + 1 < len(self.instructions):
                starts.add(idx + 1)
        return sorted(starts)

    @staticmethod
    def _derive_block_name(instructions: Sequence[str], order: int) -> str:
        for text in instructions:
            if text.startswith("label "):
                parts = text.split()
                if len(parts) >= 2:
                    return parts[1]
        return f"B{order}"

    def successors(self) -> Dict[str, List[Tuple[str, Optional[str]]]]:
        succ: Dict[str, List[Tuple[str, Optional[str]]]] = {}
        block_map = {block.name: idx for idx, block in enumerate(self.blocks)}
        for idx, block in enumerate(self.blocks):
            last_instruction = self._find_last_instruction(block.instructions)
            outgoing: List[Tuple[str, Optional[str]]] = []
            next_block_name = self.blocks[idx + 1].name if idx + 1 < len(self.blocks) else None
            if last_instruction is None:
                if next_block_name:
                    outgoing.append((next_block_name, None))
            else:
                tokens = last_instruction.split()
                op = tokens[0]
                if op == "goto" and len(tokens) >= 2:
                    target = tokens[1]
                    dest = self._lookup_block(target, block_map)
                    if dest:
                        outgoing.append((dest.name, None))
                elif op == "ifz" and "goto" in tokens:
                    try:
                        goto_index = tokens.index("goto")
                        target = tokens[goto_index + 1]
                        condition = tokens[1] if len(tokens) > 1 else "cond"
                    except (ValueError, IndexError):
                        target = None
                        condition = "cond"
                    if target:
                        dest = self._lookup_block(target, block_map)
                        if dest:
                            outgoing.append((dest.name, f"{condition}==0"))
                    if next_block_name:
                        outgoing.append((next_block_name, f"{condition}!=0"))
                elif op in {"return", "end"}:
                    pass
                else:
                    if next_block_name:
                        outgoing.append((next_block_name, None))
            succ[block.name] = self._deduplicate_edges(outgoing)
        return succ

    @staticmethod
    def _find_last_instruction(instructions: Sequence[str]) -> Optional[str]:
        for text in reversed(instructions):
            stripped = text.strip()
            if not stripped:
                continue
            if stripped.startswith("label "):
                continue
            return stripped
        return None

    def _lookup_block(self, label: str, block_map: Dict[str, int]) -> Optional[Block]:
        block = self.label_to_block.get(label)
        if block:
            return block
        # Attempt fallback for auto-named blocks.
        index = block_map.get(label)
        if index is None:
            return None
        return self.blocks[index]

    @staticmethod
    def _deduplicate_edges(edges: Sequence[Tuple[str, Optional[str]]]) -> List[Tuple[str, Optional[str]]]:
        seen = set()
        ordered: List[Tuple[str, Optional[str]]] = []
        for dest, label in edges:
            key = (dest, label)
            if key in seen:
                continue
            seen.add(key)
            ordered.append((dest, label))
        return ordered


def parse_instructions(path: str) -> List[Instruction]:
    instructions: List[Instruction] = []
    with open(path, "r", encoding="utf-8") as f:
        for idx, line in enumerate(f):
            line = line.strip()
            if not line or line.startswith("#"):
                continue
            match = LINE_RE.match(line)
            if not match:
                continue
            text = match.group(1).strip()
            if text:
                instructions.append(Instruction(index=idx, text=text))
    return instructions


def escape_label(text: str) -> str:
    return text.replace("\\", "\\\\").replace("\"", "\\\"")


def build_dot(blocks: Sequence[Block], successors: Dict[str, List[Tuple[str, Optional[str]]]]) -> str:
    lines = ["digraph CFG {", "  node [shape=box, fontname=\"Courier\"]; "]
    for block in blocks:
        body = "\\l".join(escape_label(instr) for instr in block.instructions) + "\\l"
        label_text = f"{escape_label(block.name)}\\l{body}" if body else escape_label(block.name)
        lines.append(f'  "{block.name}" [label="{label_text}"];')
    for src, edges in successors.items():
        for dest, edge_label in edges:
            if edge_label:
                lines.append(f'  "{src}" -> "{dest}" [label="{escape_label(edge_label)}"];')
            else:
                lines.append(f'  "{src}" -> "{dest}";')
    lines.append("}")
    return "\n".join(lines)


def main(argv: Optional[Sequence[str]] = None) -> int:
    parser = argparse.ArgumentParser(description="Generate a control-flow graph from a TAC .x file.")
    parser.add_argument("input", help="Path to the TAC .x file")
    parser.add_argument("-o", "--output", help="Path to write DOT output; defaults to stdout")
    args = parser.parse_args(argv)

    if not os.path.exists(args.input):
        parser.error(f"input file '{args.input}' does not exist")

    instructions = parse_instructions(args.input)
    builder = CFGBuilder(instructions)
    builder.build()
    dot_source = build_dot(builder.blocks, builder.successors())

    if args.output:
        with open(args.output, "w", encoding="utf-8") as f:
            f.write(dot_source)
    else:
        sys.stdout.write(dot_source)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())

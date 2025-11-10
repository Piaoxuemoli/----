#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "tac.h"
#include "obj.h"

/* global var */
int tos; /* top of static */
int tof; /* top of frame */
int oof; /* offset of formal */
int oon; /* offset of next frame */
struct rdesc rdesc[R_NUM];

static int sym_requires_writeback(SYM *sym)
{
	if(sym==NULL) return 0;
	if(sym->type!=SYM_VAR) return 0;
	return 1;
}

static TAC *find_label_tac_obj(SYM *label)
{
	for(TAC *iter=tac_first; iter!=NULL; iter=iter->next)
	{
		if(iter->op==TAC_LABEL && iter->a==label)
		{
			return iter;
		}
	}
	return NULL;
}

static SYM *resolve_jump_target(SYM *label)
{
	SYM *current=label;
	for(int depth=0; depth<16; ++depth)
	{
		if(current==NULL) break;
		TAC *lt=find_label_tac_obj(current);
		if(lt==NULL) break;
		TAC *after=lt->next;
		while(after!=NULL && after->op==TAC_LABEL && after->a==current)
		{
			after=after->next;
		}
		if(after!=NULL && after->op==TAC_GOTO && after->a!=current)
		{
			current=after->a;
			continue;
		}
		break;
	}
	return current;
}

static int target_is_next_label(TAC *node, SYM *label)
{
	for(TAC *scan=node->next; scan!=NULL; scan=scan->next)
	{
		if(scan->op==TAC_LABEL)
		{
			if(scan->a==label)
			{
				return 1;
			}
			continue;
		}
		return 0;
	}
	return 0;
}

static int sym_size_bytes(SYM *sym)
{
	if(sym==NULL) return 4;
	if(sym->type!=SYM_VAR) return 4;
	if(is_array_type(sym->data_type))
	{
		ARRAY_INFO *info=(ARRAY_INFO *)sym->etc;
		if(info==NULL) return 4;
		return info->total_size;
	}
	if(sym->data_type==TYPE_STRUCT)
	{
		STRUCT_TYPE *stype=(STRUCT_TYPE *)sym->etc;
		if(stype==NULL) return 4;
		return stype->size;
	}
	return 4;
}

void rdesc_clear(int r)    
{
	rdesc[r].var = NULL;
	rdesc[r].mod = 0;
}

void rdesc_fill(int r, SYM *s, int mod)
{
	int old;
	for(old=R_GEN; old < R_NUM; old++)
	{
		if(rdesc[old].var==s)
		{
			rdesc_clear(old);
		}
	}

	rdesc[r].var=s;
	rdesc[r].mod=mod;
}     

void asm_write_back(int r)
{
	if(rdesc[r].var==NULL || !rdesc[r].mod)
	{
		return;
	}
	SYM *sym=rdesc[r].var;
	if(sym_requires_writeback(sym))
	{
		if(sym->scope==1) /* local var */
		{
			out_str(file_s, "	STO (R%u+%u),R%u\n", R_BP, sym->offset, r);
		}
		else /* global var */
		{
			out_str(file_s, "	LOD R%u,STATIC\n", R_TP);
			out_str(file_s, "	STO (R%u+%u),R%u\n", R_TP, sym->offset, r);
		}
	}
	rdesc[r].mod=UNMODIFIED;
}

void asm_load(int r, SYM *s) 
{
	/* already in a reg */
	for(int i=R_GEN; i < R_NUM; i++)  
	{
		if(rdesc[i].var==s)
		{
			/* load from the reg */
			out_str(file_s, "	LOD R%u,R%u\n", r, i);

			/* update rdesc */
			// rdesc_fill(r, s, rdesc[i].mod);
			return;
		}
	}
	
	/* not in a reg */
	switch(s->type)
	{
		case SYM_INT:
		out_str(file_s, "	LOD R%u,%u\n", r, s->value);
		break;

		case SYM_VAR:
		if(s->scope==1) /* local var */
		{
			if((s->offset)>=0) out_str(file_s, "	LOD R%u,(R%u+%d)\n", r, R_BP, s->offset);
			else out_str(file_s, "	LOD R%u,(R%u-%d)\n", r, R_BP, -(s->offset));
		}
		else /* global var */
		{
			out_str(file_s, "	LOD R%u,STATIC\n", R_TP);
			out_str(file_s, "	LOD R%u,(R%u+%d)\n", r, R_TP, s->offset);
		}
		break;

		case SYM_TEXT:
		out_str(file_s, "	LOD R%u,L%u\n", r, s->label);
		break;
	}

	// rdesc_fill(r, s, UNMODIFIED);
}   

int reg_alloc(SYM *s)
{
	int r; 

	/* already in a register */
	for(r=R_GEN; r < R_NUM; r++)
	{
		if(rdesc[r].var==s)
		{
			if(rdesc[r].mod) asm_write_back(r);
			return r;
		}
	}

	/* empty register */
	for(r=R_GEN; r < R_NUM; r++)
	{
		if(rdesc[r].var==NULL)
		{
			asm_load(r, s);
			rdesc_fill(r, s, UNMODIFIED);
			return r;
		}

	}
	
	/* unmodifed register */
	for(r=R_GEN; r < R_NUM; r++)
	{
		if(!rdesc[r].mod)
		{
			asm_load(r, s);
			rdesc_fill(r, s, UNMODIFIED);
			return r;
		}
	}

	/* random register */
	srand(time(NULL));
	int random = (rand() % (R_NUM - R_GEN)) + R_GEN; 
	asm_write_back(random);
	asm_load(random, s);
	rdesc_fill(random, s, UNMODIFIED);
	return random;
}

static const char *tac_bin_mnemonic(int op)
{
	switch(op)
	{
		case TAC_ADD:
		return "ADD";
		case TAC_SUB:
		return "SUB";
		case TAC_MUL:
		return "MUL";
		case TAC_DIV:
		return "DIV";
		default:
		return "ADD";
	}
}

static int tac_is_commutative_bin(int op)
{
	return op==TAC_ADD || op==TAC_MUL;
}

void asm_bin(int op, SYM *a, SYM *b, SYM *c)
{
	SYM *lhs=b;
	SYM *rhs=c;
	if(rhs!=NULL && rhs->type==SYM_INT)
	{
		/* ok */
	}
	else if(tac_is_commutative_bin(op) && lhs!=NULL && lhs->type==SYM_INT && rhs!=NULL)
	{
		SYM *tmp=lhs;
		lhs=rhs;
		rhs=tmp;
	}

	const char *mnemonic=tac_bin_mnemonic(op);
	if(rhs!=NULL && rhs->type==SYM_INT && lhs!=NULL)
	{
		int reg_b = reg_alloc(lhs);
		int imm=rhs->value;
		if(op==TAC_SUB && mnemonic[0]=='S')
		{
			out_str(file_s, "\t%s R%u,%d\n", mnemonic, reg_b, imm);
		}
		else if(op==TAC_DIV && imm==0)
		{
			/* assembler/VM will catch divide by zero at runtime */
			out_str(file_s, "\t%s R%u,%d\n", mnemonic, reg_b, imm);
		}
		else
		{
			out_str(file_s, "\t%s R%u,%d\n", mnemonic, reg_b, imm);
		}
		rdesc_fill(reg_b, a, MODIFIED);
		return;
	}

	int reg_b = reg_alloc(lhs);
	int reg_c = reg_alloc(rhs);
	if(reg_b == reg_c)
	{
		int alt=-1;
		for(int r=R_GEN; r < R_NUM; r++)
		{
			if(r==reg_b) continue;
			if(rdesc[r].var==NULL)
			{
				asm_load(r, rhs);
				rdesc_fill(r, rhs, UNMODIFIED);
				alt=r;
				break;
			}
		}
		if(alt==-1)
		{
			for(int r=R_GEN; r < R_NUM; r++)
			{
				if(r==reg_b) continue;
				asm_write_back(r);
				asm_load(r, rhs);
				rdesc_fill(r, rhs, UNMODIFIED);
				alt=r;
				break;
			}
		}
		if(alt==-1)
		{
			alt=reg_b;
		}
		reg_c=alt;
		if(rdesc[reg_b].var!=lhs)
		{
			asm_load(reg_b, lhs);
			rdesc_fill(reg_b, lhs, UNMODIFIED);
		}
	}
	
	out_str(file_s, "	%s R%u,R%u\n", mnemonic, reg_b, reg_c);
	rdesc_fill(reg_b, a, MODIFIED);
}   

void asm_cmp(int op, SYM *a, SYM *b, SYM *c)
{
	int reg_b = reg_alloc(b);
	if(c!=NULL && c->type==SYM_INT)
	{
		out_str(file_s, "	SUB R%u,%d\n", reg_b, c->value);
	}
	else
	{
		int reg_c = reg_alloc(c);
		if(reg_c == reg_b)
		{
			int alt=-1;
			for(int r=R_GEN; r < R_NUM; r++)
			{
				if(r==reg_b) continue;
				if(rdesc[r].var==NULL)
				{
					alt=r;
					break;
				}
			}
			if(alt==-1)
			{
				for(int r=R_GEN; r < R_NUM; r++)
				{
					if(r==reg_b) continue;
					if(!sym_requires_writeback(rdesc[r].var) || !rdesc[r].mod)
					{
						alt=r;
						break;
					}
				}
			}
			if(alt==-1)
			{
				alt = (reg_b==R_GEN) ? R_GEN+1 : R_GEN;
				asm_write_back(alt);
			}
			asm_load(alt, c);
			rdesc_fill(alt, c, UNMODIFIED);
			reg_c=alt;
			if(rdesc[reg_b].var!=b)
			{
				asm_load(reg_b, b);
				rdesc_fill(reg_b, b, UNMODIFIED);
			}
		}
		out_str(file_s, "	SUB R%u,R%u\n", reg_b, reg_c);
	}
	out_str(file_s, "	TST R%u\n", reg_b);

	switch(op)
	{
		case TAC_EQ:
		out_str(file_s, "	LOD R3,R1+40\n");
		out_str(file_s, "	JEZ R3\n");
		out_str(file_s, "	LOD R%u,0\n", reg_b);
		out_str(file_s, "	LOD R3,R1+24\n");
		out_str(file_s, "	JMP R3\n");
		out_str(file_s, "	LOD R%u,1\n", reg_b);
		break;

		case TAC_NE:
		out_str(file_s, "	LOD R3,R1+40\n");
		out_str(file_s, "	JEZ R3\n");
		out_str(file_s, "	LOD R%u,1\n", reg_b);
		out_str(file_s, "	LOD R3,R1+24\n");
		out_str(file_s, "	JMP R3\n");
		out_str(file_s, "	LOD R%u,0\n", reg_b);
		break;

		case TAC_LT:
		out_str(file_s, "	LOD R3,R1+40\n");
		out_str(file_s, "	JLZ R3\n");
		out_str(file_s, "	LOD R%u,0\n", reg_b);
		out_str(file_s, "	LOD R3,R1+24\n");
		out_str(file_s, "	JMP R3\n");
		out_str(file_s, "	LOD R%u,1\n", reg_b);
		break;

		case TAC_LE:
		out_str(file_s, "	LOD R3,R1+40\n");
		out_str(file_s, "	JGZ R3\n");
		out_str(file_s, "	LOD R%u,1\n", reg_b);
		out_str(file_s, "	LOD R3,R1+24\n");
		out_str(file_s, "	JMP R3\n");
		out_str(file_s, "	LOD R%u,0\n", reg_b);
		break;

		case TAC_GT:
		out_str(file_s, "	LOD R3,R1+40\n");
		out_str(file_s, "	JGZ R3\n");
		out_str(file_s, "	LOD R%u,0\n", reg_b);
		out_str(file_s, "	LOD R3,R1+24\n");
		out_str(file_s, "	JMP R3\n");
		out_str(file_s, "	LOD R%u,1\n", reg_b);
		break;

		case TAC_GE:
		out_str(file_s, "	LOD R3,R1+40\n");
		out_str(file_s, "	JLZ R3\n");
		out_str(file_s, "	LOD R%u,1\n", reg_b);
		out_str(file_s, "	LOD R3,R1+24\n");
		out_str(file_s, "	JMP R3\n");
		out_str(file_s, "	LOD R%u,0\n", reg_b);
		break;
	}

	rdesc_clear(reg_b);
	rdesc_fill(reg_b, a, MODIFIED);
}

void asm_cond(char *op, SYM *a,  char *l)
{
	for(int r=R_GEN; r < R_NUM; r++)
	{
		if(rdesc[r].var==NULL)
		{
			continue;
		}
		if(sym_requires_writeback(rdesc[r].var))
		{
			asm_write_back(r);
			rdesc_clear(r);
		}
		else
		{
			rdesc[r].mod=UNMODIFIED;
		}
	}

	if(a !=NULL)
	{
		int r;

		for(r=R_GEN; r < R_NUM; r++) /* Is it in reg? */
		{
			if(rdesc[r].var==a) break;
		}

		if(r < R_NUM) out_str(file_s, "	TST R%u\n", r);
		else out_str(file_s, "	TST R%u\n", reg_alloc(a)); /* Load into new register */
	}

	out_str(file_s, "	%s %s\n", op, l); 
} 

void asm_call(SYM *a, SYM *b)
{
	int r;
	for(int r=R_GEN; r < R_NUM; r++) asm_write_back(r);
	for(int r=R_GEN; r < R_NUM; r++) rdesc_clear(r);
	out_str(file_s, "	STO (R2+%d),R2\n", tof+oon);	/* store old bp */
	oon += 4;
	out_str(file_s, "	LOD R4,R1+32\n"); 				/* return addr: 4*8=32 */
	out_str(file_s, "	STO (R2+%d),R4\n", tof+oon);	/* store return addr */
	oon += 4;
	out_str(file_s, "	LOD R2,R2+%d\n", tof+oon-8);	/* load new bp */
	out_str(file_s, "	JMP %s\n", (char *)b);			/* jump to new func */
	if(a != NULL)
	{
		r = reg_alloc(a);
		out_str(file_s, "	LOD R%u,R%u\n", r, R_TP);	
		rdesc[r].mod = MODIFIED;
	}
	oon=0;
}

void asm_return(SYM *a)
{
	for(int r=R_GEN; r < R_NUM; r++) asm_write_back(r);
	for(int r=R_GEN; r < R_NUM; r++) rdesc_clear(r);

	if(a!=NULL)	 /* return value */
	{
		asm_load(R_TP, a);
	}

	out_str(file_s, "	LOD R3,(R2+4)\n");	/* return address */
	out_str(file_s, "	LOD R2,(R2)\n");	/* restore bp */
	out_str(file_s, "	JMP R3\n");			/* return */
}   

void asm_head()
{
	char head[]=
	"	# head\n"
	"	LOD R2,STACK\n"
	"	STO (R2),0\n"
	"	LOD R4,EXIT\n"
	"	STO (R2+4),R4\n";

	out_str(file_s, "%s", head);
}

void asm_tail()
{
	char tail[]=
	"\n	# tail\n"
	"EXIT:\n"
	"	END\n";

	out_str(file_s, "%s", tail);
}

void asm_str(SYM *s)
{
	char *t=s->name; /* The text */
	int i;

	out_str(file_s, "L%u:\n", s->label); /* Label for the string */
	out_str(file_s, "	DBS "); /* Label for the string */

	for(i=1; t[i + 1] !=0; i++)
	{
		if(t[i]=='\\')
		{
			switch(t[++i])
			{
				case 'n':
				out_str(file_s, "%u,", '\n');
				break;

				case '\"':
				out_str(file_s, "%u,", '\"');
				break;
			}
		}
		else out_str(file_s, "%u,", t[i]);
	}

	out_str(file_s, "0\n"); /* End of string */
}

void asm_static(void)
{
	int i;

	SYM *sl;

	for(sl=sym_tab_global; sl !=NULL; sl=sl->next)
	{
		if(sl->type==SYM_TEXT) asm_str(sl);
	}

	out_str(file_s, "STATIC:\n");
	out_str(file_s, "	DBN 0,%u\n", tos);				
	out_str(file_s, "STACK:\n");
}

void asm_code(TAC *c)
{
	int r;

	switch(c->op)
	{
		case TAC_UNDEF:
		error("cannot translate TAC_UNDEF");
		return;

		case TAC_ADD:
			asm_bin(TAC_ADD, c->a, c->b, c->c);
		return;

		case TAC_SUB:
			asm_bin(TAC_SUB, c->a, c->b, c->c);
		return;

		case TAC_MUL:
			asm_bin(TAC_MUL, c->a, c->b, c->c);
		return;

		case TAC_DIV:
			asm_bin(TAC_DIV, c->a, c->b, c->c);
		return;

		case TAC_NEG:
		{
			SYM *zero_sym = mk_const(0);
			int reg_zero = reg_alloc(zero_sym);
			int reg_val = reg_alloc(c->b);
			if(reg_zero == reg_val)
			{
				int alt=-1;
				for(int r=R_GEN; r < R_NUM; r++)
				{
					if(r==reg_zero) continue;
					if(rdesc[r].var==NULL)
					{
						alt=r;
						break;
					}
				}
				if(alt==-1)
				{
					for(int r=R_GEN; r < R_NUM; r++)
					{
						if(r==reg_zero) continue;
						if(!sym_requires_writeback(rdesc[r].var) || !rdesc[r].mod)
						{
							alt=r;
							break;
						}
					}
				}
				if(alt==-1)
				{
					alt = (reg_zero==R_GEN) ? R_GEN+1 : R_GEN;
					asm_write_back(alt);
				}
				asm_load(alt, zero_sym);
				rdesc_fill(alt, zero_sym, UNMODIFIED);
				reg_zero=alt;
			}
			if(rdesc[reg_val].var!=c->b)
			{
				asm_load(reg_val, c->b);
				rdesc_fill(reg_val, c->b, UNMODIFIED);
			}
			out_str(file_s, "	SUB R%u,R%u\n", reg_zero, reg_val);
			rdesc_fill(reg_zero, c->a, MODIFIED);
			if(sym_requires_writeback(rdesc[reg_val].var))
			{
				rdesc[reg_val].mod=UNMODIFIED;
			}
			return;
		}

		case TAC_EQ:
		case TAC_NE:
		case TAC_LT:
		case TAC_LE:
		case TAC_GT:
		case TAC_GE:
		asm_cmp(c->op, c->a, c->b, c->c);
		return;

		case TAC_COPY:
		r = reg_alloc(c->b);
		rdesc_fill(r, c->a, MODIFIED);
		return;

		case TAC_INPUT:
		r=reg_alloc(c->a);
		if(c->a->data_type == TYPE_CHAR)
			out_str(file_s, "\tITC\n");
		else
			out_str(file_s, "\tITI\n");
		out_str(file_s, "	LOD R%u,R15\n", r);
		rdesc[r].mod = MODIFIED;
		return;

		case TAC_OUTPUT:
		if(c->a->type == SYM_VAR)
		{
			r=reg_alloc(c->a);
			out_str(file_s, "	LOD R15,R%u\n", r);
			if(c->a->data_type == TYPE_CHAR)
				out_str(file_s, "\tOTC\n");
			else
				out_str(file_s, "\tOTI\n");
		} else if(c->a->type == SYM_TEXT)
		{
			r=reg_alloc(c->a);
			out_str(file_s, "	LOD R15,R%u\n", r);
			out_str(file_s, "\tOTS\n");
		} else if(c->a->type == SYM_INT)
		{
			r=reg_alloc(c->a);
			out_str(file_s, "\tLOD R15,R%u\n", r);
			if(c->a->data_type == TYPE_CHAR)
				out_str(file_s, "\tOTC\n");
			else
				out_str(file_s, "\tOTI\n");
		}
		return;

		case TAC_GOTO:
		{
			SYM *target=resolve_jump_target(c->a);
			if(target==NULL) target=c->a;
			if(!target_is_next_label(c, target))
			{
				asm_cond("JMP", NULL, target->name);
			}
			return;
		}

		case TAC_IFZ:
		{
			SYM *target=resolve_jump_target(c->a);
			if(target==NULL) target=c->a;
			if(target!=NULL && target_is_next_label(c, target))
			{
				return;
			}
			asm_cond("JEZ", c->b, target->name);
			return;
		}

		case TAC_LABEL:
		for(int r=R_GEN; r < R_NUM; r++) asm_write_back(r);
		for(int r=R_GEN; r < R_NUM; r++) rdesc_clear(r);
		out_str(file_s, "%s:\n", c->a->name);
		return;

		case TAC_ACTUAL:
		r=reg_alloc(c->a);
		out_str(file_s, "	STO (R2+%d),R%u\n", tof+oon, r);
		oon += 4;
		return;

		case TAC_CALL:
		asm_call(c->a, c->b);
		return;

		case TAC_BEGINFUNC:
		/* We reset the top of stack, since it is currently empty apart from the link information. */
		scope=1;
		tof=LOCAL_OFF;
		oof=FORMAL_OFF;
		oon=0;
		return;

		case TAC_FORMAL:
		c->a->scope=1; /* parameter is special local var */
		c->a->offset=oof;
		oof -=4;
		return;

		case TAC_VAR:
		{
			int size=sym_size_bytes(c->a);
			if(scope)
			{
				c->a->scope=1; /* local var */
				c->a->offset=tof;
				tof +=size;
			}
			else
			{
				c->a->scope=0; /* global var */
				c->a->offset=tos;
				tos +=size;
			}
		}
		return;

		case TAC_RETURN:
		asm_return(c->a);
		return;

		case TAC_ENDFUNC:
		asm_return(NULL);
		scope=0;
		return;

		case TAC_ADDR:
		{
			for(int r=R_GEN; r < R_NUM; r++) asm_write_back(r);
			for(int r=R_GEN; r < R_NUM; r++) rdesc_clear(r);
			int rd=R_GEN;
			rdesc_fill(rd, c->a, MODIFIED);
			int offset=c->b->offset;
			if(c->b->scope==1)
			{
				out_str(file_s, "\tLOD R%u,R%u\n", rd, R_BP);
			}
			else
			{
				out_str(file_s, "\tLOD R%u,STATIC\n", rd);
			}
			if(offset!=0)
			{
				int rc=(rd==R_GEN)? R_GEN+1 : R_GEN;
				if(rc>=R_NUM) rc=R_GEN+1; /* fallback within general regs */
				out_str(file_s, "\tLOD R%u,%d\n", rc, abs(offset));
				if(offset>=0)
				{
					out_str(file_s, "\tADD R%u,R%u\n", rd, rc);
				}
				else
				{
					out_str(file_s, "\tSUB R%u,R%u\n", rd, rc);
				}
			}
			return;
		}

		case TAC_LOAD:
		{
			int rp=reg_alloc(c->b);
			out_str(file_s, "\tLOD R%u,(R%u+0)\n", rp, rp);
			rdesc_fill(rp, c->a, MODIFIED);
			return;
		}

		case TAC_STORE:
		{
			int rp=reg_alloc(c->a);
			int saved_mod=rdesc[rp].mod;
			rdesc[rp].mod=MODIFIED;
			int rv=reg_alloc(c->b);
			rdesc[rp].mod=saved_mod;
			out_str(file_s, "\tSTO (R%u+0),R%u\n", rp, rv);
			for(int r=R_GEN; r < R_NUM; r++)
			{
				if(rdesc[r].var==NULL)
				{
					continue;
				}
				if(sym_requires_writeback(rdesc[r].var))
				{
					asm_write_back(r);
					rdesc_clear(r);
				}
				else
				{
					rdesc[r].mod=UNMODIFIED;
				}
			}
			return;
		}

		default:
		/* Don't know what this one is */
		error("unknown TAC opcode to translate");
		return;
	}
}

void tac_obj()
{
	tof=LOCAL_OFF; /* TOS allows space for link info */
	oof=FORMAL_OFF;
	oon=0;

	for(int r=0; r < R_NUM; r++) rdesc[r].var=NULL;
	
	asm_head();

	TAC * cur;
	for(cur=tac_first; cur!=NULL; cur=cur->next)
	{
		out_str(file_s, "\n	# ");
		out_tac(file_s, cur);
		out_str(file_s, "\n");
		asm_code(cur);
	}
	asm_tail();
	asm_static();
} 


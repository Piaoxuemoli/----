	# head
	LOD R2,STACK
	STO (R2),0
	LOD R4,EXIT
	STO (R2+4),R4

	# label main
main:

	# begin

	# var i

	# var j

	# var k

	# k = 0
	LOD R5,0

	# label L1
	STO (R2+16),R5
L1:

	# var t0

	# t0 = (k < 10)
	LOD R5,(R2+16)
	SUB R5,10
	TST R5
	LOD R3,R1+40
	JLZ R3
	LOD R5,0
	LOD R3,R1+24
	JMP R3
	LOD R5,1

	# ifz t0 goto L2
	STO (R2+20),R5
	LOD R5,(R2+20)
	TST R5
	JEZ L2

	# i = 0
	LOD R6,0

	# label L3
	STO (R2+8),R6
L3:

	# var t1

	# t1 = (i < 10)
	LOD R5,(R2+8)
	SUB R5,10
	TST R5
	LOD R3,R1+40
	JLZ R3
	LOD R5,0
	LOD R3,R1+24
	JMP R3
	LOD R5,1

	# ifz t1 goto L4
	STO (R2+24),R5
	LOD R5,(R2+24)
	TST R5
	JEZ L4

	# var t2

	# t2 = 2 * i
	LOD R6,(R2+8)
	MUL R6,2

	# j = t2 + 9
	STO (R2+28),R6
	ADD R6,9

	# output j
	STO (R2+12),R6
	LOD R15,R6
	OTI

	# output L5
	LOD R7,L5
	LOD R15,R7
	OTS

	# i = i + 1
	LOD R8,(R2+8)
	ADD R8,1

	# goto L3
	STO (R2+8),R8
	JMP L3

	# label L4
L4:

	# k = k + 1
	LOD R5,(R2+16)
	ADD R5,1

	# goto L1
	STO (R2+16),R5
	JMP L1

	# label L2
L2:

	# end
	LOD R3,(R2+4)
	LOD R2,(R2)
	JMP R3

	# tail
EXIT:
	END
L5:
	DBS 10,0
STATIC:
	DBN 0,0
STACK:

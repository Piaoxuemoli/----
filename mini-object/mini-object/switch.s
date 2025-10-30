	# head
	LOD R2,STACK
	STO (R2),0
	LOD R4,EXIT
	STO (R2+4),R4

	# label main
main:

	# begin

	# var value

	# var result

	# value = 2
	LOD R5,2

	# result = 0
	LOD R6,0

	# var t2

	# t2 = value
	STO (R2+8),R5

	# var t3

	# t3 = t2 - 1
	STO (R2+16),R5
	LOD R7,1
	SUB R5,R7

	# ifz t3 goto L2
	STO (R2+20),R5
	STO (R2+12),R6
	TST R5
	JEZ L2

	# var t4

	# t4 = t2 - 2
	LOD R8,(R2+16)
	LOD R9,2
	SUB R8,R9

	# ifz t4 goto L3
	STO (R2+24),R8
	TST R8
	JEZ L3

	# var t5

	# t5 = t2 - 3
	LOD R10,(R2+16)
	LOD R11,3
	SUB R10,R11

	# ifz t5 goto L4
	STO (R2+28),R10
	TST R10
	JEZ L4

	# goto L5
	JMP L5

	# label L2
L2:

	# result = 1
	LOD R5,1

	# goto L1
	STO (R2+12),R5
	JMP L1

	# label L3
L3:

	# result = 2
	LOD R5,2

	# label L4
	STO (R2+12),R5
L4:

	# var t0

	# t0 = result + 3
	LOD R5,(R2+12)
	LOD R6,3
	ADD R5,R6

	# result = t0
	STO (R2+32),R5

	# goto L1
	STO (R2+12),R5
	JMP L1

	# label L5
L5:

	# var t1

	# t1 = - 1
	LOD R5,0
	LOD R6,1
	SUB R5,R6

	# result = t1
	STO (R2+36),R5

	# goto L1
	STO (R2+12),R5
	JMP L1

	# label L1
L1:

	# output result
	LOD R5,(R2+12)
	LOD R15,R5
	OTI

	# output L6
	LOD R6,L6
	LOD R15,R6
	OTS

	# end
	LOD R3,(R2+4)
	LOD R2,(R2)
	JMP R3

	# tail
EXIT:
	END
L6:
	DBS 10,0
STATIC:
	DBN 0,0
STACK:

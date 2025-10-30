	# head
	LOD R2,STACK
	STO (R2),0
	LOD R4,EXIT
	STO (R2+4),R4

	# label main
main:

	# begin

	# var i

	# var sum

	# sum = 0
	LOD R5,0

	# i = 0
	LOD R6,0

	# label L1
	STO (R2+12),R5
	STO (R2+8),R6
L1:

	# var t0

	# t0 = (i < 10)
	LOD R5,(R2+8)
	LOD R6,10
	SUB R5,R6
	TST R5
	LOD R3,R1+40
	JLZ R3
	LOD R5,0
	LOD R3,R1+24
	JMP R3
	LOD R5,1

	# ifz t0 goto L3
	STO (R2+16),R5
	TST R5
	JEZ L3

	# var t2

	# t2 = (i == 7)
	LOD R7,(R2+8)
	LOD R8,7
	SUB R7,R8
	TST R7
	LOD R3,R1+40
	JEZ R3
	LOD R7,0
	LOD R3,R1+24
	JMP R3
	LOD R7,1

	# ifz t2 goto L4
	STO (R2+20),R7
	TST R7
	JEZ L4

	# goto L3
	JMP L3

	# label L4
L4:

	# var t3

	# t3 = (i < 3)
	LOD R5,(R2+8)
	LOD R6,3
	SUB R5,R6
	TST R5
	LOD R3,R1+40
	JLZ R3
	LOD R5,0
	LOD R3,R1+24
	JMP R3
	LOD R5,1

	# ifz t3 goto L5
	STO (R2+24),R5
	TST R5
	JEZ L5

	# goto L2
	JMP L2

	# label L5
L5:

	# var t4

	# t4 = sum + i
	LOD R5,(R2+12)
	LOD R6,(R2+8)
	ADD R5,R6

	# sum = t4
	STO (R2+28),R5

	# label L2
	STO (R2+12),R5
L2:

	# var t1

	# t1 = i + 1
	LOD R5,(R2+8)
	LOD R6,1
	ADD R5,R6

	# i = t1
	STO (R2+32),R5

	# goto L1
	STO (R2+8),R5
	JMP L1

	# label L3
L3:

	# output sum
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

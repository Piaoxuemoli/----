	# head
	LOD R2,STACK
	STO (R2),0
	LOD R4,EXIT
	STO (R2+4),R4

	# label main
main:

	# begin

	# var a

	# var b

	# var c

	# var d

	# var e

	# var i

	# var j

	# var k

	# input a
	LOD R5,(R2+8)
	ITI
	LOD R5,R15

	# input b
	LOD R6,(R2+12)
	ITI
	LOD R6,R15

	# input c
	LOD R7,(R2+16)
	ITI
	LOD R7,R15

	# j = 5
	LOD R8,5

	# label L1
	STO (R2+8),R5
	STO (R2+12),R6
	STO (R2+16),R7
	STO (R2+32),R8
L1:

	# var t0

	# t0 = (j > 0)
	LOD R5,(R2+32)
	LOD R6,0
	SUB R5,R6
	TST R5
	LOD R3,R1+40
	JGZ R3
	LOD R5,0
	LOD R3,R1+24
	JMP R3
	LOD R5,1

	# ifz t0 goto L2
	STO (R2+40),R5
	TST R5
	JEZ L2

	# output j
	LOD R7,(R2+32)
	LOD R15,R7
	OTI

	# i = 9
	LOD R8,9

	# label L3
	STO (R2+28),R8
L3:

	# var t1

	# t1 = (i > 0)
	LOD R5,(R2+28)
	LOD R6,0
	SUB R5,R6
	TST R5
	LOD R3,R1+40
	JGZ R3
	LOD R5,0
	LOD R3,R1+24
	JMP R3
	LOD R5,1

	# ifz t1 goto L4
	STO (R2+44),R5
	TST R5
	JEZ L4

	# output i
	LOD R7,(R2+28)
	LOD R15,R7
	OTI

	# var t2

	# t2 = b * c
	LOD R8,(R2+12)
	LOD R9,(R2+16)
	MUL R8,R9

	# var t3

	# t3 = a + t2
	LOD R10,(R2+8)
	STO (R2+48),R8
	ADD R10,R8

	# var t4

	# t4 = a + c
	LOD R11,(R2+8)
	ADD R11,R9

	# var t5

	# t5 = t4 / b
	STO (R2+56),R11
	LOD R12,(R2+12)
	DIV R11,R12

	# var t6

	# t6 = t3 - t5
	STO (R2+52),R10
	STO (R2+60),R11
	SUB R10,R11

	# var t7

	# t7 = t6 + 9
	STO (R2+64),R10
	LOD R13,9
	ADD R10,R13

	# d = t7
	STO (R2+68),R10

	# var t8

	# t8 = c - a
	LOD R14,(R2+8)
	SUB R9,R14

	# var t9

	# t9 = t8 / b
	STO (R2+72),R9
	DIV R9,R12

	# var t10

	# t10 = t3 - t9
	LOD R15,(R2+52)
	STO (R2+76),R9
	SUB R15,R9

	# var t11

	# t11 = t10 + 9
	STO (R2+80),R15
	ADD R15,R13

	# e = t11
	STO (R2+84),R15

	# var t12

	# t12 = i - 1
	LOD R5,1
	SUB R7,R5

	# i = t12
	STO (R2+88),R7

	# goto L3
	STO (R2+28),R7
	STO (R2+20),R10
	STO (R2+24),R15
	JMP L3

	# label L4
L4:

	# var t13

	# t13 = j - 1
	LOD R5,(R2+32)
	LOD R6,1
	SUB R5,R6

	# j = t13
	STO (R2+92),R5

	# output L5
	LOD R7,L5
	LOD R15,R7
	OTS

	# goto L1
	STO (R2+32),R5
	JMP L1

	# label L2
L2:

	# output L6
	LOD R5,L6
	LOD R15,R5
	OTS

	# output d
	LOD R6,(R2+20)
	LOD R15,R6
	OTI

	# output L5
	LOD R7,L5
	LOD R15,R7
	OTS

	# output e
	LOD R8,(R2+24)
	LOD R15,R8
	OTI

	# output L6
	LOD R15,R5
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
L5:
	DBS 32,0
STATIC:
	DBN 0,0
STACK:

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

	# var sumd

	# var sume

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

	# sumd = 0
	LOD R8,0

	# sume = 0
	LOD R9,0

	# k = 12
	LOD R10,12

	# var t3

	# t3 = b * c
	STO (R2+12),R6
	STO (R2+16),R7
	MUL R6,R7

	# var t4

	# t4 = a + t3
	STO (R2+8),R5
	STO (R2+48),R6
	ADD R5,R6

	# var t5

	# t5 = a + c
	LOD R11,(R2+8)
	ADD R11,R7

	# var t6

	# t6 = t5 / b
	STO (R2+56),R11
	LOD R12,(R2+12)
	DIV R11,R12

	# var t7

	# t7 = t4 - t6
	STO (R2+52),R5
	STO (R2+60),R11
	SUB R5,R11

	# d = t7 + 9
	STO (R2+64),R5
	ADD R5,9

	# var t9

	# t9 = c - a
	LOD R13,(R2+8)
	SUB R7,R13

	# var t10

	# t10 = t9 / b
	STO (R2+68),R7
	DIV R7,R12

	# var t11

	# t11 = t4 - t10
	LOD R14,(R2+52)
	STO (R2+72),R7
	SUB R14,R7

	# e = t11 + 13
	STO (R2+76),R14
	ADD R14,13

	# label L1
	STO (R2+20),R5
	STO (R2+28),R8
	STO (R2+32),R9
	STO (R2+44),R10
	STO (R2+24),R14
L1:

	# var t0

	# t0 = (k > 0)
	LOD R5,(R2+44)
	SUB R5,0
	TST R5
	LOD R3,R1+40
	JGZ R3
	LOD R5,0
	LOD R3,R1+24
	JMP R3
	LOD R5,1

	# ifz t0 goto L2
	STO (R2+80),R5
	LOD R5,(R2+80)
	TST R5
	JEZ L2

	# j = 15
	LOD R6,15

	# label L3
	STO (R2+40),R6
L3:

	# var t1

	# t1 = (j > 0)
	LOD R5,(R2+40)
	SUB R5,0
	TST R5
	LOD R3,R1+40
	JGZ R3
	LOD R5,0
	LOD R3,R1+24
	JMP R3
	LOD R5,1

	# ifz t1 goto L4
	STO (R2+84),R5
	LOD R5,(R2+84)
	TST R5
	JEZ L4

	# i = 18
	LOD R6,18

	# label L5
	STO (R2+36),R6
L5:

	# var t2

	# t2 = (i > 0)
	LOD R5,(R2+36)
	SUB R5,0
	TST R5
	LOD R3,R1+40
	JGZ R3
	LOD R5,0
	LOD R3,R1+24
	JMP R3
	LOD R5,1

	# ifz t2 goto L6
	STO (R2+88),R5
	LOD R5,(R2+88)
	TST R5
	JEZ L6

	# sumd = sumd + d
	LOD R6,(R2+28)
	LOD R7,(R2+20)
	ADD R6,R7

	# var t14

	# t14 = sume + e
	LOD R8,(R2+32)
	LOD R9,(R2+24)
	ADD R8,R9

	# sume = t14 + d
	STO (R2+92),R8
	ADD R8,R7

	# i = i - 1
	LOD R10,(R2+36)
	SUB R10,1

	# goto L5
	STO (R2+28),R6
	STO (R2+32),R8
	STO (R2+36),R10
	JMP L5

	# label L6
L6:

	# j = j - 1
	LOD R5,(R2+40)
	SUB R5,1

	# goto L3
	STO (R2+40),R5
	JMP L3

	# label L4
L4:

	# k = k - 1
	LOD R5,(R2+44)
	SUB R5,1

	# goto L1
	STO (R2+44),R5
	JMP L1

	# label L2
L2:

	# output sumd
	LOD R5,(R2+28)
	LOD R15,R5
	OTI

	# output L7
	LOD R6,L7
	LOD R15,R6
	OTS

	# output sume
	LOD R7,(R2+32)
	LOD R15,R7
	OTI

	# output L8
	LOD R8,L8
	LOD R15,R8
	OTS

	# end
	LOD R3,(R2+4)
	LOD R2,(R2)
	JMP R3

	# tail
EXIT:
	END
L8:
	DBS 10,0
L7:
	DBS 32,0
STATIC:
	DBN 0,0
STACK:

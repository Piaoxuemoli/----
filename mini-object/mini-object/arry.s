	# head
	LOD R2,STACK
	STO (R2),0
	LOD R4,EXIT
	STO (R2+4),R4

	# label main
main:

	# begin

	# var nums

	# var letters

	# var i

	# var total

	# total = 0
	LOD R5,0

	# i = 0
	LOD R6,0

	# label L1
	STO (R2+40),R5
	STO (R2+36),R6
L1:

	# var t0

	# t0 = (i < 4)
	LOD R5,(R2+36)
	LOD R6,4
	SUB R5,R6
	TST R5
	LOD R3,R1+40
	JLZ R3
	LOD R5,0
	LOD R3,R1+24
	JMP R3
	LOD R5,1

	# ifz t0 goto L2
	STO (R2+44),R5
	TST R5
	JEZ L2

	# var t1

	# t1 = i * 4
	LOD R7,(R2+36)
	MUL R7,R6

	# var t2

	# t2 = &nums
	STO (R2+48),R7
	LOD R5,R2
	LOD R6,8
	ADD R5,R6

	# var t3

	# t3 = t2 + t1
	STO (R2+52),R5
	LOD R6,(R2+48)
	ADD R5,R6

	# var t4

	# t4 = i * 2
	LOD R7,(R2+36)
	LOD R8,2
	MUL R7,R8

	# *t3 = t4
	STO (R2+56),R5
	STO (R2+60),R7
	STO (R5+0),R7

	# var t5

	# t5 = i * 4
	LOD R9,(R2+36)
	LOD R10,4
	MUL R9,R10

	# var t6

	# t6 = &nums
	STO (R2+64),R9
	LOD R5,R2
	LOD R6,8
	ADD R5,R6

	# var t7

	# t7 = t6 + t5
	STO (R2+68),R5
	LOD R6,(R2+64)
	ADD R5,R6

	# var t8

	# t8 = *t7
	STO (R2+72),R5
	LOD R5,(R5+0)

	# var t9

	# t9 = total + t8
	LOD R7,(R2+40)
	STO (R2+76),R5
	ADD R7,R5

	# total = t9
	STO (R2+80),R7

	# var t10

	# t10 = i + 1
	LOD R8,(R2+36)
	LOD R9,1
	ADD R8,R9

	# i = t10
	STO (R2+84),R8

	# goto L1
	STO (R2+40),R7
	STO (R2+36),R8
	JMP L1

	# label L2
L2:

	# var t11

	# t11 = 0 * 4
	LOD R5,0
	LOD R6,4
	MUL R5,R6

	# var t12

	# t12 = &letters
	STO (R2+88),R5
	LOD R5,R2
	LOD R6,24
	ADD R5,R6

	# var t13

	# t13 = t12 + t11
	STO (R2+92),R5
	LOD R6,(R2+88)
	ADD R5,R6

	# *t13 = 72
	STO (R2+96),R5
	LOD R7,72
	STO (R5+0),R7

	# var t14

	# t14 = 1 * 4
	LOD R8,1
	LOD R9,4
	MUL R8,R9

	# var t15

	# t15 = &letters
	STO (R2+100),R8
	LOD R5,R2
	LOD R6,24
	ADD R5,R6

	# var t16

	# t16 = t15 + t14
	STO (R2+104),R5
	LOD R6,(R2+100)
	ADD R5,R6

	# *t16 = 105
	STO (R2+108),R5
	LOD R7,105
	STO (R5+0),R7

	# var t17

	# t17 = 2 * 4
	LOD R8,2
	LOD R9,4
	MUL R8,R9

	# var t18

	# t18 = &letters
	STO (R2+112),R8
	LOD R5,R2
	LOD R6,24
	ADD R5,R6

	# var t19

	# t19 = t18 + t17
	STO (R2+116),R5
	LOD R6,(R2+112)
	ADD R5,R6

	# *t19 = 33
	STO (R2+120),R5
	LOD R7,33
	STO (R5+0),R7

	# var t20

	# t20 = 1 * 4
	LOD R8,1
	LOD R9,4
	MUL R8,R9

	# var t21

	# t21 = &letters
	STO (R2+124),R8
	LOD R5,R2
	LOD R6,24
	ADD R5,R6

	# var t22

	# t22 = t21 + t20
	STO (R2+128),R5
	LOD R6,(R2+124)
	ADD R5,R6

	# var t23

	# t23 = 0 * 4
	LOD R7,0
	LOD R8,4
	MUL R7,R8

	# var t24

	# t24 = &letters
	STO (R2+132),R5
	STO (R2+136),R7
	LOD R5,R2
	LOD R6,24
	ADD R5,R6

	# var t25

	# t25 = t24 + t23
	STO (R2+140),R5
	LOD R6,(R2+136)
	ADD R5,R6

	# var t26

	# t26 = *t25
	STO (R2+144),R5
	LOD R5,(R5+0)

	# *t22 = t26
	LOD R7,(R2+132)
	STO (R2+148),R5
	STO (R7+0),R5

	# output total
	LOD R8,(R2+40)
	LOD R15,R8
	OTI

	# output L3
	LOD R9,L3
	LOD R15,R9
	OTS

	# var t27

	# t27 = 3 * 4
	LOD R10,3
	LOD R11,4
	MUL R10,R11

	# var t28

	# t28 = &nums
	STO (R2+152),R10
	LOD R5,R2
	LOD R6,8
	ADD R5,R6

	# var t29

	# t29 = t28 + t27
	STO (R2+156),R5
	LOD R6,(R2+152)
	ADD R5,R6

	# var t30

	# t30 = *t29
	STO (R2+160),R5
	LOD R5,(R5+0)

	# output t30
	STO (R2+164),R5
	LOD R15,R5
	OTI

	# output L3
	LOD R7,L3
	LOD R15,R7
	OTS

	# var t31

	# t31 = 1 * 4
	LOD R8,1
	LOD R9,4
	MUL R8,R9

	# var t32

	# t32 = &letters
	STO (R2+168),R8
	LOD R5,R2
	LOD R6,24
	ADD R5,R6

	# var t33

	# t33 = t32 + t31
	STO (R2+172),R5
	LOD R6,(R2+168)
	ADD R5,R6

	# var t34

	# t34 = *t33
	STO (R2+176),R5
	LOD R5,(R5+0)

	# output t34
	STO (R2+180),R5
	LOD R15,R5
	OTC

	# output L3
	LOD R7,L3
	LOD R15,R7
	OTS

	# end
	LOD R3,(R2+4)
	LOD R2,(R2)
	JMP R3

	# tail
EXIT:
	END
L3:
	DBS 10,0
STATIC:
	DBN 0,0
STACK:

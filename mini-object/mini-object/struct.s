	# head
	LOD R2,STACK
	STO (R2),0
	LOD R4,EXIT
	STO (R2+4),R4

	# label main
main:

	# begin

	# var p

	# var q

	# var total

	# var t0

	# t0 = &p
	LOD R5,R2
	LOD R6,8
	ADD R5,R6

	# var t1

	# t1 = t0 + 0
	STO (R2+28),R5
	LOD R6,0
	ADD R5,R6

	# *t1 = 7
	STO (R2+32),R5
	LOD R7,7
	STO (R5+0),R7

	# var t2

	# t2 = &p
	LOD R5,R2
	LOD R6,8
	ADD R5,R6

	# var t3

	# t3 = t2 + 4
	STO (R2+36),R5
	LOD R6,4
	ADD R5,R6

	# *t3 = 88
	STO (R2+40),R5
	LOD R7,88
	STO (R5+0),R7

	# var t4

	# t4 = &q
	LOD R5,R2
	LOD R6,16
	ADD R5,R6

	# var t5

	# t5 = t4 + 0
	STO (R2+44),R5
	LOD R6,0
	ADD R5,R6

	# *t5 = 3
	STO (R2+48),R5
	LOD R7,3
	STO (R5+0),R7

	# var t6

	# t6 = &q
	LOD R5,R2
	LOD R6,16
	ADD R5,R6

	# var t7

	# t7 = t6 + 4
	STO (R2+52),R5
	LOD R6,4
	ADD R5,R6

	# *t7 = 89
	STO (R2+56),R5
	LOD R7,89
	STO (R5+0),R7

	# var t8

	# t8 = &p
	LOD R5,R2
	LOD R6,8
	ADD R5,R6

	# var t9

	# t9 = t8 + 0
	STO (R2+60),R5
	LOD R6,0
	ADD R5,R6

	# var t10

	# t10 = *t9
	STO (R2+64),R5
	LOD R5,(R5+0)

	# var t11

	# t11 = &q
	STO (R2+68),R5
	LOD R5,R2
	LOD R6,16
	ADD R5,R6

	# var t12

	# t12 = t11 + 0
	STO (R2+72),R5
	LOD R6,0
	ADD R5,R6

	# var t13

	# t13 = *t12
	STO (R2+76),R5
	LOD R5,(R5+0)

	# var t14

	# t14 = t10 + t13
	LOD R7,(R2+68)
	STO (R2+80),R5
	ADD R7,R5

	# total = t14
	STO (R2+84),R7

	# var t15

	# t15 = &q
	STO (R2+24),R7
	LOD R5,R2
	LOD R6,16
	ADD R5,R6

	# var t16

	# t16 = t15 + 4
	STO (R2+88),R5
	LOD R6,4
	ADD R5,R6

	# var t17

	# t17 = &p
	STO (R2+92),R5
	LOD R5,R2
	LOD R6,8
	ADD R5,R6

	# var t18

	# t18 = t17 + 4
	STO (R2+96),R5
	LOD R6,4
	ADD R5,R6

	# var t19

	# t19 = *t18
	STO (R2+100),R5
	LOD R5,(R5+0)

	# *t16 = t19
	LOD R7,(R2+92)
	STO (R2+104),R5
	STO (R7+0),R5

	# output total
	LOD R8,(R2+24)
	LOD R15,R8
	OTI

	# output L1
	LOD R9,L1
	LOD R15,R9
	OTS

	# var t20

	# t20 = &q
	LOD R5,R2
	LOD R6,16
	ADD R5,R6

	# var t21

	# t21 = t20 + 4
	STO (R2+108),R5
	LOD R6,4
	ADD R5,R6

	# var t22

	# t22 = *t21
	STO (R2+112),R5
	LOD R5,(R5+0)

	# output t22
	STO (R2+116),R5
	LOD R15,R5
	OTC

	# output L1
	LOD R7,L1
	LOD R15,R7
	OTS

	# end
	LOD R3,(R2+4)
	LOD R2,(R2)
	JMP R3

	# tail
EXIT:
	END
L1:
	DBS 10,0
STATIC:
	DBN 0,0
STACK:

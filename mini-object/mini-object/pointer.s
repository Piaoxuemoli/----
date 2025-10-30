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

	# var p

	# var ch

	# var copy

	# var pc

	# value = 5
	LOD R5,5

	# var t0

	# t0 = &value
	STO (R2+8),R5
	LOD R5,R2
	LOD R6,8
	ADD R5,R6

	# p = t0
	STO (R2+32),R5

	# var t1

	# t1 = *p
	STO (R2+16),R5
	LOD R5,(R5+0)

	# result = t1
	STO (R2+36),R5

	# var t2

	# t2 = result + 1
	STO (R2+12),R5
	LOD R6,1
	ADD R5,R6

	# *p = t2
	LOD R7,(R2+16)
	STO (R2+40),R5
	STO (R7+0),R5

	# ch = 65
	LOD R8,65

	# var t3

	# t3 = &ch
	STO (R2+20),R8
	LOD R5,R2
	LOD R6,20
	ADD R5,R6

	# pc = t3
	STO (R2+44),R5

	# var t4

	# t4 = *pc
	STO (R2+28),R5
	LOD R5,(R5+0)

	# copy = t4
	STO (R2+48),R5

	# output result
	LOD R6,(R2+12)
	LOD R15,R6
	OTI

	# output L1
	LOD R7,L1
	LOD R15,R7
	OTS

	# output value
	LOD R8,(R2+8)
	LOD R15,R8
	OTI

	# output L1
	LOD R15,R7
	OTS

	# output copy
	STO (R2+24),R5
	LOD R15,R5
	OTC

	# output L1
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

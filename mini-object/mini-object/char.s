	# head
	LOD R2,STACK
	STO (R2),0
	LOD R4,EXIT
	STO (R2+4),R4

	# label main
main:

	# begin

	# var ch

	# var next

	# var a

	# var b

	# var c

	# var d

	# d = 100
	LOD R5,100

	# output d
	STO (R2+28),R5
	LOD R15,R5
	OTC

	# c = 99
	LOD R6,99

	# output c
	STO (R2+24),R6
	LOD R15,R6
	OTC

	# b = 98
	LOD R7,98

	# output b
	STO (R2+20),R7
	LOD R15,R7
	OTC

	# a = 97
	LOD R8,97

	# output a
	STO (R2+16),R8
	LOD R15,R8
	OTC

	# output L1
	LOD R9,L1
	LOD R15,R9
	OTS

	# ch = 88
	LOD R10,88

	# var t0

	# t0 = ch + 1
	STO (R2+8),R10
	LOD R11,1
	ADD R10,R11

	# next = t0
	STO (R2+32),R10

	# output ch
	LOD R12,(R2+8)
	LOD R15,R12
	OTC

	# output L1
	LOD R15,R9
	OTS

	# output next
	STO (R2+12),R10
	LOD R15,R10
	OTC

	# output L1
	LOD R15,R9
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

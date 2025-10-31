	# head
	LOD R2,STACK
	STO (R2),0
	LOD R4,EXIT
	STO (R2+4),R4

	# label main
main:

	# begin

	# var rows

	# var numbers

	# var pi

	# var pc

	# var i

	# var sum

	# var t1

	# t1 = 0 * 4
	LOD R5,0
	LOD R6,4
	MUL R5,R6

	# var t0

	# t0 = &numbers
	STO (R2+136),R5
	LOD R5,R2
	LOD R6,104
	ADD R5,R6

	# var t2

	# t2 = t0 + t1
	STO (R2+140),R5
	LOD R6,(R2+136)
	ADD R5,R6

	# *t2 = 1
	STO (R2+144),R5
	LOD R7,1
	STO (R5+0),R7

	# var t4

	# t4 = 1 * 4
	LOD R8,4
	MUL R7,R8

	# var t3

	# t3 = &numbers
	STO (R2+148),R7
	LOD R5,R2
	LOD R6,104
	ADD R5,R6

	# var t5

	# t5 = t3 + t4
	STO (R2+152),R5
	LOD R6,(R2+148)
	ADD R5,R6

	# *t5 = 2
	STO (R2+156),R5
	LOD R7,2
	STO (R5+0),R7

	# var t7

	# t7 = 2 * 4
	LOD R8,4
	MUL R7,R8

	# var t6

	# t6 = &numbers
	STO (R2+160),R7
	LOD R5,R2
	LOD R6,104
	ADD R5,R6

	# var t8

	# t8 = t6 + t7
	STO (R2+164),R5
	LOD R6,(R2+160)
	ADD R5,R6

	# *t8 = 3
	STO (R2+168),R5
	LOD R7,3
	STO (R5+0),R7

	# var t10

	# t10 = 3 * 4
	LOD R8,4
	MUL R7,R8

	# var t9

	# t9 = &numbers
	STO (R2+172),R7
	LOD R5,R2
	LOD R6,104
	ADD R5,R6

	# var t11

	# t11 = t9 + t10
	STO (R2+176),R5
	LOD R6,(R2+172)
	ADD R5,R6

	# *t11 = 4
	STO (R2+180),R5
	LOD R7,4
	STO (R5+0),R7

	# var t16

	# t16 = 0 * 4
	LOD R8,0
	MUL R8,R7

	# var t13

	# t13 = 1 * 32
	LOD R9,1
	LOD R10,32
	MUL R9,R10

	# var t12

	# t12 = &rows
	STO (R2+184),R8
	STO (R2+188),R9
	LOD R5,R2
	LOD R6,8
	ADD R5,R6

	# var t14

	# t14 = t12 + t13
	STO (R2+192),R5
	LOD R6,(R2+188)
	ADD R5,R6

	# var t15

	# t15 = t14 + 0
	STO (R2+196),R5
	LOD R7,0
	ADD R5,R7

	# var t17

	# t17 = t15 + t16
	STO (R2+200),R5
	LOD R8,(R2+184)
	ADD R5,R8

	# *t17 = 104
	STO (R2+204),R5
	LOD R9,104
	STO (R5+0),R9

	# var t22

	# t22 = 1 * 4
	LOD R10,1
	LOD R11,4
	MUL R10,R11

	# var t19

	# t19 = 1 * 32
	LOD R12,1
	LOD R13,32
	MUL R12,R13

	# var t18

	# t18 = &rows
	STO (R2+208),R10
	STO (R2+212),R12
	LOD R5,R2
	LOD R6,8
	ADD R5,R6

	# var t20

	# t20 = t18 + t19
	STO (R2+216),R5
	LOD R6,(R2+212)
	ADD R5,R6

	# var t21

	# t21 = t20 + 0
	STO (R2+220),R5
	LOD R7,0
	ADD R5,R7

	# var t23

	# t23 = t21 + t22
	STO (R2+224),R5
	LOD R8,(R2+208)
	ADD R5,R8

	# *t23 = 105
	STO (R2+228),R5
	LOD R9,105
	STO (R5+0),R9

	# var t28

	# t28 = 2 * 4
	LOD R10,2
	LOD R11,4
	MUL R10,R11

	# var t25

	# t25 = 1 * 32
	LOD R12,1
	LOD R13,32
	MUL R12,R13

	# var t24

	# t24 = &rows
	STO (R2+232),R10
	STO (R2+236),R12
	LOD R5,R2
	LOD R6,8
	ADD R5,R6

	# var t26

	# t26 = t24 + t25
	STO (R2+240),R5
	LOD R6,(R2+236)
	ADD R5,R6

	# var t27

	# t27 = t26 + 0
	STO (R2+244),R5
	LOD R7,0
	ADD R5,R7

	# var t29

	# t29 = t27 + t28
	STO (R2+248),R5
	LOD R8,(R2+232)
	ADD R5,R8

	# *t29 = 0
	STO (R2+252),R5
	LOD R9,0
	STO (R5+0),R9

	# var t31

	# t31 = 1 * 32
	LOD R10,1
	LOD R11,32
	MUL R10,R11

	# var t30

	# t30 = &rows
	STO (R2+256),R10
	LOD R5,R2
	LOD R6,8
	ADD R5,R6

	# var t32

	# t32 = t30 + t31
	STO (R2+260),R5
	LOD R6,(R2+256)
	ADD R5,R6

	# var t33

	# t33 = t32 + 24
	STO (R2+264),R5
	LOD R7,24
	ADD R5,R7

	# var t34

	# t34 = t33 + 0
	STO (R2+268),R5
	LOD R8,0
	ADD R5,R8

	# *t34 = 10
	STO (R2+272),R5
	LOD R9,10
	STO (R5+0),R9

	# var t36

	# t36 = 1 * 32
	LOD R10,1
	LOD R11,32
	MUL R10,R11

	# var t35

	# t35 = &rows
	STO (R2+276),R10
	LOD R5,R2
	LOD R6,8
	ADD R5,R6

	# var t37

	# t37 = t35 + t36
	STO (R2+280),R5
	LOD R6,(R2+276)
	ADD R5,R6

	# var t38

	# t38 = t37 + 24
	STO (R2+284),R5
	LOD R7,24
	ADD R5,R7

	# var t39

	# t39 = t38 + 4
	STO (R2+288),R5
	LOD R8,4
	ADD R5,R8

	# *t39 = 88
	STO (R2+292),R5
	LOD R9,88
	STO (R5+0),R9

	# var t44

	# t44 = 0 * 4
	LOD R10,0
	MUL R10,R8

	# var t41

	# t41 = 2 * 32
	LOD R11,2
	LOD R12,32
	MUL R11,R12

	# var t40

	# t40 = &rows
	STO (R2+296),R10
	STO (R2+300),R11
	LOD R5,R2
	LOD R6,8
	ADD R5,R6

	# var t42

	# t42 = t40 + t41
	STO (R2+304),R5
	LOD R6,(R2+300)
	ADD R5,R6

	# var t43

	# t43 = t42 + 0
	STO (R2+308),R5
	LOD R7,0
	ADD R5,R7

	# var t45

	# t45 = t43 + t44
	STO (R2+312),R5
	LOD R8,(R2+296)
	ADD R5,R8

	# *t45 = 98
	STO (R2+316),R5
	LOD R9,98
	STO (R5+0),R9

	# var t50

	# t50 = 1 * 4
	LOD R10,1
	LOD R11,4
	MUL R10,R11

	# var t47

	# t47 = 2 * 32
	LOD R12,2
	LOD R13,32
	MUL R12,R13

	# var t46

	# t46 = &rows
	STO (R2+320),R10
	STO (R2+324),R12
	LOD R5,R2
	LOD R6,8
	ADD R5,R6

	# var t48

	# t48 = t46 + t47
	STO (R2+328),R5
	LOD R6,(R2+324)
	ADD R5,R6

	# var t49

	# t49 = t48 + 0
	STO (R2+332),R5
	LOD R7,0
	ADD R5,R7

	# var t51

	# t51 = t49 + t50
	STO (R2+336),R5
	LOD R8,(R2+320)
	ADD R5,R8

	# *t51 = 121
	STO (R2+340),R5
	LOD R9,121
	STO (R5+0),R9

	# var t56

	# t56 = 2 * 4
	LOD R10,2
	LOD R11,4
	MUL R10,R11

	# var t53

	# t53 = 2 * 32
	LOD R12,2
	LOD R13,32
	MUL R12,R13

	# var t52

	# t52 = &rows
	STO (R2+344),R10
	STO (R2+348),R12
	LOD R5,R2
	LOD R6,8
	ADD R5,R6

	# var t54

	# t54 = t52 + t53
	STO (R2+352),R5
	LOD R6,(R2+348)
	ADD R5,R6

	# var t55

	# t55 = t54 + 0
	STO (R2+356),R5
	LOD R7,0
	ADD R5,R7

	# var t57

	# t57 = t55 + t56
	STO (R2+360),R5
	LOD R8,(R2+344)
	ADD R5,R8

	# *t57 = 101
	STO (R2+364),R5
	LOD R9,101
	STO (R5+0),R9

	# var t62

	# t62 = 3 * 4
	LOD R10,3
	LOD R11,4
	MUL R10,R11

	# var t59

	# t59 = 2 * 32
	LOD R12,2
	LOD R13,32
	MUL R12,R13

	# var t58

	# t58 = &rows
	STO (R2+368),R10
	STO (R2+372),R12
	LOD R5,R2
	LOD R6,8
	ADD R5,R6

	# var t60

	# t60 = t58 + t59
	STO (R2+376),R5
	LOD R6,(R2+372)
	ADD R5,R6

	# var t61

	# t61 = t60 + 0
	STO (R2+380),R5
	LOD R7,0
	ADD R5,R7

	# var t63

	# t63 = t61 + t62
	STO (R2+384),R5
	LOD R8,(R2+368)
	ADD R5,R8

	# *t63 = 0
	STO (R2+388),R5
	LOD R9,0
	STO (R5+0),R9

	# var t65

	# t65 = 2 * 32
	LOD R10,2
	LOD R11,32
	MUL R10,R11

	# var t64

	# t64 = &rows
	STO (R2+392),R10
	LOD R5,R2
	LOD R6,8
	ADD R5,R6

	# var t66

	# t66 = t64 + t65
	STO (R2+396),R5
	LOD R6,(R2+392)
	ADD R5,R6

	# var t67

	# t67 = t66 + 24
	STO (R2+400),R5
	LOD R7,24
	ADD R5,R7

	# var t68

	# t68 = t67 + 0
	STO (R2+404),R5
	LOD R8,0
	ADD R5,R8

	# *t68 = 20
	STO (R2+408),R5
	LOD R9,20
	STO (R5+0),R9

	# var t70

	# t70 = 2 * 32
	LOD R10,2
	LOD R11,32
	MUL R10,R11

	# var t69

	# t69 = &rows
	STO (R2+412),R10
	LOD R5,R2
	LOD R6,8
	ADD R5,R6

	# var t71

	# t71 = t69 + t70
	STO (R2+416),R5
	LOD R6,(R2+412)
	ADD R5,R6

	# var t72

	# t72 = t71 + 24
	STO (R2+420),R5
	LOD R7,24
	ADD R5,R7

	# var t73

	# t73 = t72 + 4
	STO (R2+424),R5
	LOD R8,4
	ADD R5,R8

	# *t73 = 89
	STO (R2+428),R5
	LOD R9,89
	STO (R5+0),R9

	# var t75

	# t75 = 0 * 4
	LOD R10,0
	MUL R10,R8

	# var t74

	# t74 = &numbers
	STO (R2+432),R10
	LOD R5,R2
	LOD R6,104
	ADD R5,R6

	# var t76

	# t76 = t74 + t75
	STO (R2+436),R5
	LOD R6,(R2+432)
	ADD R5,R6

	# pi = t76
	STO (R2+440),R5

	# sum = 0
	LOD R7,0

	# i = 0
	LOD R8,0

	# label L1
	STO (R2+120),R5
	STO (R2+132),R7
	STO (R2+128),R8
L1:

	# var t77

	# t77 = (i < 4)
	LOD R5,(R2+128)
	LOD R6,4
	SUB R5,R6
	TST R5
	LOD R3,R1+40
	JLZ R3
	LOD R5,0
	LOD R3,R1+24
	JMP R3
	LOD R5,1

	# ifz t77 goto L2
	STO (R2+444),R5
	TST R5
	JEZ L2

	# var t78

	# t78 = *pi
	LOD R7,(R2+120)
	LOD R7,(R7+0)

	# var t79

	# t79 = sum + t78
	LOD R8,(R2+132)
	STO (R2+448),R7
	ADD R8,R7

	# sum = t79
	STO (R2+452),R8

	# var t80

	# t80 = pi + 1
	LOD R9,(R2+120)
	LOD R10,1
	ADD R9,R10

	# pi = t80
	STO (R2+456),R9

	# var t81

	# t81 = i + 1
	LOD R11,(R2+128)
	ADD R11,R10

	# i = t81
	STO (R2+460),R11

	# goto L1
	STO (R2+132),R8
	STO (R2+120),R9
	STO (R2+128),R11
	JMP L1

	# label L2
L2:

	# var t86

	# t86 = 0 * 4
	LOD R5,0
	LOD R6,4
	MUL R5,R6

	# var t83

	# t83 = 2 * 32
	LOD R7,2
	LOD R8,32
	MUL R7,R8

	# var t82

	# t82 = &rows
	STO (R2+464),R5
	STO (R2+468),R7
	LOD R5,R2
	LOD R6,8
	ADD R5,R6

	# var t84

	# t84 = t82 + t83
	STO (R2+472),R5
	LOD R6,(R2+468)
	ADD R5,R6

	# var t85

	# t85 = t84 + 0
	STO (R2+476),R5
	LOD R7,0
	ADD R5,R7

	# var t87

	# t87 = t85 + t86
	STO (R2+480),R5
	LOD R8,(R2+464)
	ADD R5,R8

	# pc = t87
	STO (R2+484),R5

	# *pc = 66
	STO (R2+124),R5
	LOD R9,66
	STO (R5+0),R9

	# var t88

	# t88 = pc + 1
	LOD R10,1
	ADD R5,R10

	# pc = t88
	STO (R2+488),R5

	# *pc = 89
	STO (R2+124),R5
	LOD R11,89
	STO (R5+0),R11

	# var t89

	# t89 = pc + 1
	ADD R5,R10

	# pc = t89
	STO (R2+492),R5

	# *pc = 69
	STO (R2+124),R5
	LOD R12,69
	STO (R5+0),R12

	# var t91

	# t91 = 1 * 32
	LOD R13,32
	MUL R10,R13

	# var t90

	# t90 = &rows
	STO (R2+496),R10
	LOD R5,R2
	LOD R6,8
	ADD R5,R6

	# var t92

	# t92 = t90 + t91
	STO (R2+500),R5
	LOD R6,(R2+496)
	ADD R5,R6

	# var t93

	# t93 = t92 + 24
	STO (R2+504),R5
	LOD R7,24
	ADD R5,R7

	# var t94

	# t94 = t93 + 0
	STO (R2+508),R5
	LOD R8,0
	ADD R5,R8

	# var t96

	# t96 = 1 * 32
	LOD R9,1
	LOD R10,32
	MUL R9,R10

	# var t95

	# t95 = &rows
	STO (R2+512),R5
	STO (R2+516),R9
	LOD R5,R2
	LOD R6,8
	ADD R5,R6

	# var t97

	# t97 = t95 + t96
	STO (R2+520),R5
	LOD R6,(R2+516)
	ADD R5,R6

	# var t98

	# t98 = t97 + 24
	STO (R2+524),R5
	LOD R7,24
	ADD R5,R7

	# var t99

	# t99 = t98 + 0
	STO (R2+528),R5
	LOD R8,0
	ADD R5,R8

	# var t100

	# t100 = *t99
	STO (R2+532),R5
	LOD R5,(R5+0)

	# var t102

	# t102 = 2 * 32
	LOD R9,2
	LOD R10,32
	MUL R9,R10

	# var t101

	# t101 = &rows
	STO (R2+536),R5
	STO (R2+540),R9
	LOD R5,R2
	LOD R6,8
	ADD R5,R6

	# var t103

	# t103 = t101 + t102
	STO (R2+544),R5
	LOD R6,(R2+540)
	ADD R5,R6

	# var t104

	# t104 = t103 + 24
	STO (R2+548),R5
	LOD R7,24
	ADD R5,R7

	# var t105

	# t105 = t104 + 0
	STO (R2+552),R5
	LOD R8,0
	ADD R5,R8

	# var t106

	# t106 = *t105
	STO (R2+556),R5
	LOD R5,(R5+0)

	# var t107

	# t107 = t100 + t106
	LOD R9,(R2+536)
	STO (R2+560),R5
	ADD R9,R5

	# *t94 = t107
	LOD R10,(R2+512)
	STO (R2+564),R9
	STO (R10+0),R9

	# var t109

	# t109 = 1 * 32
	LOD R11,1
	LOD R12,32
	MUL R11,R12

	# var t108

	# t108 = &rows
	STO (R2+568),R11
	LOD R5,R2
	LOD R6,8
	ADD R5,R6

	# var t110

	# t110 = t108 + t109
	STO (R2+572),R5
	LOD R6,(R2+568)
	ADD R5,R6

	# var t111

	# t111 = t110 + 24
	STO (R2+576),R5
	LOD R7,24
	ADD R5,R7

	# var t112

	# t112 = t111 + 4
	STO (R2+580),R5
	LOD R8,4
	ADD R5,R8

	# var t114

	# t114 = 2 * 32
	LOD R9,2
	LOD R10,32
	MUL R9,R10

	# var t113

	# t113 = &rows
	STO (R2+584),R5
	STO (R2+588),R9
	LOD R5,R2
	LOD R6,8
	ADD R5,R6

	# var t115

	# t115 = t113 + t114
	STO (R2+592),R5
	LOD R6,(R2+588)
	ADD R5,R6

	# var t116

	# t116 = t115 + 24
	STO (R2+596),R5
	LOD R7,24
	ADD R5,R7

	# var t117

	# t117 = t116 + 4
	STO (R2+600),R5
	LOD R8,4
	ADD R5,R8

	# var t118

	# t118 = *t117
	STO (R2+604),R5
	LOD R5,(R5+0)

	# *t112 = t118
	LOD R9,(R2+584)
	STO (R2+608),R5
	STO (R9+0),R5

	# output sum
	LOD R10,(R2+132)
	LOD R15,R10
	OTI

	# output L3
	LOD R11,L3
	LOD R15,R11
	OTS

	# var t123

	# t123 = 0 * 4
	LOD R12,0
	MUL R12,R8

	# var t120

	# t120 = 2 * 32
	LOD R13,2
	LOD R14,32
	MUL R13,R14

	# var t119

	# t119 = &rows
	STO (R2+612),R12
	STO (R2+616),R13
	LOD R5,R2
	LOD R6,8
	ADD R5,R6

	# var t121

	# t121 = t119 + t120
	STO (R2+620),R5
	LOD R6,(R2+616)
	ADD R5,R6

	# var t122

	# t122 = t121 + 0
	STO (R2+624),R5
	LOD R7,0
	ADD R5,R7

	# var t124

	# t124 = t122 + t123
	STO (R2+628),R5
	LOD R8,(R2+612)
	ADD R5,R8

	# var t125

	# t125 = *t124
	STO (R2+632),R5
	LOD R5,(R5+0)

	# output t125
	STO (R2+636),R5
	LOD R15,R5
	OTC

	# var t130

	# t130 = 1 * 4
	LOD R9,1
	LOD R10,4
	MUL R9,R10

	# var t127

	# t127 = 2 * 32
	LOD R11,2
	LOD R12,32
	MUL R11,R12

	# var t126

	# t126 = &rows
	STO (R2+640),R9
	STO (R2+644),R11
	LOD R5,R2
	LOD R6,8
	ADD R5,R6

	# var t128

	# t128 = t126 + t127
	STO (R2+648),R5
	LOD R6,(R2+644)
	ADD R5,R6

	# var t129

	# t129 = t128 + 0
	STO (R2+652),R5
	LOD R7,0
	ADD R5,R7

	# var t131

	# t131 = t129 + t130
	STO (R2+656),R5
	LOD R8,(R2+640)
	ADD R5,R8

	# var t132

	# t132 = *t131
	STO (R2+660),R5
	LOD R5,(R5+0)

	# output t132
	STO (R2+664),R5
	LOD R15,R5
	OTC

	# var t137

	# t137 = 2 * 4
	LOD R9,2
	LOD R10,4
	MUL R9,R10

	# var t134

	# t134 = 2 * 32
	LOD R11,2
	LOD R12,32
	MUL R11,R12

	# var t133

	# t133 = &rows
	STO (R2+668),R9
	STO (R2+672),R11
	LOD R5,R2
	LOD R6,8
	ADD R5,R6

	# var t135

	# t135 = t133 + t134
	STO (R2+676),R5
	LOD R6,(R2+672)
	ADD R5,R6

	# var t136

	# t136 = t135 + 0
	STO (R2+680),R5
	LOD R7,0
	ADD R5,R7

	# var t138

	# t138 = t136 + t137
	STO (R2+684),R5
	LOD R8,(R2+668)
	ADD R5,R8

	# var t139

	# t139 = *t138
	STO (R2+688),R5
	LOD R5,(R5+0)

	# output t139
	STO (R2+692),R5
	LOD R15,R5
	OTC

	# output L3
	LOD R9,L3
	LOD R15,R9
	OTS

	# var t141

	# t141 = 1 * 32
	LOD R10,1
	LOD R11,32
	MUL R10,R11

	# var t140

	# t140 = &rows
	STO (R2+696),R10
	LOD R5,R2
	LOD R6,8
	ADD R5,R6

	# var t142

	# t142 = t140 + t141
	STO (R2+700),R5
	LOD R6,(R2+696)
	ADD R5,R6

	# var t143

	# t143 = t142 + 24
	STO (R2+704),R5
	LOD R7,24
	ADD R5,R7

	# var t144

	# t144 = t143 + 0
	STO (R2+708),R5
	LOD R8,0
	ADD R5,R8

	# var t145

	# t145 = *t144
	STO (R2+712),R5
	LOD R5,(R5+0)

	# output t145
	STO (R2+716),R5
	LOD R15,R5
	OTI

	# output L3
	LOD R9,L3
	LOD R15,R9
	OTS

	# var t147

	# t147 = 1 * 32
	LOD R10,1
	LOD R11,32
	MUL R10,R11

	# var t146

	# t146 = &rows
	STO (R2+720),R10
	LOD R5,R2
	LOD R6,8
	ADD R5,R6

	# var t148

	# t148 = t146 + t147
	STO (R2+724),R5
	LOD R6,(R2+720)
	ADD R5,R6

	# var t149

	# t149 = t148 + 24
	STO (R2+728),R5
	LOD R7,24
	ADD R5,R7

	# var t150

	# t150 = t149 + 4
	STO (R2+732),R5
	LOD R8,4
	ADD R5,R8

	# var t151

	# t151 = *t150
	STO (R2+736),R5
	LOD R5,(R5+0)

	# output t151
	STO (R2+740),R5
	LOD R15,R5
	OTC

	# output L3
	LOD R9,L3
	LOD R15,R9
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

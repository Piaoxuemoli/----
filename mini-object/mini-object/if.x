
# tac list

0x60f2940e6440	label main
0x60f2940e6480	begin
0x60f2940e59d0	var i
0x60f2940e5a70	var j
0x60f2940e5b10	var k
0x60f2940e5b70	input i
0x60f2940e5bd0	input j
0x60f2940e5d10	var t0
0x60f2940e5d50	t0 = (i == j)
0x60f2940e6050	ifz t0 goto L3
0x60f2940e5df0	output L1
0x60f2940e6090	goto L4
0x60f2940e5f50	label L3
0x60f2940e5e90	output L2
0x60f2940e6010	label L4
0x60f2940e61f0	var t1
0x60f2940e6230	t1 = i + j
0x60f2940e6270	k = t1
0x60f2940e6300	output k
0x60f2940e63a0	output L5
0x60f2940e64c0	end

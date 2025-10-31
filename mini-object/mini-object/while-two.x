
# tac list

0x64e0af59f130	label main
0x64e0af59f170	begin
0x64e0af59c9d0	var a
0x64e0af59ca70	var b
0x64e0af59cb10	var c
0x64e0af59cbb0	var d
0x64e0af59cc50	var e
0x64e0af59ccf0	var i
0x64e0af59cd90	var j
0x64e0af59ce30	var k
0x64e0af59ce90	input a
0x64e0af59cef0	input b
0x64e0af59cf50	input c
0x64e0af59d060	j = 5
0x64e0af59ee40	label L1
0x64e0af59d200	var t0
0x64e0af59d240	t0 = (j > 0)
0x64e0af59ee00	ifz t0 goto L2
0x64e0af59d410	output j
0x64e0af59d520	i = 9
0x64e0af59eb00	label L3
0x64e0af59d660	var t1
0x64e0af59d6a0	t1 = (i > 0)
0x64e0af59eac0	ifz t1 goto L4
0x64e0af59d870	output i
0x64e0af59da20	var t2
0x64e0af59da60	t2 = b * c
0x64e0af59db30	var t3
0x64e0af59db70	t3 = a + t2
0x64e0af59dce0	var t4
0x64e0af59dd20	t4 = a + c
0x64e0af59de40	var t5
0x64e0af59de80	t5 = t4 / b
0x64e0af59df50	var t6
0x64e0af59df90	t6 = t3 - t5
0x64e0af59e0b0	var t7
0x64e0af59e0f0	t7 = t6 + 9
0x64e0af59e160	d = t7
0x64e0af59e350	var t8
0x64e0af59e390	t8 = c - a
0x64e0af59e4b0	var t9
0x64e0af59e4f0	t9 = t8 / b
0x64e0af59e5c0	var t10
0x64e0af59e600	t10 = t3 - t9
0x64e0af59e720	var t11
0x64e0af59e760	t11 = t10 + 9
0x64e0af59e7d0	e = t11
0x64e0af59e990	var t12
0x64e0af59e9d0	t12 = i - 1
0x64e0af59ea40	i = t12
0x64e0af59ea80	goto L3
0x64e0af59eb40	label L4
0x64e0af59ec30	var t13
0x64e0af59ec70	t13 = j - 1
0x64e0af59ece0	j = t13
0x64e0af59ed80	output L5
0x64e0af59edc0	goto L1
0x64e0af59ee80	label L2
0x64e0af59ef00	output L6
0x64e0af59ef40	output d
0x64e0af59efa0	output L5
0x64e0af59f030	output e
0x64e0af59f090	output L6
0x64e0af59f1b0	end

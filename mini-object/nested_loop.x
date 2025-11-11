
# tac list

0x5d37eb809f00	label main
0x5d37eb809f40	begin
0x5d37eb8089f0	var i
0x5d37eb808aa0	var j
0x5d37eb808b50	var k
0x5d37eb808c70	k = 0
0x5d37eb809e30	label L1
0x5d37eb808e30	var t0
0x5d37eb808e70	t0 = (k < 10)
0x5d37eb809df0	ifz t0 goto L2
0x5d37eb809080	i = 0
0x5d37eb809bf0	label L3
0x5d37eb8091d0	var t1
0x5d37eb809210	t1 = (i < 10)
0x5d37eb809bb0	ifz t1 goto L4
0x5d37eb809550	var t2
0x5d37eb809590	t2 = 2 * i
0x5d37eb809770	j = t2 + 9
0x5d37eb809830	output j
0x5d37eb8098e0	output L5
0x5d37eb809b00	i = i + 1
0x5d37eb809b70	goto L3
0x5d37eb809c30	label L4
0x5d37eb809d40	k = k + 1
0x5d37eb809db0	goto L1
0x5d37eb809e70	label L2
0x5d37eb809f80	end

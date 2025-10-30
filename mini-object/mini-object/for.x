
# tac list

0x5ce5aaf63cd0	label main
0x5ce5aaf63d10	begin
0x5ce5aaf629d0	var i
0x5ce5aaf62a70	var sum
0x5ce5aaf62b80	sum = 0
0x5ce5aaf62c30	i = 0
0x5ce5aaf63b30	label L1
0x5ce5aaf62dd0	var t0
0x5ce5aaf62e10	t0 = (i < 10)
0x5ce5aaf63af0	ifz t0 goto L3
0x5ce5aaf633b0	var t2
0x5ce5aaf633f0	t2 = (i == 7)
0x5ce5aaf63530	ifz t2 goto L4
0x5ce5aaf63430	goto L3
0x5ce5aaf634f0	label L4
0x5ce5aaf636d0	var t3
0x5ce5aaf63710	t3 = (i < 3)
0x5ce5aaf63870	ifz t3 goto L5
0x5ce5aaf63750	goto L2
0x5ce5aaf63830	label L5
0x5ce5aaf639b0	var t4
0x5ce5aaf639f0	t4 = sum + i
0x5ce5aaf63a30	sum = t4
0x5ce5aaf63ab0	label L2
0x5ce5aaf62fd0	var t1
0x5ce5aaf63010	t1 = i + 1
0x5ce5aaf63050	i = t1
0x5ce5aaf63a70	goto L1
0x5ce5aaf63b70	label L3
0x5ce5aaf63bb0	output sum
0x5ce5aaf63c30	output L6
0x5ce5aaf63d50	end

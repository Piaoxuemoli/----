
# tac list

0x5910d6bc4e00	label main
0x5910d6bc4e40	begin
0x5910d6bc39d0	var value
0x5910d6bc3a70	var result
0x5910d6bc3b80	value = 2
0x5910d6bc3c90	result = 0
0x5910d6bc48a0	var t2
0x5910d6bc48e0	t2 = value
0x5910d6bc4960	var t3
0x5910d6bc49a0	t3 = t2 - 1
0x5910d6bc49e0	ifz t3 goto L2
0x5910d6bc4a80	var t4
0x5910d6bc4ac0	t4 = t2 - 2
0x5910d6bc4b00	ifz t4 goto L3
0x5910d6bc4ba0	var t5
0x5910d6bc4be0	t5 = t2 - 3
0x5910d6bc4c20	ifz t5 goto L4
0x5910d6bc4c60	goto L5
0x5910d6bc4020	label L2
0x5910d6bc3ef0	result = 1
0x5910d6bc3f30	goto L1
0x5910d6bc41e0	label L3
0x5910d6bc40f0	result = 2
0x5910d6bc4570	label L4
0x5910d6bc43c0	var t0
0x5910d6bc4400	t0 = result + 3
0x5910d6bc4440	result = t0
0x5910d6bc4480	goto L1
0x5910d6bc4820	label L5
0x5910d6bc4680	var t1
0x5910d6bc46c0	t1 = - 1
0x5910d6bc4700	result = t1
0x5910d6bc4740	goto L1
0x5910d6bc4ca0	label L1
0x5910d6bc4ce0	output result
0x5910d6bc4d60	output L6
0x5910d6bc4e80	end

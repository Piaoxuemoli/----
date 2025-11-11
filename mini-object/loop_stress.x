
# tac list

0x578ecc179f60	label main
0x578ecc179fa0	begin
0x578ecc1769f0	var a
0x578ecc176aa0	var b
0x578ecc176b50	var c
0x578ecc176c00	var d
0x578ecc176cb0	var e
0x578ecc176d60	var sumd
0x578ecc176e10	var sume
0x578ecc176ec0	var i
0x578ecc176f70	var j
0x578ecc177020	var k
0x578ecc177080	input a
0x578ecc1770e0	input b
0x578ecc177140	input c
0x578ecc177260	sumd = 0
0x578ecc177310	sume = 0
0x578ecc177430	k = 12
0x578ecc178100	var t3
0x578ecc178140	t3 = b * c
0x578ecc178220	var t4
0x578ecc178260	t4 = a + t3
0x578ecc1783e0	var t5
0x578ecc178420	t5 = a + c
0x578ecc178550	var t6
0x578ecc178590	t6 = t5 / b
0x578ecc178670	var t7
0x578ecc1786b0	t7 = t4 - t6
0x578ecc178890	d = t7 + 9
0x578ecc178ac0	var t9
0x578ecc178b00	t9 = c - a
0x578ecc178c30	var t10
0x578ecc178c70	t10 = t9 / b
0x578ecc178d50	var t11
0x578ecc178d90	t11 = t4 - t10
0x578ecc178f70	e = t11 + 13
0x578ecc179c60	label L1
0x578ecc177580	var t0
0x578ecc1775c0	t0 = (k > 0)
0x578ecc179c20	ifz t0 goto L2
0x578ecc177840	j = 15
0x578ecc1799f0	label L3
0x578ecc177990	var t1
0x578ecc1779d0	t1 = (j > 0)
0x578ecc1799b0	ifz t1 goto L4
0x578ecc177c50	i = 18
0x578ecc179780	label L5
0x578ecc177da0	var t2
0x578ecc177de0	t2 = (i > 0)
0x578ecc179740	ifz t2 goto L6
0x578ecc179150	sumd = sumd + d
0x578ecc1792c0	var t14
0x578ecc179300	t14 = sume + e
0x578ecc179470	sume = t14 + d
0x578ecc179690	i = i - 1
0x578ecc179700	goto L5
0x578ecc1797c0	label L6
0x578ecc179900	j = j - 1
0x578ecc179970	goto L3
0x578ecc179a30	label L4
0x578ecc179b70	k = k - 1
0x578ecc179be0	goto L1
0x578ecc179ca0	label L2
0x578ecc179ce0	output sumd
0x578ecc179d70	output L7
0x578ecc179e00	output sume
0x578ecc179eb0	output L8
0x578ecc179fe0	end

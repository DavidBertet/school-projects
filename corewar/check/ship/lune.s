.name "foo"
.comment "a another ship"

	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	ll r1 ,	375
	ll r2 , 375 - 3
	ll r4 , 0
	mode icaras
	ldb [r4], 0, 12
	check
	stb [r1], 0, 12
	b r2
	crash
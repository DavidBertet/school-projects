.name "asr_test"
.comment "asr_com"

	lc r1, %00110110
	asr r1, 2               # r1 equals \%00001101
	lc r1, %10110110 + 045
	asr r1, 2               # r1 equals \%11101101
	write r1
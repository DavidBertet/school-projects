.name "mode ship"
.comment "test mode instr"

	mode icaras
	ll r0, 1000
	mode qirex
	ll r0, 1000
	mode feisar
	ll r0, 1002
	mode mine
	ll r1, 0xcf
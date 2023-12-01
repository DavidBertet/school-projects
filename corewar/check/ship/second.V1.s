.name "vogan"
.comment "Second version of vogan"

	mode	qirex

	stat	r0, 9
	mov 	r1, r0

	ll	r2, 300 + (end - store)
	ll	r3, next - else
	ll	r4, 300
	ll	r5, 0
	ll	r6, 300 + (end - begin)

	#begin of loop
	ldb	[r5], 0, end - begin
begin:
	stb	[r2], 0, end - begin
store:
	sub	r1, r6
	bs	r3
else:
	mov 	r1, r0
	check
next:
	b	r4
end:
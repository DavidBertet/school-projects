.name "vogan"
.comment "First version of vogan."
ll 	r0 , 0x2ecf # Load simple code
ll	r1 , 0x13e0 # into two registers
ll	r6 , 0x047f # into two registers
r0:
ll:
ll	r2 , 100 + end - from1 # Load offsets for
	ll	r3 , 100 + end - from2 + 4
	+ r0 + ll # the two str
ll	r5 , 100 + end - from3 + 8 # the two str
ll      r4 , 100 str	[r2], r0 # Write code just
from1:
str 	[r3], r1 # before PC
from2:
str 	[r5], r6 # before PC
from3:
b	r4
end: # When the PC reaches here , a `check '

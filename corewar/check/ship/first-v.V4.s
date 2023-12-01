.name "vogan"
.comment "Limit of first version of vogan"

mode	piranha

ll 	r0 , 0x2ecf # Load simple code
ll	r1 , 0x13e0 # into two registers
ll	r6 , 0xe65e # into two registers
ll	r8 , 0x9e87 # into two registers
ll	r10 , 0x47fa # into two registers

ll	r2 , 350 + end - from1 # Load offsets for
ll	r3 , 350 + end - from2 + 4 # the two str
ll	r5 , 350 + end - from3 + 8 # the two str
ll	r7 , 350 + end - from4 + 12 # the two str
ll	r9 , 350 + end - from5 + 16 # the two str
ll      r4 , 350

str	[r2], r0 # Write code just
from1:
str 	[r3], r1 # before PC
from2:
str 	[r5], r6 # before PC
from3:
str 	[r7], r8 # before PC
from4:
str 	[r9], r10 # before PC
from5:
b	r4
end: # When the PC reaches here , a `check '

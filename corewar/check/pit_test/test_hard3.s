        ll r1, 0x1fe2
        stb [r2], 5, 12 + ll
ll:     ldb [r15], 8, 4 + ll + 12 % 0xf / 32
        write r18
check:  check
        nop
        nop
        nop
        nop
        xor r1, r4
        not r2, r5
        nop
        nop
        nop
        fork
        mode qirex
        ll r1, 0x1fe2
        stb [r2], 5, 12 + ll
ll:     ldb [r15], 8, 4 + ll + 12 % 0xf / 32
        write r1
check:  check
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        fork
        mode qirex
        ll r1, 0x1fe2
        stb [r2], 5, 12 + ll
ll:     ldb [r15], 8, 4 + ll + 12 % 0xf / 32
        write r18
check:  check
        nop
        nop
        nop
        nop
        mov r4, r1
        neg r3, r1
        cmp r2, r2
        nop
        nop
        nop
        fork
        mode qirex
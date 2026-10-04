// Library: libffavc.so
// Function ID: libffavc::0x561d4
// Recovered Name: sub_561d4
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x561d4 | Size: 196 bytes | SHA256: 1d43f8846ca53e119499426a44fe5b3a2b642b1080b50e888631ff6d31310d38
// Callers: 0 | Callees: 2 | Imports: 1

// Calls external APIs: memcpy

void sub_561d4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 49 instructions
    /* 0x561d4 */ stp x29, x30, [sp, #-0x50]!;
    /* 0x561d8 */ str x25, [sp, #0x10];
    /* 0x561dc */ stp x24, x23, [sp, #0x20];
    /* 0x561e0 */ stp x22, x21, [sp, #0x30];
    /* 0x561e4 */ stp x20, x19, [sp, #0x40];
    /* 0x561e8 */ mov x29, sp;
    /* 0x561ec */ ldp x23, x24, [x1];
    /* 0x561f0 */ mov x19, x0;
    /* 0x561f4 */ cmp x23, x24;
    /* 0x561f8 */ b.eq #0x56250;
    /* 0x561fc */ mov x20, xzr;
    sub_101694();
    memcpy();
    sub_101694();
    sub_56298();
    sub_fb4a8();
    return x0;
}

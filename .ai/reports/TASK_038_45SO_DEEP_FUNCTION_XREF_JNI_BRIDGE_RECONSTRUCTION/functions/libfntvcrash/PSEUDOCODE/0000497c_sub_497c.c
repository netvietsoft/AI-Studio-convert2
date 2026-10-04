// Library: libfntvcrash.so
// Function ID: libfntvcrash::0x497c
// Recovered Name: sub_497c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x497c | Size: 40 bytes | SHA256: 942a9524ae3ec5de138a1d0a412d30d31da72c19992444c13371b5708da0e25e
// Callers: 0 | Callees: 1 | Imports: 0


void sub_497c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 10 instructions
    /* 0x497c */ stp x29, x30, [sp, #0x10];
    /* 0x4980 */ add x29, sp, #0x10;
    /* 0x4984 */ add x2, sp, #8;
    /* 0x4988 */ mov w1, #-1;
    sub_4a4c();
    /* 0x4990 */ ldr x0, [sp, #8];
    /* 0x4994 */ ldp x29, x30, [sp, #0x10];
    /* 0x4998 */ add sp, sp, #0x20;
    /* 0x499c */ autiasp ;
    return x0;
}

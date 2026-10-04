// Library: libPVGLive.so
// Function ID: libPVGLive::0x27804
// Recovered Name: sub_27804
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x27804 | Size: 52 bytes | SHA256: 2d2a47b007e9f02da2d0733b3b5b3af7e9875a732fc82d8fae7559b1a97c8b57
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: fileno, fwrite

void sub_27804(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 13 instructions
    /* 0x27804 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x27808 */ mov x29, sp;
    /* 0x2780c */ mov w2, w2;
    /* 0x27810 */ mov x0, x1;
    /* 0x27814 */ mov w1, #1;
    fwrite();
    /* 0x2781c */ ldp x29, x30, [sp], #0x10;
    return x0;
    /* 0x27824 */ ldr x0, [x0, #0x20];
    /* 0x27828 */ cbz x0, #0x27830;
    /* 0x2782c */ b #0x90590;
    return x0;
}

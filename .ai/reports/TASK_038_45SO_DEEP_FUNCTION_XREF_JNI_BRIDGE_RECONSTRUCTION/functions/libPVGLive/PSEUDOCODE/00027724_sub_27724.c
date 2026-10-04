// Library: libPVGLive.so
// Function ID: libPVGLive::0x27724
// Recovered Name: sub_27724
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x27724 | Size: 100 bytes | SHA256: aa64daf600a7d60d41a6bf7c319f4d26cffae193f00bc14ce019f743f87bea55
// Callers: 1 | Callees: 0 | Imports: 2

// Calls external APIs: _ZdlPv, fclose

void sub_27724(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 25 instructions
    /* 0x27724 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x27728 */ str x19, [sp, #0x10];
    /* 0x2772c */ mov x29, sp;
    /* 0x27730 */ mov x19, x0;
    /* 0x27734 */ ldr x0, [x0, #0x20];
    /* 0x27738 */ adrp x8, #0x94000;
    /* 0x2773c */ add x8, x8, #0xdd8;
    /* 0x27740 */ str x8, [x19];
    /* 0x27744 */ cbz x0, #0x27754;
    /* 0x27748 */ ldrb w8, [x19, #0x28];
    /* 0x2774c */ cbz w8, #0x27754;
    fclose();
    return x0;
}

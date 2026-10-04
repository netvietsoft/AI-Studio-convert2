// Library: libPVGLive.so
// Function ID: libPVGLive::0x27838
// Recovered Name: sub_27838
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x27838 | Size: 160 bytes | SHA256: 627bb76e8fa94312e1575b7d5a5075fb6618814bf85cbd6b6fd75912a4b526fc
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: fseek, ftell

void sub_27838(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 40 instructions
    /* 0x27838 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x2783c */ str x21, [sp, #0x10];
    /* 0x27840 */ stp x20, x19, [sp, #0x20];
    /* 0x27844 */ mov x29, sp;
    /* 0x27848 */ ldr x19, [x0, #0x20];
    /* 0x2784c */ cbz x19, #0x278b0;
    /* 0x27850 */ mov x0, x19;
    /* 0x27854 */ cmp w2, #0x10, lsl #12;
    /* 0x27858 */ b.ne #0x278a8;
    ftell();
    /* 0x27860 */ tbnz x0, #0x3f, #0x278b0;
    fseek();
    ftell();
    fseek();
    fseek();
    return x0;
    ftell();
}

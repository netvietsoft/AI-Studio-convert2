// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0x1032a4
// Recovered Name: _ZN14MTFilterKernel17MTGaussBlurFilterD2Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x1032a4 | Size: 80 bytes | SHA256: 4a8c0e7633a7afbc4776c21ac7860ef0c09762da43cdd8ed56938f47fa5ea2fb
// Callers: 1 | Callees: 1 | Imports: 1

// Calls external APIs: glDeleteTextures

void _ZN14MTFilterKernel17MTGaussBlurFilterD2Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 20 instructions
    /* 0x1032a4 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x1032a8 */ stp x20, x19, [sp, #0x10];
    /* 0x1032ac */ mov x29, sp;
    /* 0x1032b0 */ adrp x8, #0x1c5000;
    /* 0x1032b4 */ mov x20, x0;
    /* 0x1032b8 */ mov x19, x0;
    /* 0x1032bc */ ldr x8, [x8, #0x690];
    /* 0x1032c0 */ ldr w9, [x20, #0xd0]!;
    /* 0x1032c4 */ add x8, x8, #0x10;
    /* 0x1032c8 */ str x8, [x0];
    /* 0x1032cc */ cbz w9, #0x1032e0;
    glDeleteTextures();
    sub_c0b38();
}

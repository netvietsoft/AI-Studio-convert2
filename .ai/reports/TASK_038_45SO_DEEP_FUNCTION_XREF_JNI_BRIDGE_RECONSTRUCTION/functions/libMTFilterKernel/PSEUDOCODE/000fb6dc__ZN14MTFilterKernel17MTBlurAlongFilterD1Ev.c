// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xfb6dc
// Recovered Name: _ZN14MTFilterKernel17MTBlurAlongFilterD1Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0xfb6dc | Size: 80 bytes | SHA256: 66ed9a8c18faa102a88f2aec8fd272cdec6dda24675c1fb0af5c6888a99cb646
// Callers: 1 | Callees: 1 | Imports: 1

// Calls external APIs: glDeleteTextures

void _ZN14MTFilterKernel17MTBlurAlongFilterD1Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 20 instructions
    /* 0xfb6dc */ stp x29, x30, [sp, #-0x20]!;
    /* 0xfb6e0 */ stp x20, x19, [sp, #0x10];
    /* 0xfb6e4 */ mov x29, sp;
    /* 0xfb6e8 */ adrp x8, #0x1c5000;
    /* 0xfb6ec */ mov x20, x0;
    /* 0xfb6f0 */ mov x19, x0;
    /* 0xfb6f4 */ ldr x8, [x8, #0x640];
    /* 0xfb6f8 */ ldr w9, [x20, #0xc4]!;
    /* 0xfb6fc */ add x8, x8, #0x10;
    /* 0xfb700 */ str x8, [x0];
    /* 0xfb704 */ cbz w9, #0xfb718;
    glDeleteTextures();
    sub_c0b38();
}

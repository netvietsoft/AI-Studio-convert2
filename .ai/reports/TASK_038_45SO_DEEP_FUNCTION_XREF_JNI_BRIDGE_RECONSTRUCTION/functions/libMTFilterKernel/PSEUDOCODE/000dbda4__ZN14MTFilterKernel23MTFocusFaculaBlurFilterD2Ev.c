// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xdbda4
// Recovered Name: _ZN14MTFilterKernel23MTFocusFaculaBlurFilterD2Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0xdbda4 | Size: 136 bytes | SHA256: 6101fb17b7dbbc31ae3523c641f2386cfebc1a474b035a5d025ba6a49b1a6ab3
// Callers: 1 | Callees: 1 | Imports: 1

// Calls external APIs: glDeleteTextures

void _ZN14MTFilterKernel23MTFocusFaculaBlurFilterD2Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 34 instructions
    /* 0xdbda4 */ stp x29, x30, [sp, #-0x20]!;
    /* 0xdbda8 */ stp x20, x19, [sp, #0x10];
    /* 0xdbdac */ mov x29, sp;
    /* 0xdbdb0 */ adrp x8, #0x1c5000;
    /* 0xdbdb4 */ mov x20, x0;
    /* 0xdbdb8 */ mov x19, x0;
    /* 0xdbdbc */ ldr x8, [x8, #0x520];
    /* 0xdbdc0 */ ldr w9, [x20, #0xb0]!;
    /* 0xdbdc4 */ add x8, x8, #0x10;
    /* 0xdbdc8 */ str x8, [x0];
    /* 0xdbdcc */ cbz w9, #0xdbde0;
    glDeleteTextures();
    glDeleteTextures();
    glDeleteTextures();
    sub_c0b38();
}

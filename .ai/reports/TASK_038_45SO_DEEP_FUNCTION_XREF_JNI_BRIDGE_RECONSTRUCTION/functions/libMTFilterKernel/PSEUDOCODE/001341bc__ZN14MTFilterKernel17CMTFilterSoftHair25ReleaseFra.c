// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0x1341bc
// Recovered Name: _ZN14MTFilterKernel17CMTFilterSoftHair25ReleaseFramebufferTextureEv
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x1341bc | Size: 252 bytes | SHA256: 4c0c32239e45c039d659e9a4a1628dd4b8c01e9ccc2f397731b39c93403f8688
// Callers: 2 | Callees: 0 | Imports: 2

// Calls external APIs: glDeleteFramebuffers, glDeleteTextures

void _ZN14MTFilterKernel17CMTFilterSoftHair25ReleaseFramebufferTextureEv(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 63 instructions
    /* 0x1341bc */ stp x29, x30, [sp, #-0x20]!;
    /* 0x1341c0 */ stp x20, x19, [sp, #0x10];
    /* 0x1341c4 */ mov x29, sp;
    /* 0x1341c8 */ ldr w8, [x0, #0x100];
    /* 0x1341cc */ mov x19, x0;
    /* 0x1341d0 */ cbz w8, #0x1341e8;
    /* 0x1341d4 */ add x20, x19, #0x100;
    /* 0x1341d8 */ mov w0, #1;
    /* 0x1341dc */ mov x1, x20;
    glDeleteFramebuffers();
    /* 0x1341e4 */ str wzr, [x20];
    glDeleteTextures();
    glDeleteFramebuffers();
    glDeleteTextures();
    glDeleteFramebuffers();
    glDeleteTextures();
    glDeleteFramebuffers();
    glDeleteTextures();
    return x0;
}

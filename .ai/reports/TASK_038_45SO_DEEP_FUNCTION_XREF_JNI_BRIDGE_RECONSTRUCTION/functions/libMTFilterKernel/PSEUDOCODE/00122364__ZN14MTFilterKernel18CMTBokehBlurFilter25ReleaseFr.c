// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0x122364
// Recovered Name: _ZN14MTFilterKernel18CMTBokehBlurFilter25ReleaseFramebufferTextureEv
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x122364 | Size: 420 bytes | SHA256: 5458440f1d11b427b6b285e893edde4a79c3d82c655ef0e3050b49d169445067
// Callers: 2 | Callees: 0 | Imports: 2

// Calls external APIs: glDeleteFramebuffers, glDeleteTextures

void _ZN14MTFilterKernel18CMTBokehBlurFilter25ReleaseFramebufferTextureEv(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 105 instructions
    /* 0x122364 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x122368 */ stp x20, x19, [sp, #0x10];
    /* 0x12236c */ mov x29, sp;
    /* 0x122370 */ ldr w8, [x0, #0x100];
    /* 0x122374 */ mov x19, x0;
    /* 0x122378 */ cbz w8, #0x122390;
    /* 0x12237c */ add x20, x19, #0x100;
    /* 0x122380 */ mov w0, #1;
    /* 0x122384 */ mov x1, x20;
    glDeleteFramebuffers();
    /* 0x12238c */ str wzr, [x20];
    glDeleteTextures();
    glDeleteFramebuffers();
    glDeleteTextures();
    glDeleteFramebuffers();
    glDeleteTextures();
    glDeleteFramebuffers();
    glDeleteTextures();
    glDeleteFramebuffers();
    glDeleteTextures();
    glDeleteFramebuffers();
    glDeleteTextures();
    glDeleteFramebuffers();
    glDeleteTextures();
    return x0;
}

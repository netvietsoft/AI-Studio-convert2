// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0x1032f4
// Recovered Name: _ZN14MTFilterKernel17MTGaussBlurFilterD0Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x1032f4 | Size: 36 bytes | SHA256: ef0e1279f37cf46866bc21c8313f9928e2aede301afa095af3eadb44a0515b62
// Callers: 0 | Callees: 1 | Imports: 1

// Calls external APIs: _ZdlPv

void _ZN14MTFilterKernel17MTGaussBlurFilterD0Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x1032f4 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x1032f8 */ str x19, [sp, #0x10];
    /* 0x1032fc */ mov x29, sp;
    /* 0x103300 */ mov x19, x0;
    _ZN14MTFilterKernel17MTGaussBlurFilterD2Ev();
    /* 0x103308 */ mov x0, x19;
    /* 0x10330c */ ldr x19, [sp, #0x10];
    /* 0x103310 */ ldp x29, x30, [sp], #0x20;
    /* 0x103314 */ b #0x1b42e0;
}

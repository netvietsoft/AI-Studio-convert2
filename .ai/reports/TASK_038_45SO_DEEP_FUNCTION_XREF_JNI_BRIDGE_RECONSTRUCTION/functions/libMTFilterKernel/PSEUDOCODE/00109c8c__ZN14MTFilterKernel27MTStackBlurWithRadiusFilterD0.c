// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0x109c8c
// Recovered Name: _ZN14MTFilterKernel27MTStackBlurWithRadiusFilterD0Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x109c8c | Size: 36 bytes | SHA256: ce4224a2153e900c7dd19a288e3ddb9044dd8eef089250c839b8a7deafd8bfbd
// Callers: 0 | Callees: 1 | Imports: 1

// Calls external APIs: _ZdlPv

void _ZN14MTFilterKernel27MTStackBlurWithRadiusFilterD0Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x109c8c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x109c90 */ str x19, [sp, #0x10];
    /* 0x109c94 */ mov x29, sp;
    /* 0x109c98 */ mov x19, x0;
    _ZN14MTFilterKernel27MTStackBlurWithRadiusFilterD2Ev();
    /* 0x109ca0 */ mov x0, x19;
    /* 0x109ca4 */ ldr x19, [sp, #0x10];
    /* 0x109ca8 */ ldp x29, x30, [sp], #0x20;
    /* 0x109cac */ b #0x1b42e0;
}

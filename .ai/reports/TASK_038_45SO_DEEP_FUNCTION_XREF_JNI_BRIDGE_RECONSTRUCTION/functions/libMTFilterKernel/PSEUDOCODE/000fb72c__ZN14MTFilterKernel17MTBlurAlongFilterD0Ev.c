// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xfb72c
// Recovered Name: _ZN14MTFilterKernel17MTBlurAlongFilterD0Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0xfb72c | Size: 36 bytes | SHA256: 2d2580611b2e341921b9e0dd78390cb2c6c26a77b987fb4f19c261cdd642d94a
// Callers: 0 | Callees: 1 | Imports: 1

// Calls external APIs: _ZdlPv

void _ZN14MTFilterKernel17MTBlurAlongFilterD0Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0xfb72c */ stp x29, x30, [sp, #-0x20]!;
    /* 0xfb730 */ str x19, [sp, #0x10];
    /* 0xfb734 */ mov x29, sp;
    /* 0xfb738 */ mov x19, x0;
    _ZN14MTFilterKernel17MTBlurAlongFilterD1Ev();
    /* 0xfb740 */ mov x0, x19;
    /* 0xfb744 */ ldr x19, [sp, #0x10];
    /* 0xfb748 */ ldp x29, x30, [sp], #0x20;
    /* 0xfb74c */ b #0x1b42e0;
}

// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0x166800
// Recovered Name: _ZN14MTFilterKernel36GPUImageGaussianBlurWithRadiusFilterD0Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x166800 | Size: 36 bytes | SHA256: a429f3378ec074a4e211b5242dfe7fb53f0e7da736985de6ac1f58d9442114d8
// Callers: 0 | Callees: 1 | Imports: 1

// Calls external APIs: _ZdlPv

void _ZN14MTFilterKernel36GPUImageGaussianBlurWithRadiusFilterD0Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x166800 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x166804 */ str x19, [sp, #0x10];
    /* 0x166808 */ mov x29, sp;
    /* 0x16680c */ mov x19, x0;
    _ZN14MTFilterKernel36GPUImageGaussianBlurWithRadiusFilterD2Ev();
    /* 0x166814 */ mov x0, x19;
    /* 0x166818 */ ldr x19, [sp, #0x10];
    /* 0x16681c */ ldp x29, x30, [sp], #0x20;
    /* 0x166820 */ b #0x1b42e0;
}

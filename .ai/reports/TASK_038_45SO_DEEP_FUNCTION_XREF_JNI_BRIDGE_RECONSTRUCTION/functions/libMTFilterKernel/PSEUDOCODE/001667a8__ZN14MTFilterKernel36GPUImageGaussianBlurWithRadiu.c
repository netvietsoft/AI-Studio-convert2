// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0x1667a8
// Recovered Name: _ZN14MTFilterKernel36GPUImageGaussianBlurWithRadiusFilterC1Eib
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x1667a8 | Size: 84 bytes | SHA256: 2c911320621737e47edd9a7a86286be59a2d06db5fdd285629785177e2d2c53c
// Callers: 0 | Callees: 1 | Imports: 0


void _ZN14MTFilterKernel36GPUImageGaussianBlurWithRadiusFilterC1Eib(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 21 instructions
    /* 0x1667a8 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x1667ac */ str x21, [sp, #0x10];
    /* 0x1667b0 */ stp x20, x19, [sp, #0x20];
    /* 0x1667b4 */ mov x29, sp;
    /* 0x1667b8 */ mov w19, w2;
    /* 0x1667bc */ mov w20, w1;
    /* 0x1667c0 */ mov x21, x0;
    _ZN14MTFilterKernel21GPUImageTwoPassFilterC2Ev();
    /* 0x1667c8 */ adrp x8, #0x1c5000;
    /* 0x1667cc */ mov w9, #0x3f800000;
    /* 0x1667d0 */ ldr x8, [x8, #0xa50];
    return x0;
}

// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0x166760
// Recovered Name: _ZN14MTFilterKernel36GPUImageGaussianBlurWithRadiusFilterC2Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x166760 | Size: 72 bytes | SHA256: 8a2e6d991e98b8d5258224f5bf89a466b0de98cd59666a844b4e09c857f030f5
// Callers: 0 | Callees: 1 | Imports: 0


void _ZN14MTFilterKernel36GPUImageGaussianBlurWithRadiusFilterC2Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 18 instructions
    /* 0x166760 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x166764 */ str x19, [sp, #0x10];
    /* 0x166768 */ mov x29, sp;
    /* 0x16676c */ mov x19, x0;
    _ZN14MTFilterKernel21GPUImageTwoPassFilterC2Ev();
    /* 0x166774 */ adrp x8, #0x1c5000;
    /* 0x166778 */ mov x9, #4;
    /* 0x16677c */ ldr x8, [x8, #0xa50];
    /* 0x166780 */ movk x9, #0x3f80, lsl #48;
    /* 0x166784 */ str xzr, [x19, #0xd0];
    /* 0x166788 */ str wzr, [x19, #0xcc];
    return x0;
}

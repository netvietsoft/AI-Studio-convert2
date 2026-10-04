// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0x164778
// Recovered Name: _ZN14MTFilterKernel26GPUImageGaussianBlurFilterD0Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x164778 | Size: 36 bytes | SHA256: c2aee05add4024ed9fcb453b2df092d9988321f673801979546e1b63b96e366d
// Callers: 0 | Callees: 1 | Imports: 1

// Calls external APIs: _ZdlPv

void _ZN14MTFilterKernel26GPUImageGaussianBlurFilterD0Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x164778 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x16477c */ str x19, [sp, #0x10];
    /* 0x164780 */ mov x29, sp;
    /* 0x164784 */ mov x19, x0;
    _ZN14MTFilterKernel26GPUImageGaussianBlurFilterD2Ev();
    /* 0x16478c */ mov x0, x19;
    /* 0x164790 */ ldr x19, [sp, #0x10];
    /* 0x164794 */ ldp x29, x30, [sp], #0x20;
    /* 0x164798 */ b #0x1b42e0;
}

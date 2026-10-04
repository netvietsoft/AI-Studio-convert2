// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0x164744
// Recovered Name: _ZN14MTFilterKernel26GPUImageGaussianBlurFilterC1Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x164744 | Size: 48 bytes | SHA256: afeff1412d05178bbcca6e0fcc5477e87bcdd2afa6de3ca4d9c5c8a103d1f6ee
// Callers: 0 | Callees: 1 | Imports: 0


void _ZN14MTFilterKernel26GPUImageGaussianBlurFilterC1Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 12 instructions
    /* 0x164744 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x164748 */ str x19, [sp, #0x10];
    /* 0x16474c */ mov x29, sp;
    /* 0x164750 */ mov x19, x0;
    _ZN14MTFilterKernel36GPUImageTwoPassTextureSamplingFilterC1Ev();
    /* 0x164758 */ nop ;
    /* 0x16475c */ adr x8, #0x1c2e68;
    /* 0x164760 */ add x8, x8, #0x10;
    /* 0x164764 */ str x8, [x19];
    /* 0x164768 */ ldr x19, [sp, #0x10];
    /* 0x16476c */ ldp x29, x30, [sp], #0x20;
    return x0;
}

// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0x16572c
// Recovered Name: _ZN14MTFilterKernel26GPUImageGaussianBlurFilter25setTexelSpacingMultiplierEf
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x16572c | Size: 60 bytes | SHA256: 1474543739ac1d202c29e46834bf8e4815b31b06665b2a93d861d4ed61fba6d4
// Callers: 0 | Callees: 0 | Imports: 0


void _ZN14MTFilterKernel26GPUImageGaussianBlurFilter25setTexelSpacingMultiplierEf(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 15 instructions
    /* 0x16572c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x165730 */ str x19, [sp, #0x10];
    /* 0x165734 */ mov x29, sp;
    /* 0x165738 */ ldr x8, [x0];
    /* 0x16573c */ str s0, [x0, #0xdc];
    /* 0x165740 */ mov x19, x0;
    /* 0x165744 */ stp s0, s0, [x0, #0xc0];
    /* 0x165748 */ ldr x8, [x8, #0x70];
    /* 0x16574c */ blr x8;
    /* 0x165750 */ ldr x8, [x19];
    /* 0x165754 */ ldr x1, [x8, #0x110];
}

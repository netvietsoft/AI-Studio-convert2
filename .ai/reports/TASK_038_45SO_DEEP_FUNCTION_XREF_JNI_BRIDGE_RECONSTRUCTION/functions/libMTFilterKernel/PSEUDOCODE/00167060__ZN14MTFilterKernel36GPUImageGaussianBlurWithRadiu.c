// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0x167060
// Recovered Name: _ZN14MTFilterKernel36GPUImageGaussianBlurWithRadiusFilter10readConfigEPNS_15GPUImageContextERKNS_10MTPugiDictE
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x167060 | Size: 396 bytes | SHA256: e53c0a8fafe8384992cace78fbad7ae6cfbd8cfa9315422483e15bff0656e011
// Callers: 0 | Callees: 1 | Imports: 0


void _ZN14MTFilterKernel36GPUImageGaussianBlurWithRadiusFilter10readConfigEPNS_15GPUImageContextERKNS_10MTPugiDictE(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 99 instructions
    /* 0x167060 */ stp x29, x30, [sp, #-0x50]!;
    /* 0x167064 */ stp x26, x25, [sp, #0x10];
    /* 0x167068 */ stp x24, x23, [sp, #0x20];
    /* 0x16706c */ stp x22, x21, [sp, #0x30];
    /* 0x167070 */ stp x20, x19, [sp, #0x40];
    /* 0x167074 */ mov x29, sp;
    /* 0x167078 */ ldr x8, [x2];
    /* 0x16707c */ mov x20, x0;
    /* 0x167080 */ mov x0, x2;
    /* 0x167084 */ mov x19, x2;
    /* 0x167088 */ ldr x8, [x8, #0x80];
    _ZNK14MTFilterKernel9MTPugiAny8GetFloatEv();
    _ZNK14MTFilterKernel9MTPugiAny8GetFloatEv();
    return x0;
}

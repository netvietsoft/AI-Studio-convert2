// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0x10a428
// Recovered Name: _ZN14MTFilterKernel27MTStackBlurWithRadiusFilter10readConfigEPNS_15GPUImageContextERKNS_10MTPugiDictE
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x10a428 | Size: 592 bytes | SHA256: 6f45e2571b58223aa4a0d5a156dfa0bcf8d16bdd9702c34b007d225df2daf33e
// Callers: 0 | Callees: 2 | Imports: 0


void _ZN14MTFilterKernel27MTStackBlurWithRadiusFilter10readConfigEPNS_15GPUImageContextERKNS_10MTPugiDictE(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 148 instructions
    /* 0x10a428 */ stp x29, x30, [sp, #-0x60]!;
    /* 0x10a42c */ stp x28, x27, [sp, #0x10];
    /* 0x10a430 */ stp x26, x25, [sp, #0x20];
    /* 0x10a434 */ stp x24, x23, [sp, #0x30];
    /* 0x10a438 */ stp x22, x21, [sp, #0x40];
    /* 0x10a43c */ stp x20, x19, [sp, #0x50];
    /* 0x10a440 */ mov x29, sp;
    /* 0x10a444 */ ldr x8, [x2];
    /* 0x10a448 */ mov x20, x0;
    /* 0x10a44c */ mov x0, x2;
    /* 0x10a450 */ mov x19, x2;
    _ZNK14MTFilterKernel9MTPugiAny10GetBooleanEv();
    _ZNK14MTFilterKernel9MTPugiAny8GetFloatEv();
    _ZNK14MTFilterKernel9MTPugiAny8GetFloatEv();
    _ZNK14MTFilterKernel9MTPugiAny8GetFloatEv();
    return x0;
}

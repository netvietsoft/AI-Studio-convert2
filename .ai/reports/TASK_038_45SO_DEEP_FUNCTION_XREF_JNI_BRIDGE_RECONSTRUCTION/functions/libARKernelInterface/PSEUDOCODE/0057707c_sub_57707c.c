// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57707c
// Recovered Name: sub_57707c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57707c | Size: 64 bytes | SHA256: 77f6ff355c36e16b2df5b9f45c27aa35ff5a7245b06358d907e0049f5038474f
// Callers: 0 | Callees: 2 | Imports: 2

// Dynamic Registration: nativeCreateInstance()J (table at 0x10cdbe0)
// Calls external APIs: _ZdlPv, _Znwm

jlong sub_57707c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 16 instructions
    /* 0x57707c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x577080 */ stp x20, x19, [sp, #0x10];
    /* 0x577084 */ mov x29, sp;
    /* 0x577088 */ mov w0, #0x18;
    _Znwm();
    /* 0x577090 */ mov x19, x0;
    sub_5749b4();
    /* 0x577098 */ mov x0, x19;
    /* 0x57709c */ ldp x20, x19, [sp, #0x10];
    /* 0x5770a0 */ ldp x29, x30, [sp], #0x20;
    return x0;
    _ZdlPv();
    sub_1042be4();
}

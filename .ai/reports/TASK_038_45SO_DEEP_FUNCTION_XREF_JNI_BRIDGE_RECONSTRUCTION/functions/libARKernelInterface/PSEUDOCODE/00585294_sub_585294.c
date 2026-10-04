// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x585294
// Recovered Name: sub_585294
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x585294 | Size: 64 bytes | SHA256: d07bc84652006180af35734711d872497c683d805bf7eda4c249b008e0f3f7a9
// Callers: 0 | Callees: 2 | Imports: 2

// Dynamic Registration: nativeCreateInstance()J (table at 0x10cf938)
// Calls external APIs: _ZdlPv, _Znwm

jlong sub_585294(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 16 instructions
    /* 0x585294 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x585298 */ stp x20, x19, [sp, #0x10];
    /* 0x58529c */ mov x29, sp;
    /* 0x5852a0 */ mov w0, #0x2c0;
    _Znwm();
    /* 0x5852a8 */ mov x19, x0;
    sub_583b14();
    /* 0x5852b0 */ mov x0, x19;
    /* 0x5852b4 */ ldp x20, x19, [sp, #0x10];
    /* 0x5852b8 */ ldp x29, x30, [sp], #0x20;
    return x0;
    _ZdlPv();
    sub_1042be4();
}

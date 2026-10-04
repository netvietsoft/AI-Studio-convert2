// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x578c60
// Recovered Name: sub_578c60
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x578c60 | Size: 36 bytes | SHA256: 163cf439f0ba0359da4194239d2eba20db3a48bc90f58e739f2b424912258ff6
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nativeCreateInstance()J (table at 0x10ce030)
// Calls external APIs: _Znwm

jlong sub_578c60(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x578c60 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x578c64 */ mov x29, sp;
    /* 0x578c68 */ mov w0, #0x28;
    _Znwm();
    /* 0x578c70 */ movi v0.2d, #0000000000000000;
    /* 0x578c74 */ stp q0, q0, [x0];
    /* 0x578c78 */ str xzr, [x0, #0x20];
    /* 0x578c7c */ ldp x29, x30, [sp], #0x10;
    return x0;
}

// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57d1a8
// Recovered Name: sub_57d1a8
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57d1a8 | Size: 44 bytes | SHA256: ca8aefcdd270d03319f662c9facacd393276f2d3aa0cc61755017914972345f9
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nativeCreateInstance()J (table at 0x10cec30)
// Calls external APIs: _Znwm

jlong sub_57d1a8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 11 instructions
    /* 0x57d1a8 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x57d1ac */ mov x29, sp;
    /* 0x57d1b0 */ mov w0, #0x18;
    _Znwm();
    /* 0x57d1b8 */ adrp x8, #0x104e000;
    /* 0x57d1bc */ add x8, x8, #0x380;
    /* 0x57d1c0 */ str wzr, [x0, #0x14];
    /* 0x57d1c4 */ stp x8, xzr, [x0];
    /* 0x57d1c8 */ stur xzr, [x0, #0xc];
    /* 0x57d1cc */ ldp x29, x30, [sp], #0x10;
    return x0;
}

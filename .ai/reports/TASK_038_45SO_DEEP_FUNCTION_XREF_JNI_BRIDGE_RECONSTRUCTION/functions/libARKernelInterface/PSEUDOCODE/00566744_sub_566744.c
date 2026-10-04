// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x566744
// Recovered Name: sub_566744
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x566744 | Size: 3472 bytes | SHA256: 9ec7e5201d6b698bd2226490c090e6454df9a39998c710871fd8edb8e99f31d8
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nativeCreateInstance()J (table at 0x10cc9e0)
// Calls external APIs: _Znwm, __stack_chk_fail

jlong sub_566744(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 868 instructions
    /* 0x566744 */ stp x29, x30, [sp, #-0x60]!;
    /* 0x566748 */ stp x28, x27, [sp, #0x10];
    /* 0x56674c */ stp x26, x25, [sp, #0x20];
    /* 0x566750 */ stp x24, x23, [sp, #0x30];
    /* 0x566754 */ stp x22, x21, [sp, #0x40];
    /* 0x566758 */ stp x20, x19, [sp, #0x50];
    /* 0x56675c */ mov x29, sp;
    /* 0x566760 */ sub sp, sp, #0xa70;
    /* 0x566764 */ mrs x8, tpidr_el0;
    /* 0x566768 */ mov w0, #0xab0;
    /* 0x56676c */ sub x19, x29, #0x100;
    _Znwm();
    return x0;
    __stack_chk_fail();
}

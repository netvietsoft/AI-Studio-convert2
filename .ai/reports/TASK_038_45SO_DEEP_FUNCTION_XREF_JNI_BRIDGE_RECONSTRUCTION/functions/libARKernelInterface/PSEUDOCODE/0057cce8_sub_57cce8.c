// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57cce8
// Recovered Name: sub_57cce8
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57cce8 | Size: 288 bytes | SHA256: d362a0aa0588844be71b3c87f64daa6c856764d98bc116d7aaf0d8c80260d597
// Callers: 0 | Callees: 0 | Imports: 4

// Dynamic Registration: nativeCreateInstance()J (table at 0x10ceaf8)
// Calls external APIs: _Znwm, __stack_chk_fail, memcpy, memset

jlong sub_57cce8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 72 instructions
    /* 0x57cce8 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x57ccec */ stp x28, x21, [sp, #0x10];
    /* 0x57ccf0 */ stp x20, x19, [sp, #0x20];
    /* 0x57ccf4 */ mov x29, sp;
    /* 0x57ccf8 */ sub sp, sp, #0xbd0;
    /* 0x57ccfc */ mrs x20, tpidr_el0;
    /* 0x57cd00 */ mov w0, #0xbc8;
    /* 0x57cd04 */ ldr x8, [x20, #0x28];
    /* 0x57cd08 */ stur x8, [x29, #-8];
    _Znwm();
    /* 0x57cd10 */ mov w1, wzr;
    memset();
    memset();
    memcpy();
    return x0;
    __stack_chk_fail();
}

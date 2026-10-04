// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x560dfc
// Recovered Name: sub_560dfc
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x560dfc | Size: 1940 bytes | SHA256: 193f869e7fe992087b107747fdd31e57a7bc2c9f6ef3f601376c56c2c33e1892
// Callers: 0 | Callees: 0 | Imports: 4

// Dynamic Registration: nativeCreateInstance()J (table at 0x10cc4d0)
// Calls external APIs: _Znwm, __stack_chk_fail, memcpy, memset

jlong sub_560dfc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 485 instructions
    /* 0x560dfc */ stp x29, x30, [sp, #-0x60]!;
    /* 0x560e00 */ stp x28, x27, [sp, #0x10];
    /* 0x560e04 */ stp x26, x25, [sp, #0x20];
    /* 0x560e08 */ stp x24, x23, [sp, #0x30];
    /* 0x560e0c */ stp x22, x21, [sp, #0x40];
    /* 0x560e10 */ stp x20, x19, [sp, #0x50];
    /* 0x560e14 */ mov x29, sp;
    /* 0x560e18 */ sub sp, sp, #9, lsl #12;
    /* 0x560e1c */ sub sp, sp, #0x510;
    /* 0x560e20 */ mrs x8, tpidr_el0;
    /* 0x560e24 */ mov w0, #0x94e8;
    _Znwm();
    memset();
    memset();
    memset();
    memset();
    memset();
    memset();
    memset();
    memset();
    memset();
    memcpy();
    return x0;
    __stack_chk_fail();
}

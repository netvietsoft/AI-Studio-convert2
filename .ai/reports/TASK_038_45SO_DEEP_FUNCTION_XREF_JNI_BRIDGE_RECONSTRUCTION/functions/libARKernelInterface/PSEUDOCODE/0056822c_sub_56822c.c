// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56822c
// Recovered Name: sub_56822c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56822c | Size: 1880 bytes | SHA256: 6d9b98b9c443b38732b89c884f4d4caf5f29914045ca5839282b38a775aca865
// Callers: 0 | Callees: 3 | Imports: 3

// Dynamic Registration: nativeCreateInstance()J (table at 0x10ccc50)
// Calls external APIs: _Znwm, __stack_chk_fail, memset

jlong sub_56822c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 470 instructions
    /* 0x56822c */ stp x29, x30, [sp, #-0x60]!;
    /* 0x568230 */ stp x28, x27, [sp, #0x10];
    /* 0x568234 */ stp x26, x25, [sp, #0x20];
    /* 0x568238 */ stp x24, x23, [sp, #0x30];
    /* 0x56823c */ stp x22, x21, [sp, #0x40];
    /* 0x568240 */ stp x20, x19, [sp, #0x50];
    /* 0x568244 */ mov x29, sp;
    /* 0x568248 */ sub sp, sp, #4, lsl #12;
    /* 0x56824c */ sub sp, sp, #0xd10;
    /* 0x568250 */ mrs x8, tpidr_el0;
    /* 0x568254 */ add x21, sp, #0x10;
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
    memset();
    memset();
    memset();
    memset();
    memset();
    memset();
    memset();
    memset();
    memset();
    memset();
    memset();
    memset();
    memset();
    memset();
    memset();
    memset();
    memset();
    memset();
    memset();
    memset();
    memset();
    memset();
    memset();
    memset();
    memset();
    memset();
    memset();
    memset();
    memset();
    memset();
    memset();
    memset();
    sub_568984();
    sub_568ae4();
    return x0;
    sub_568ae4();
    sub_1042be4();
    __stack_chk_fail();
}

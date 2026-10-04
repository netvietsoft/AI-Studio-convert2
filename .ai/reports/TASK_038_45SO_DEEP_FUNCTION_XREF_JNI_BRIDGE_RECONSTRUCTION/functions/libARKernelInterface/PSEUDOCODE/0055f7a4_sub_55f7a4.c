// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x55f7a4
// Recovered Name: sub_55f7a4
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x55f7a4 | Size: 416 bytes | SHA256: 356cab963abaec17fcd79f4e114cd4adc61961e5ce455d8c58954ad2c8a60cc5
// Callers: 0 | Callees: 5 | Imports: 5

// Dynamic Registration: nativeCreateInstance()J (table at 0x10cc320)
// Calls external APIs: _ZdlPv, _Znwm, __stack_chk_fail, memcpy, memset

jlong sub_55f7a4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 104 instructions
    /* 0x55f7a4 */ stp x29, x30, [sp, #-0x40]!;
    /* 0x55f7a8 */ stp x28, x23, [sp, #0x10];
    /* 0x55f7ac */ stp x22, x21, [sp, #0x20];
    /* 0x55f7b0 */ stp x20, x19, [sp, #0x30];
    /* 0x55f7b4 */ mov x29, sp;
    /* 0x55f7b8 */ sub sp, sp, #0x12, lsl #12;
    /* 0x55f7bc */ sub sp, sp, #0x2b0;
    /* 0x55f7c0 */ mrs x21, tpidr_el0;
    /* 0x55f7c4 */ mov w0, #0x22a8;
    /* 0x55f7c8 */ ldr x8, [x21, #0x28];
    /* 0x55f7cc */ movk w0, #1, lsl #16;
    _Znwm();
    memset();
    sub_55f944();
    memset();
    sub_55f944();
    memcpy();
    sub_560b60();
    sub_560c24();
    sub_560c24();
    sub_560c24();
    sub_560c24();
    sub_560c24();
    sub_55fd94();
    return x0;
    _ZdlPv();
    sub_55fd94();
    sub_1042be4();
    __stack_chk_fail();
}

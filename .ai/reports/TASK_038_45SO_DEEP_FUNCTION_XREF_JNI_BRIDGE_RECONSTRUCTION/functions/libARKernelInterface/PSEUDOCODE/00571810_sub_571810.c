// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x571810
// Recovered Name: sub_571810
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x571810 | Size: 1876 bytes | SHA256: 9059def1ad9c08a69684abb4647e7c36727ddaf48544d77bb2ab3777bd9acd31
// Callers: 0 | Callees: 2 | Imports: 3

// Dynamic Registration: nativeCreateInstance()J (table at 0x10cd778)
// Calls external APIs: _ZdlPv, _Znwm, __stack_chk_fail

jlong sub_571810(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 469 instructions
    /* 0x571810 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x571814 */ str x28, [sp, #0x10];
    /* 0x571818 */ stp x20, x19, [sp, #0x20];
    /* 0x57181c */ mov x29, sp;
    /* 0x571820 */ sub sp, sp, #0x380;
    /* 0x571824 */ mrs x20, tpidr_el0;
    /* 0x571828 */ mov w0, #0xea8;
    /* 0x57182c */ ldr x8, [x20, #0x28];
    /* 0x571830 */ stur x8, [x29, #-8];
    _Znwm();
    /* 0x571838 */ mov x19, x0;
    sub_571f64();
    return x0;
    _ZdlPv();
    sub_1042be4();
    __stack_chk_fail();
}

// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57b808
// Recovered Name: sub_57b808
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57b808 | Size: 2164 bytes | SHA256: e06e94c0a8261f310611f0636c8ab36374f7e68bb8569ccfd07570ed588579a3
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nativeCreateInstance()J (table at 0x10ce960)
// Calls external APIs: _Znwm, __stack_chk_fail

jlong sub_57b808(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 541 instructions
    /* 0x57b808 */ stp x29, x30, [sp, #-0x40]!;
    /* 0x57b80c */ stp x28, x23, [sp, #0x10];
    /* 0x57b810 */ stp x22, x21, [sp, #0x20];
    /* 0x57b814 */ stp x20, x19, [sp, #0x30];
    /* 0x57b818 */ mov x29, sp;
    /* 0x57b81c */ sub sp, sp, #0x3d0;
    /* 0x57b820 */ mrs x19, tpidr_el0;
    /* 0x57b824 */ mov w0, #0x658;
    /* 0x57b828 */ sub x23, x29, #0x80;
    /* 0x57b82c */ ldr x8, [x19, #0x28];
    /* 0x57b830 */ add x22, sp, #0x240;
    _Znwm();
    return x0;
    __stack_chk_fail();
}

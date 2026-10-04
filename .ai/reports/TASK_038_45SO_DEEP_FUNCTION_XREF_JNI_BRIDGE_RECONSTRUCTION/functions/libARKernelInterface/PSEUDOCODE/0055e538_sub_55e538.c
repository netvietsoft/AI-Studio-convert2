// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x55e538
// Recovered Name: sub_55e538
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x55e538 | Size: 2224 bytes | SHA256: dc15714e3eed80a97c34f686ab510cbb29d21fa7a8a3bbbd0442be16cc01fa86
// Callers: 0 | Callees: 0 | Imports: 3

// Dynamic Registration: nativeCreateInstance()J (table at 0x10cc1b8)
// Calls external APIs: _Znwm, __stack_chk_fail, memcpy

jlong sub_55e538(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 556 instructions
    /* 0x55e538 */ stp x29, x30, [sp, #-0x40]!;
    /* 0x55e53c */ str x28, [sp, #0x10];
    /* 0x55e540 */ stp x22, x21, [sp, #0x20];
    /* 0x55e544 */ stp x20, x19, [sp, #0x30];
    /* 0x55e548 */ mov x29, sp;
    /* 0x55e54c */ sub sp, sp, #0xb50;
    /* 0x55e550 */ mrs x20, tpidr_el0;
    /* 0x55e554 */ mov w0, #0xc98;
    /* 0x55e558 */ ldr x8, [x20, #0x28];
    /* 0x55e55c */ stur x8, [x29, #-8];
    _Znwm();
    memcpy();
    memcpy();
    memcpy();
    memcpy();
    memcpy();
    memcpy();
    memcpy();
    memcpy();
    memcpy();
    memcpy();
    return x0;
    __stack_chk_fail();
    return x0;
}

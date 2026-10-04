// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57b144
// Recovered Name: sub_57b144
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57b144 | Size: 148 bytes | SHA256: ddfb8e70772f685a8011caaf1b0e64816f5e48507511857a16fbd1ac639f8dd0
// Callers: 0 | Callees: 0 | Imports: 4

// Dynamic Registration: nativeCreateInstance()J (table at 0x10ce798)
// Calls external APIs: _Znwm, __stack_chk_fail, memcpy, memset

jlong sub_57b144(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 37 instructions
    /* 0x57b144 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x57b148 */ stp x28, x21, [sp, #0x10];
    /* 0x57b14c */ stp x20, x19, [sp, #0x20];
    /* 0x57b150 */ mov x29, sp;
    /* 0x57b154 */ sub sp, sp, #2, lsl #12;
    /* 0x57b158 */ sub sp, sp, #0xa90;
    /* 0x57b15c */ mrs x20, tpidr_el0;
    /* 0x57b160 */ mov w0, #0x2a90;
    /* 0x57b164 */ ldr x8, [x20, #0x28];
    /* 0x57b168 */ stur x8, [x29, #-8];
    _Znwm();
    memset();
    memcpy();
    return x0;
    __stack_chk_fail();
}

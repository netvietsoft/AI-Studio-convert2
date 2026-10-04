// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x565adc
// Recovered Name: sub_565adc
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x565adc | Size: 1484 bytes | SHA256: bf5de88d715c88bb1ea254901e1479614a2d09fecf9a0f15f724c7baf2da8de2
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nativeCreateInstance()J (table at 0x10cc800)
// Calls external APIs: _Znwm, __stack_chk_fail

jlong sub_565adc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 371 instructions
    /* 0x565adc */ stp x29, x30, [sp, #-0x30]!;
    /* 0x565ae0 */ str x28, [sp, #0x10];
    /* 0x565ae4 */ stp x20, x19, [sp, #0x20];
    /* 0x565ae8 */ mov x29, sp;
    /* 0x565aec */ sub sp, sp, #0x1f0;
    /* 0x565af0 */ mrs x19, tpidr_el0;
    /* 0x565af4 */ mov w0, #0x478;
    /* 0x565af8 */ add x20, sp, #0xb0;
    /* 0x565afc */ ldr x8, [x19, #0x28];
    /* 0x565b00 */ stur x8, [x29, #-8];
    _Znwm();
    return x0;
    __stack_chk_fail();
}

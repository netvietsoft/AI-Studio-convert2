// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xc036a8
// Recovered Name: sub_c036a8
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xc036a8 | Size: 140 bytes | SHA256: 7c9b3e887527bd66a57c16ce69014a2950b80ac8295599a2ad8e03765a1b9f85
// Callers: 0 | Callees: 2 | Imports: 2

// Calls external APIs: __stack_chk_fail, memcpy
// Strings referenced:
//   "GPInstanceSegmentData"

void sub_c036a8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 35 instructions
    /* 0xc036a8 */ stp x29, x30, [sp, #0xb0];
    /* 0xc036ac */ stp x20, x19, [sp, #0xc0];
    /* 0xc036b0 */ add x29, sp, #0xb0;
    /* 0xc036b4 */ mrs x19, tpidr_el0;
    /* 0xc036b8 */ adrp x1, #0x10a4000;
    /* 0xc036bc */ add x1, x1, #0xd90;
    /* 0xc036c0 */ ldr x8, [x19, #0x28];
    /* 0xc036c4 */ add x0, sp, #0x28;
    /* 0xc036c8 */ mov w2, #0x80;
    /* 0xc036cc */ stur x8, [x29, #-8];
    memcpy();
    sub_d94250();
    sub_59e3a4();
    return x0;
    __stack_chk_fail();
}

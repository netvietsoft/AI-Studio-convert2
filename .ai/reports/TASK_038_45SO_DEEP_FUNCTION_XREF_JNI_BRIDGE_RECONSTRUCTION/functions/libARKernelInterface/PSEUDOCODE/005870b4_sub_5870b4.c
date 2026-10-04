// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5870b4
// Recovered Name: sub_5870b4
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x5870b4 | Size: 868 bytes | SHA256: 57f0c2fbf4751205b56b20378390a26e40e2017697d9f2ef81097fd5ce481ce0
// Callers: 0 | Callees: 1 | Imports: 1

// Calls external APIs: __stack_chk_fail
// Strings referenced:
//   "bColorWork"
//   "blur"
//   "com/meitu/mtlab/arkernelinterface/interaction/ARKernelTextInteraction$ARKernelTextGlowConfig"
//   "containMask"
//   "editable"

void sub_5870b4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 217 instructions
    /* 0x5870b4 */ stp x29, x30, [sp, #0x60];
    /* 0x5870b8 */ stp x28, x27, [sp, #0x70];
    /* 0x5870bc */ stp x26, x25, [sp, #0x80];
    /* 0x5870c0 */ stp x24, x23, [sp, #0x90];
    /* 0x5870c4 */ stp x22, x21, [sp, #0xa0];
    /* 0x5870c8 */ stp x20, x19, [sp, #0xb0];
    /* 0x5870cc */ add x29, sp, #0x60;
    /* 0x5870d0 */ mrs x25, tpidr_el0;
    /* 0x5870d4 */ ldr x8, [x25, #0x28];
    /* 0x5870d8 */ str x8, [sp, #0x28];
    /* 0x5870dc */ cbz x2, #0x5873c4;
    return x0;
    sub_581efc();
    __stack_chk_fail();
}

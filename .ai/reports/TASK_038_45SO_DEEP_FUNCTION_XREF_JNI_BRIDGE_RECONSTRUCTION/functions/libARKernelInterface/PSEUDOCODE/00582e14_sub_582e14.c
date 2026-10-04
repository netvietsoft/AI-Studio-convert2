// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x582e14
// Recovered Name: sub_582e14
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x582e14 | Size: 276 bytes | SHA256: abbf830cb95026786de20e8eb782cb0f3c64605e6e629de032920b8450f10394
// Callers: 0 | Callees: 1 | Imports: 0

// Dynamic Registration: nativeGetTextFuncStructVector(J)[Lcom/meitu/mtlab/arkernelinterface/interaction/ARKernelTextInteraction; (table at 0x10cf710)
// Strings referenced:
//   "com/meitu/mtlab/arkernelinterface/interaction/ARKernelTextInteraction"

jlong sub_582e14(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 69 instructions
    /* 0x582e14 */ stp x29, x30, [sp, #-0x40]!;
    /* 0x582e18 */ stp x24, x23, [sp, #0x10];
    /* 0x582e1c */ stp x22, x21, [sp, #0x20];
    /* 0x582e20 */ stp x20, x19, [sp, #0x30];
    /* 0x582e24 */ mov x29, sp;
    /* 0x582e28 */ cbz x2, #0x582f0c;
    /* 0x582e2c */ ldr x8, [x2, #0xbd0];
    /* 0x582e30 */ ldr x9, [x2, #0xbd8];
    /* 0x582e34 */ mov x20, x2;
    /* 0x582e38 */ cmp x8, x9;
    /* 0x582e3c */ b.eq #0x582f0c;
    sub_57e928();
    return x0;
}

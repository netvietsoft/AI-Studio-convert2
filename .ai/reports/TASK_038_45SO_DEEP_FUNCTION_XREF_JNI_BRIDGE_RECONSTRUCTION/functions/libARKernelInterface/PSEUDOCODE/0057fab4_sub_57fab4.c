// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57fab4
// Recovered Name: sub_57fab4
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x57fab4 | Size: 844 bytes | SHA256: b05da69182b5771089c06417dbd704589737cd5a2c9b02f7658be64dd9cc99e8
// Callers: 0 | Callees: 1 | Imports: 0

// Strings referenced:
//   "()V"
//   "<init>"
//   "bColorWork"
//   "blur"
//   "com/meitu/mtlab/arkernelinterface/interaction/ARKernelTextInteraction$ARKernelTextShadowConfig"

void sub_57fab4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 211 instructions
    /* 0x57fab4 */ stp x29, x30, [sp, #0x30];
    /* 0x57fab8 */ stp x28, x27, [sp, #0x40];
    /* 0x57fabc */ stp x26, x25, [sp, #0x50];
    /* 0x57fac0 */ stp x24, x23, [sp, #0x60];
    /* 0x57fac4 */ stp x22, x21, [sp, #0x70];
    /* 0x57fac8 */ stp x20, x19, [sp, #0x80];
    /* 0x57facc */ add x29, sp, #0x30;
    /* 0x57fad0 */ cbz x1, #0x57fdd8;
    /* 0x57fad4 */ ldr x8, [x0];
    /* 0x57fad8 */ mov x20, x1;
    /* 0x57fadc */ adrp x1, #0x1e5000;
    sub_55d808();
    return x0;
}

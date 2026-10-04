// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57fe04
// Recovered Name: sub_57fe04
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x57fe04 | Size: 844 bytes | SHA256: f908421412c0ab0451d4884b2d2228f1a027544d7b5101353ec97d4ac79d4a60
// Callers: 0 | Callees: 1 | Imports: 0

// Strings referenced:
//   "()V"
//   "<init>"
//   "bColorWork"
//   "blur"
//   "com/meitu/mtlab/arkernelinterface/interaction/ARKernelTextInteraction$ARKernelTextGlowConfig"

void sub_57fe04(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 211 instructions
    /* 0x57fe04 */ stp x29, x30, [sp, #0x30];
    /* 0x57fe08 */ stp x28, x27, [sp, #0x40];
    /* 0x57fe0c */ stp x26, x25, [sp, #0x50];
    /* 0x57fe10 */ stp x24, x23, [sp, #0x60];
    /* 0x57fe14 */ stp x22, x21, [sp, #0x70];
    /* 0x57fe18 */ stp x20, x19, [sp, #0x80];
    /* 0x57fe1c */ add x29, sp, #0x30;
    /* 0x57fe20 */ cbz x1, #0x580128;
    /* 0x57fe24 */ ldr x8, [x0];
    /* 0x57fe28 */ mov x20, x1;
    /* 0x57fe2c */ adrp x1, #0x1da000;
    sub_55d808();
    return x0;
}

// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xa8f3ac
// Recovered Name: sub_a8f3ac
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xa8f3ac | Size: 1652 bytes | SHA256: a2ea7aaa0f61249bc055148785515a4df816a0e5e672f0674f0bdc0656f4b5a1
// Callers: 0 | Callees: 5 | Imports: 2

// Calls external APIs: glActiveTexture, glBindTexture
// Strings referenced:
//   "s_FaceMaskMap"
//   "s_FillHeadMaskMap"
//   "s_FillNoseMaskMap"
//   "s_additionalMap"
//   "s_additionalMouthAlphaMap"

void sub_a8f3ac(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 413 instructions
    /* 0xa8f3ac */ stp x29, x30, [sp, #-0x50]!;
    /* 0xa8f3b0 */ str x25, [sp, #0x10];
    /* 0xa8f3b4 */ stp x24, x23, [sp, #0x20];
    /* 0xa8f3b8 */ stp x22, x21, [sp, #0x30];
    /* 0xa8f3bc */ stp x20, x19, [sp, #0x40];
    /* 0xa8f3c0 */ mov x29, sp;
    /* 0xa8f3c4 */ ldr x8, [x0];
    /* 0xa8f3c8 */ mov x19, x0;
    /* 0xa8f3cc */ ldr x8, [x8, #0x40];
    /* 0xa8f3d0 */ blr x8;
    /* 0xa8f3d4 */ tbz w0, #0, #0xa8f420;
    glActiveTexture();
    sub_69b7c4();
    glBindTexture();
    glActiveTexture();
    sub_69b7c4();
    glBindTexture();
    glActiveTexture();
    sub_69b7c4();
    glBindTexture();
    glActiveTexture();
    sub_69b7c4();
    glBindTexture();
    sub_69add8();
    glActiveTexture();
    sub_69b7c4();
    glBindTexture();
    sub_69add8();
    sub_69add8();
    sub_69add8();
    glActiveTexture();
    sub_69b7c4();
    glBindTexture();
    sub_a8fa20();
    sub_69add8();
    sub_69add8();
    glActiveTexture();
    sub_69b7c4();
    glBindTexture();
    glActiveTexture();
    sub_69b7c4();
    glBindTexture();
    glActiveTexture();
    sub_69b7c4();
    glBindTexture();
    glActiveTexture();
    sub_69b7c4();
    glBindTexture();
    sub_a8f2ec();
    sub_69add8();
    glActiveTexture();
    sub_69b7c4();
    glBindTexture();
    sub_c394fc();
    glActiveTexture();
    sub_69b7c4();
    glBindTexture();
    glActiveTexture();
    sub_69b7c4();
    glBindTexture();
    glActiveTexture();
    sub_69b7c4();
    glBindTexture();
    return x0;
}

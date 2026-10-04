// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x98e474
// Recovered Name: sub_98e474
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x98e474 | Size: 1700 bytes | SHA256: cd795c20d25fe59de03dab03ae605086dbfa11b1498d1d83b26ba11d36fd337b
// Callers: 0 | Callees: 4 | Imports: 9

// Calls external APIs: __android_log_print, __stack_chk_fail, glActiveTexture, glBindFramebuffer, glBindTexture, glCheckFramebufferStatus, glDrawArrays, glFramebufferTexture2D, glViewport
// Strings referenced:
//   "PostProcessPart: RenderGaussian error: %d, width: %d, height: %d"
//   "PostProcessPart: RenderGaussian error: m_pGaussianProgram is nullptr"
//   "PostProcessPart: RenderGaussian error: pTargetMaskTexture or pTempTexture is nullptr"
//   "a_position"
//   "a_texcoord"

void sub_98e474(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 425 instructions
    /* 0x98e474 */ stp x29, x30, [sp, #0xa0];
    /* 0x98e478 */ stp x28, x27, [sp, #0xb0];
    /* 0x98e47c */ stp x26, x25, [sp, #0xc0];
    /* 0x98e480 */ stp x24, x23, [sp, #0xd0];
    /* 0x98e484 */ stp x22, x21, [sp, #0xe0];
    /* 0x98e488 */ stp x20, x19, [sp, #0xf0];
    /* 0x98e48c */ add x29, sp, #0xa0;
    /* 0x98e490 */ mrs x10, tpidr_el0;
    /* 0x98e494 */ ldr x8, [x10, #0x28];
    /* 0x98e498 */ stur x8, [x29, #-0x18];
    /* 0x98e49c */ ldr x8, [x1];
    sub_69b7cc();
    sub_69b7d4();
    sub_69b7cc();
    sub_69b7d4();
    glBindFramebuffer();
    glViewport();
    sub_69b7c4();
    glFramebufferTexture2D();
    glCheckFramebufferStatus();
    sub_5a6b20();
    __android_log_print();
    glActiveTexture();
    sub_69b7c4();
    glBindTexture();
    glDrawArrays();
    sub_69b7c4();
    glFramebufferTexture2D();
    glCheckFramebufferStatus();
    sub_5a6b20();
    __android_log_print();
    glActiveTexture();
    sub_69b7c4();
    glBindTexture();
    glDrawArrays();
    glBindFramebuffer();
    return x0;
    __stack_chk_fail();
}

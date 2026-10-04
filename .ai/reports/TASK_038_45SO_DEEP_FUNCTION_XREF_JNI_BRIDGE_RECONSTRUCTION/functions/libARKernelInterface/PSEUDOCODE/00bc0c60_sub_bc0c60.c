// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xbc0c60
// Recovered Name: sub_bc0c60
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xbc0c60 | Size: 1592 bytes | SHA256: 6487024a2471874414a344968bb1aebbc8b3763270895767ba5a0c482d91ce85
// Callers: 0 | Callees: 13 | Imports: 8

// Calls external APIs: _ZNSt6__ndk1plIcNS_11char_traitsIcEENS_9allocatorIcEEEENS_12basic_stringIT_T0_T1_EEPKS6_RKS9_, _ZdlPv, __android_log_print, __stack_chk_fail, glActiveTexture, glBindTexture, glDrawArrays, glViewport
// Strings referenced:
//   "FaceMeshService::filterBlurFloatTexture: float color buffer not supported"
//   "FaceMeshService::filterBlurFloatTexture: invalid texture"
//   "MEITU_GAUSSIAN_RADIUS 7"
//   "MEITU_HORIZONTAL_GAUSSIAN,"
//   "MEITU_VERTICAL_GAUSSIAN,"

void sub_bc0c60(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 398 instructions
    /* 0xbc0c60 */ stp x29, x30, [sp, #0x160];
    /* 0xbc0c64 */ stp x28, x27, [sp, #0x170];
    /* 0xbc0c68 */ stp x26, x25, [sp, #0x180];
    /* 0xbc0c6c */ stp x24, x23, [sp, #0x190];
    /* 0xbc0c70 */ stp x22, x21, [sp, #0x1a0];
    /* 0xbc0c74 */ stp x20, x19, [sp, #0x1b0];
    /* 0xbc0c78 */ add x29, sp, #0x160;
    /* 0xbc0c7c */ mrs x27, tpidr_el0;
    /* 0xbc0c80 */ ldr x8, [x27, #0x28];
    /* 0xbc0c84 */ stur x8, [x29, #-0x38];
    /* 0xbc0c88 */ cbz x1, #0xbc11b4;
    sub_69add8();
    sub_c40be0();
    sub_69b7cc();
    sub_69b7d4();
    sub_bc67b4();
    sub_c41220();
    sub_69a5a8();
    sub_fc2a84();
    glViewport();
    sub_58f19c();
    _ZNSt6__ndk1plIcNS_11char_traitsIcEENS_9allocatorIcEEEENS_12basic_stringIT_T0_T1_EEPKS6_RKS9_();
    _ZdlPv();
    glActiveTexture();
    sub_69b7c4();
    glBindTexture();
    glDrawArrays();
    glViewport();
    _ZNSt6__ndk1plIcNS_11char_traitsIcEENS_9allocatorIcEEEENS_12basic_stringIT_T0_T1_EEPKS6_RKS9_();
    _ZdlPv();
    glActiveTexture();
    sub_69b7c4();
    glBindTexture();
    glDrawArrays();
    sub_bc68d0();
    sub_c40e68();
    _ZdlPv();
    sub_5a6b20();
    __android_log_print();
    return x0;
    __stack_chk_fail();
}

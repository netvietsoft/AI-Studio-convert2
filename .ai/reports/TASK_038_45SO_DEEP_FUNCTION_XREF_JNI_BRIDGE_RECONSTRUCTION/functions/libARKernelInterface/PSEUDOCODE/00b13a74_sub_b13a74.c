// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xb13a74
// Recovered Name: sub_b13a74
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xb13a74 | Size: 1080 bytes | SHA256: 0d1768902f3ddfac111ef6c8e7c3962c15b860a5bab461ca3b241bba07783b68
// Callers: 0 | Callees: 10 | Imports: 8

// Calls external APIs: _ZdlPv, __stack_chk_fail, glActiveTexture, glBindTexture, glClear, glDisable, glDrawElements, glEnable
// Strings referenced:
//   "a_position"
//   "a_texcoord"
//   "s_faceSegmentMask"
//   "s_meshTex"
//   "s_normalTex"

void sub_b13a74(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 270 instructions
    /* 0xb13a74 */ ldr x26, [x21, #8];
    /* 0xb13a78 */ mov x0, x26;
    sub_6987b8();
    /* 0xb13a80 */ ldr x8, [x0];
    /* 0xb13a84 */ mov w1, #1;
    /* 0xb13a88 */ mov x21, x0;
    /* 0xb13a8c */ ldr x8, [x8, #0x28];
    /* 0xb13a90 */ blr x8;
    /* 0xb13a94 */ mov x0, x26;
    sub_697fb4();
    /* 0xb13a9c */ mov x0, x26;
    sub_6981a0();
    glEnable();
    glClear();
    glActiveTexture();
    sub_698574();
    sub_69b7c4();
    glBindTexture();
    glActiveTexture();
    sub_69b7c4();
    glBindTexture();
    glActiveTexture();
    sub_69b7c4();
    glBindTexture();
    sub_c17744();
    sub_c17574();
    glActiveTexture();
    sub_69b7c4();
    glBindTexture();
    glDrawElements();
    sub_698448();
    sub_697894();
    glDisable();
    _ZdlPv();
    return x0;
    sub_7719ac();
    __stack_chk_fail();
}

// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x623ed8
// Recovered Name: sub_623ed8
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x623ed8 | Size: 652 bytes | SHA256: 4bda2d63dbe3dc33eb91e3b06245af1895c9a12d61ae1130f64d9f9213da4085
// Callers: 0 | Callees: 8 | Imports: 3

// Calls external APIs: __stack_chk_fail, glActiveTexture, glBindTexture
// Strings referenced:
//   "s_faceSegmentMask"
//   "s_makeupAdaptMask"
//   "s_materialMap%d"
//   "s_srcMap"
//   "u_enableMakeupAdapt"

void sub_623ed8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 163 instructions
    /* 0x623ed8 */ stp x29, x30, [sp, #0x90];
    /* 0x623edc */ stp x26, x25, [sp, #0xa0];
    /* 0x623ee0 */ stp x24, x23, [sp, #0xb0];
    /* 0x623ee4 */ stp x22, x21, [sp, #0xc0];
    /* 0x623ee8 */ stp x20, x19, [sp, #0xd0];
    /* 0x623eec */ add x29, sp, #0x90;
    /* 0x623ef0 */ mrs x24, tpidr_el0;
    /* 0x623ef4 */ mov x19, x0;
    /* 0x623ef8 */ mov w0, #0x84c0;
    /* 0x623efc */ ldr x8, [x24, #0x28];
    /* 0x623f00 */ mov x20, x2;
    glActiveTexture();
    sub_698574();
    sub_69b7c4();
    glBindTexture();
    glActiveTexture();
    sub_c17744();
    sub_69b7c4();
    glBindTexture();
    sub_c162e4();
    sub_c38b3c();
    sub_69add8();
    glActiveTexture();
    sub_69b7c4();
    glBindTexture();
    sub_626f94();
    glActiveTexture();
    sub_69b7c4();
    glBindTexture();
    sub_624164();
    return x0;
    __stack_chk_fail();
}

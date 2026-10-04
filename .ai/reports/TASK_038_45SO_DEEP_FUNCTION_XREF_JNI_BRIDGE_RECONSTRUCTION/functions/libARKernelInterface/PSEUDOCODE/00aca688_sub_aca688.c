// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xaca688
// Recovered Name: sub_aca688
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xaca688 | Size: 908 bytes | SHA256: 1defd26f3b2832e3719bc81d4bb6b99b2003d3d534328e4a608799e9218e9677
// Callers: 0 | Callees: 3 | Imports: 7

// Calls external APIs: _ZdlPv, __stack_chk_fail, glActiveTexture, glBindFramebuffer, glBindTexture, glDrawArrays, glViewport
// Strings referenced:
//   "HLVig"
//   "blurTex"
//   "grayScale"
//   "mvpMatrix"
//   "position"

void sub_aca688(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 227 instructions
    /* 0xaca688 */ stp x29, x30, [sp, #0xf8];
    /* 0xaca68c */ str x28, [sp, #0x108];
    /* 0xaca690 */ stp x24, x23, [sp, #0x110];
    /* 0xaca694 */ stp x22, x21, [sp, #0x120];
    /* 0xaca698 */ stp x20, x19, [sp, #0x130];
    /* 0xaca69c */ add x29, sp, #0xf8;
    /* 0xaca6a0 */ mrs x23, tpidr_el0;
    /* 0xaca6a4 */ add x9, x0, w3, sxtw #2;
    /* 0xaca6a8 */ mov x19, x0;
    /* 0xaca6ac */ ldr x8, [x23, #0x28];
    /* 0xaca6b0 */ mov w21, w1;
    glBindFramebuffer();
    sub_58f19c();
    _ZdlPv();
    glViewport();
    sub_fc2a84();
    glActiveTexture();
    glBindTexture();
    glActiveTexture();
    glBindTexture();
    sub_bbbcb0();
    glDrawArrays();
    return x0;
    __stack_chk_fail();
}

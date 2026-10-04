// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xacb848
// Recovered Name: sub_acb848
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xacb848 | Size: 992 bytes | SHA256: 17e864547215a30bedf5393a77dcdf6656eb88e555de9b8ff711f4781eb36e6b
// Callers: 0 | Callees: 2 | Imports: 7

// Calls external APIs: _ZdlPv, __stack_chk_fail, glActiveTexture, glBindFramebuffer, glBindTexture, glDrawArrays, glViewport
// Strings referenced:
//   "alpha"
//   "blurTex"
//   "mvpMatrix"
//   "position"
//   "softTex"

void sub_acb848(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 248 instructions
    /* 0xacb848 */ stp x29, x30, [sp, #0xf0];
    /* 0xacb84c */ stp x28, x25, [sp, #0x100];
    /* 0xacb850 */ stp x24, x23, [sp, #0x110];
    /* 0xacb854 */ stp x22, x21, [sp, #0x120];
    /* 0xacb858 */ stp x20, x19, [sp, #0x130];
    /* 0xacb85c */ add x29, sp, #0xf0;
    /* 0xacb860 */ mrs x24, tpidr_el0;
    /* 0xacb864 */ add x9, x0, w4, sxtw #2;
    /* 0xacb868 */ mov x19, x0;
    /* 0xacb86c */ ldr x8, [x24, #0x28];
    /* 0xacb870 */ mov w22, w1;
    glBindFramebuffer();
    sub_58f19c();
    _ZdlPv();
    glViewport();
    sub_fc2a84();
    glActiveTexture();
    glBindTexture();
    glActiveTexture();
    glBindTexture();
    glActiveTexture();
    glBindTexture();
    glDrawArrays();
    return x0;
    __stack_chk_fail();
}

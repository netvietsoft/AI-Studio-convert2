// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x874208
// Recovered Name: sub_874208
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x874208 | Size: 1044 bytes | SHA256: 0f3544ded6287c8a6d9f48a3862df2b47ce62270250df0f3f2b0047d5968699f
// Callers: 0 | Callees: 3 | Imports: 8

// Calls external APIs: __stack_chk_fail, glActiveTexture, glBindTexture, glClear, glClearColor, glColorMask, glDrawArrays, glViewport
// Strings referenced:
//   "343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899N8arkernel8CoreSuitE"
//   "blurRadius"
//   "invResolution"
//   "mvpMatrix"
//   "position"

void sub_874208(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 261 instructions
    /* 0x874208 */ stp x29, x30, [sp, #0xe0];
    /* 0x87420c */ stp x28, x23, [sp, #0xf0];
    /* 0x874210 */ stp x22, x21, [sp, #0x100];
    /* 0x874214 */ stp x20, x19, [sp, #0x110];
    /* 0x874218 */ add x29, sp, #0xe0;
    /* 0x87421c */ mrs x23, tpidr_el0;
    /* 0x874220 */ add x1, x0, #0x4d8;
    /* 0x874224 */ mov x19, x0;
    /* 0x874228 */ ldr x8, [x23, #0x28];
    /* 0x87422c */ stur x8, [x29, #-0x18];
    sub_874130();
    sub_fc2a84();
    glViewport();
    glClearColor();
    glClear();
    glActiveTexture();
    sub_69b7c4();
    glBindTexture();
    glDrawArrays();
    sub_874130();
    glActiveTexture();
    sub_69b7c4();
    glBindTexture();
    glDrawArrays();
    glColorMask();
    return x0;
    __stack_chk_fail();
}

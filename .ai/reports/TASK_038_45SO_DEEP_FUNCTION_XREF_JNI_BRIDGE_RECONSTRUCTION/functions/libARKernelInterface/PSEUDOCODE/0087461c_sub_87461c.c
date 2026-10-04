// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x87461c
// Recovered Name: sub_87461c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x87461c | Size: 1004 bytes | SHA256: 0fbb02a16a3270c2a26b863af9583fda5cb028b3f73f68ec8833a76d988caa07
// Callers: 0 | Callees: 3 | Imports: 8

// Calls external APIs: __stack_chk_fail, glActiveTexture, glBindTexture, glClear, glClearColor, glColorMask, glDrawElements, glViewport
// Strings referenced:
//   "blurRadius"
//   "invResolution"
//   "mvpMatrix"
//   "position"
//   "s_texture"

void sub_87461c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 251 instructions
    /* 0x87461c */ stp x29, x30, [sp, #0xa0];
    /* 0x874620 */ str x27, [sp, #0xb0];
    /* 0x874624 */ stp x26, x25, [sp, #0xc0];
    /* 0x874628 */ stp x24, x23, [sp, #0xd0];
    /* 0x87462c */ stp x22, x21, [sp, #0xe0];
    /* 0x874630 */ stp x20, x19, [sp, #0xf0];
    /* 0x874634 */ add x29, sp, #0xa0;
    /* 0x874638 */ mrs x26, tpidr_el0;
    /* 0x87463c */ mov x23, x1;
    /* 0x874640 */ add x1, x0, #0x4d8;
    /* 0x874644 */ ldr x8, [x26, #0x28];
    sub_874130();
    sub_fc2a84();
    glViewport();
    glClearColor();
    glClear();
    glActiveTexture();
    sub_69b7c4();
    glBindTexture();
    glDrawElements();
    sub_874130();
    glActiveTexture();
    sub_69b7c4();
    glBindTexture();
    glDrawElements();
    glColorMask();
    return x0;
    __stack_chk_fail();
}

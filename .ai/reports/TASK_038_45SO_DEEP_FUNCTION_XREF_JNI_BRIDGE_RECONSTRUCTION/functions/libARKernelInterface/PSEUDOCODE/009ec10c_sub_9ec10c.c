// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x9ec10c
// Recovered Name: sub_9ec10c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x9ec10c | Size: 1468 bytes | SHA256: b6c17500dd47559741eb848722d2cc63c937c55952c7b4cd7a849cfbbd69a62a
// Callers: 0 | Callees: 3 | Imports: 4

// Calls external APIs: __android_log_print, __stack_chk_fail, glDrawArrays, glViewport
// Strings referenced:
//   "343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899N8arkernel8CoreSuitE"
//   "FilterSegmentErosion::FilterToFBO: m_pErosionHProgram is nullptr !"
//   "FilterSegmentErosion::FilterToFBO: m_pErosionVProgram is nullptr !"
//   "FilterSegmentErosion::FilterToFBO: m_pFBOA is nullptr !"
//   "FilterSegmentErosion::FilterToFBO: m_pFBOB is nullptr !"

void sub_9ec10c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 367 instructions
    /* 0x9ec10c */ stp x29, x30, [sp, #0xe0];
    /* 0x9ec110 */ stp x28, x27, [sp, #0xf0];
    /* 0x9ec114 */ stp x26, x25, [sp, #0x100];
    /* 0x9ec118 */ stp x24, x23, [sp, #0x110];
    /* 0x9ec11c */ stp x22, x21, [sp, #0x120];
    /* 0x9ec120 */ stp x20, x19, [sp, #0x130];
    /* 0x9ec124 */ add x29, sp, #0xe0;
    /* 0x9ec128 */ mrs x26, tpidr_el0;
    /* 0x9ec12c */ ldr x8, [x26, #0x28];
    /* 0x9ec130 */ stur x8, [x29, #-0x18];
    /* 0x9ec134 */ ldr x8, [x0, #0x4c8];
    sub_fc2a84();
    glViewport();
    sub_69b76c();
    glDrawArrays();
    glViewport();
    sub_69b76c();
    glDrawArrays();
    sub_5a6b20();
    __android_log_print();
    return x0;
    __stack_chk_fail();
    return x0;
    return x0;
}

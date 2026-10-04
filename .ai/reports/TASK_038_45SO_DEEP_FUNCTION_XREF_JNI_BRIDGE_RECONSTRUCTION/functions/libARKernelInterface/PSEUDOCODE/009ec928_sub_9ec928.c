// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x9ec928
// Recovered Name: sub_9ec928
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x9ec928 | Size: 1568 bytes | SHA256: 178b586e065bc17d00dc1e5e4cef5c95374f0a3933d9241cf6c09890a173e928
// Callers: 0 | Callees: 4 | Imports: 5

// Calls external APIs: _ZdlPv, __android_log_print, __stack_chk_fail, glDrawArrays, glViewport
// Strings referenced:
//   "343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899N8arkernel8CoreSuitE"
//   "FilterSegmentSwell::FilterToFBO: m_pFBOA is nullptr !"
//   "FilterSegmentSwell::FilterToFBO: m_pFBOB is nullptr !"
//   "FilterSegmentSwell::FilterToFBO: m_pRefMaskTextures[0] is nullptr !"
//   "FilterSegmentSwell::FilterToFBO: m_pSwellHProgram is nullptr !"

void sub_9ec928(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 392 instructions
    /* 0x9ec928 */ stp x29, x30, [sp, #0x100];
    /* 0x9ec92c */ stp x28, x23, [sp, #0x110];
    /* 0x9ec930 */ stp x22, x21, [sp, #0x120];
    /* 0x9ec934 */ stp x20, x19, [sp, #0x130];
    /* 0x9ec938 */ add x29, sp, #0x100;
    /* 0x9ec93c */ mrs x23, tpidr_el0;
    /* 0x9ec940 */ ldr x8, [x23, #0x28];
    /* 0x9ec944 */ stur x8, [x29, #-0x18];
    /* 0x9ec948 */ ldr x8, [x0, #0x4c8];
    /* 0x9ec94c */ cbz x8, #0x9ecd6c;
    /* 0x9ec950 */ ldr x8, [x0, #0x4d0];
    sub_fc2a84();
    glViewport();
    sub_69b76c();
    glDrawArrays();
    sub_58f19c();
    _ZdlPv();
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

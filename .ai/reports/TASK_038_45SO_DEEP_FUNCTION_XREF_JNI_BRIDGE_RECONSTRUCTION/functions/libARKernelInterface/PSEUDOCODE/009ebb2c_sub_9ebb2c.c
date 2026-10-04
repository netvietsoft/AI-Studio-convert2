// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x9ebb2c
// Recovered Name: sub_9ebb2c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x9ebb2c | Size: 736 bytes | SHA256: 13dd3205fff2e6f3a847e45efa6cc01c36aa74c886090814d652b5f2a20bb658
// Callers: 0 | Callees: 2 | Imports: 4

// Calls external APIs: __android_log_print, __stack_chk_fail, glDrawArrays, glViewport
// Strings referenced:
//   "343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899N8arkernel8CoreSuitE"
//   "FilterSegmentMaskMix::FilterToFBO: BindTexture failed ! "
//   "FilterSegmentMaskMix::FilterToFBO: program is nullptr !"
//   "MEITU_USE_MASK_TEXTURE"
//   "a_position"

void sub_9ebb2c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 184 instructions
    /* 0x9ebb2c */ stp x29, x30, [sp, #0xd0];
    /* 0x9ebb30 */ stp x28, x23, [sp, #0xe0];
    /* 0x9ebb34 */ stp x22, x21, [sp, #0xf0];
    /* 0x9ebb38 */ stp x20, x19, [sp, #0x100];
    /* 0x9ebb3c */ add x29, sp, #0xd0;
    /* 0x9ebb40 */ mrs x23, tpidr_el0;
    /* 0x9ebb44 */ mov w1, #0x7c;
    /* 0x9ebb48 */ mov x19, x0;
    /* 0x9ebb4c */ ldr x8, [x23, #0x28];
    /* 0x9ebb50 */ stur x8, [x29, #-8];
    /* 0x9ebb54 */ ldr x8, [x0];
    glViewport();
    sub_fc2a84();
    glDrawArrays();
    sub_5a6b20();
    sub_5a6b20();
    __android_log_print();
    return x0;
    __android_log_print();
    __stack_chk_fail();
}

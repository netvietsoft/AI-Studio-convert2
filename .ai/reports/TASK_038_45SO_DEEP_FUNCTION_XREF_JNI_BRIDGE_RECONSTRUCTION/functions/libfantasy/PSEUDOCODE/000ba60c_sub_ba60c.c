// Library: libfantasy.so
// Function ID: libfantasy::0xba60c
// Recovered Name: sub_ba60c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xba60c | Size: 204 bytes | SHA256: 2806ccf12cb61a3b48cb815aac716f5ff178369ca9d5fdf1032e7f009decb935
// Callers: 0 | Callees: 1 | Imports: 3

// Calls external APIs: __emutls_get_address, __stack_chk_fail, vsnprintf

void sub_ba60c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 51 instructions
    /* 0xba60c */ stp x29, x30, [sp, #0x110];
    /* 0xba610 */ str x28, [sp, #0x120];
    /* 0xba614 */ stp x22, x21, [sp, #0x130];
    /* 0xba618 */ stp x20, x19, [sp, #0x140];
    /* 0xba61c */ add x29, sp, #0x110;
    /* 0xba620 */ stp x1, x2, [sp, #0x88];
    /* 0xba624 */ mov x20, x8;
    /* 0xba628 */ mov x9, sp;
    /* 0xba62c */ stp x3, x4, [sp, #0x98];
    /* 0xba630 */ add x9, x9, #0x80;
    /* 0xba634 */ add x10, sp, #0x88;
    __emutls_get_address();
    vsnprintf();
    sub_bad3c();
    return x0;
    __stack_chk_fail();
}

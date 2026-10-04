// Library: libarkernel3.so
// Function ID: libarkernel3::0xce1ed0
// Recovered Name: sub_ce1ed0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xce1ed0 | Size: 628 bytes | SHA256: cd4ae43464fa62c69fdef766261b1adcc9cf891d90753232699d4036ecca1e18
// Callers: 0 | Callees: 2 | Imports: 1

// Calls external APIs: __assert2
// Strings referenced:
//   "/Users/zhichenzhang/meitu/Project/PVGThirdParty/libwebp/src/dec/vp8_dec.c"
//   "br != NULL"
//   "hdr != NULL"
//   "int ParseSegmentHeader(VP8BitReader *, VP8SegmentHeader *, VP8Proba *)"

void sub_ce1ed0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 157 instructions
    /* 0xce1ed0 */ stp x29, x30, [sp, #0x30];
    /* 0xce1ed4 */ add x29, sp, #0x30;
    /* 0xce1ed8 */ stur x0, [x29, #-8];
    /* 0xce1edc */ stur x1, [x29, #-0x10];
    /* 0xce1ee0 */ str x2, [sp, #0x18];
    /* 0xce1ee4 */ ldur x8, [x29, #-8];
    /* 0xce1ee8 */ cbz x8, #0xce1ef4;
    /* 0xce1eec */ b #0xce1ef0;
    /* 0xce1ef0 */ b #0xce1f14;
    /* 0xce1ef4 */ adrp x0, #0x25a000;
    /* 0xce1ef8 */ add x0, x0, #0x2c0;
    __assert2();
    __assert2();
    sub_ceafa8();
    sub_ceafa8();
    sub_ceafa8();
    sub_ceafa8();
    sub_ceafa8();
    sub_ceb140();
    sub_ceafa8();
    sub_ceb140();
    sub_ceafa8();
    sub_ceafa8();
    return x0;
}

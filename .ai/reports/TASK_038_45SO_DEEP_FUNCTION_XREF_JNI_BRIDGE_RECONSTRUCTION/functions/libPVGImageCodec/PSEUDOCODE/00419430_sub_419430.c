// Library: libPVGImageCodec.so
// Function ID: libPVGImageCodec::0x419430
// Recovered Name: sub_419430
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x419430 | Size: 212 bytes | SHA256: e4610f876b5e9e84bd53fe8c4a3038606a7a20fede3cdf6eaa61b006de2458f3
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: __assert2, __memset_chk
// Strings referenced:
//   "/Users/zhichenzhang/meitu/Project/PVGThirdParty/libwebp/src/dec/vp8_dec.c"
//   "hdr != NULL"
//   "void ResetSegmentHeader(VP8SegmentHeader *const)"

void sub_419430(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 53 instructions
    /* 0x419430 */ stp x29, x30, [sp, #0x60];
    /* 0x419434 */ add x29, sp, #0x60;
    /* 0x419438 */ str x0, [sp, #0x18];
    /* 0x41943c */ ldr x8, [sp, #0x18];
    /* 0x419440 */ cbz x8, #0x41944c;
    /* 0x419444 */ b #0x419448;
    /* 0x419448 */ b #0x41946c;
    /* 0x41944c */ adrp x0, #0xc2000;
    /* 0x419450 */ add x0, x0, #0xa62;
    /* 0x419454 */ mov w1, #0x97;
    /* 0x419458 */ adrp x2, #0xc5000;
    __assert2();
    __memset_chk();
    __memset_chk();
    return x0;
}

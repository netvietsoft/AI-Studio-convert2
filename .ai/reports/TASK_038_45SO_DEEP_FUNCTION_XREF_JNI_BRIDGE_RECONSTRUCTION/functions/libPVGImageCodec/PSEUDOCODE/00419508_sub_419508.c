// Library: libPVGImageCodec.so
// Function ID: libPVGImageCodec::0x419508
// Recovered Name: sub_419508
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x419508 | Size: 628 bytes | SHA256: 77f6fbc19fa16645010549bb3d937e2f5472cc1b69c3025797d1def1e40c42b0
// Callers: 0 | Callees: 2 | Imports: 1

// Calls external APIs: __assert2
// Strings referenced:
//   "/Users/zhichenzhang/meitu/Project/PVGThirdParty/libwebp/src/dec/vp8_dec.c"
//   "br != NULL"
//   "hdr != NULL"
//   "int ParseSegmentHeader(VP8BitReader *, VP8SegmentHeader *, VP8Proba *)"

void sub_419508(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 157 instructions
    /* 0x419508 */ stp x29, x30, [sp, #0x30];
    /* 0x41950c */ add x29, sp, #0x30;
    /* 0x419510 */ stur x0, [x29, #-8];
    /* 0x419514 */ stur x1, [x29, #-0x10];
    /* 0x419518 */ str x2, [sp, #0x18];
    /* 0x41951c */ ldur x8, [x29, #-8];
    /* 0x419520 */ cbz x8, #0x41952c;
    /* 0x419524 */ b #0x419528;
    /* 0x419528 */ b #0x41954c;
    /* 0x41952c */ adrp x0, #0xc2000;
    /* 0x419530 */ add x0, x0, #0xa62;
    __assert2();
    __assert2();
    sub_487ccc();
    sub_487ccc();
    sub_487ccc();
    sub_487ccc();
    sub_487ccc();
    sub_487e64();
    sub_487ccc();
    sub_487e64();
    sub_487ccc();
    sub_487ccc();
    return x0;
}

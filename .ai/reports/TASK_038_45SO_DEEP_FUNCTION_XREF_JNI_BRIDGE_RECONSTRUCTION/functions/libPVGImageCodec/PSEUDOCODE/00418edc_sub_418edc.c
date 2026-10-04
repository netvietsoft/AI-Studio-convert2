// Library: libPVGImageCodec.so
// Function ID: libPVGImageCodec::0x418edc
// Recovered Name: sub_418edc
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x418edc | Size: 1344 bytes | SHA256: a30e2b22e08462324e1355509e3e1c65817e0177c04c052eb9c6c3751821dd75
// Callers: 0 | Callees: 11 | Imports: 1

// Calls external APIs: VP8CheckSignature
// Strings referenced:
//   "Bad code word"
//   "Frame not displayable."
//   "Incorrect keyframe parameters."
//   "Not a key frame."
//   "Truncated header."

void sub_418edc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 336 instructions
    /* 0x418edc */ stp x29, x30, [sp, #0x50];
    /* 0x418ee0 */ add x29, sp, #0x50;
    /* 0x418ee4 */ stur x0, [x29, #-0x10];
    /* 0x418ee8 */ stur x1, [x29, #-0x18];
    /* 0x418eec */ ldur x8, [x29, #-0x10];
    /* 0x418ef0 */ cbnz x8, #0x418f00;
    /* 0x418ef4 */ b #0x418ef8;
    /* 0x418ef8 */ stur wzr, [x29, #-4];
    /* 0x418efc */ b #0x41941c;
    /* 0x418f00 */ ldur x0, [x29, #-0x10];
    sub_418ad0();
    sub_418c50();
    sub_418c50();
    sub_418c50();
    sub_418c50();
    sub_418c50();
    VP8CheckSignature();
    sub_418c50();
    sub_424078();
    sub_41942c();
    sub_418c50();
    sub_487988();
    sub_487ccc();
    sub_487ccc();
    sub_419504();
    sub_418c50();
    sub_41977c();
    sub_418c50();
    sub_41993c();
    sub_418c50();
    sub_424bac();
    sub_418c50();
    sub_487ccc();
    sub_424670();
}

// Library: libarkernel3.so
// Function ID: libarkernel3::0xce18a4
// Recovered Name: sub_ce18a4
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xce18a4 | Size: 1344 bytes | SHA256: 9a396345aff94183eb398a03f2a70fa1cdb36c8f02e9e81dcb2d11354f3179bb
// Callers: 0 | Callees: 12 | Imports: 0

// Strings referenced:
//   "Bad code word"
//   "Frame not displayable."
//   "Incorrect keyframe parameters."
//   "Not a key frame."
//   "Truncated header."

void sub_ce18a4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 336 instructions
    /* 0xce18a4 */ stp x29, x30, [sp, #0x50];
    /* 0xce18a8 */ add x29, sp, #0x50;
    /* 0xce18ac */ stur x0, [x29, #-0x10];
    /* 0xce18b0 */ stur x1, [x29, #-0x18];
    /* 0xce18b4 */ ldur x8, [x29, #-0x10];
    /* 0xce18b8 */ cbnz x8, #0xce18c8;
    /* 0xce18bc */ b #0xce18c0;
    /* 0xce18c0 */ stur wzr, [x29, #-4];
    /* 0xce18c4 */ b #0xce1de4;
    /* 0xce18c8 */ ldur x0, [x29, #-0x10];
    sub_ce1498();
    sub_ce1618();
    sub_ce1618();
    sub_ce1618();
    sub_ce1618();
    sub_ce1618();
    sub_ce1668();
    sub_ce1618();
    sub_d0ac4c();
    sub_ce1df4();
    sub_ce1618();
    sub_ceac64();
    sub_ceafa8();
    sub_ceafa8();
    sub_ce1ecc();
    sub_ce1618();
    sub_ce2144();
    sub_ce1618();
    sub_ce2304();
    sub_ce1618();
    sub_d0b780();
    sub_ce1618();
    sub_ceafa8();
    sub_d0b244();
}

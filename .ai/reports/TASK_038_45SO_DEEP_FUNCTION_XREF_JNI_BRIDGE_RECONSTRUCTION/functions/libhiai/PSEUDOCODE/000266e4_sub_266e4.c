// Library: libhiai.so
// Function ID: libhiai::0x266e4
// Recovered Name: sub_266e4
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x266e4 | Size: 200 bytes | SHA256: 293fd55eb49126f1db2d6cdfcd9076baa4b47041fe9cb78c699f09b28ce3efc3
// Callers: 37 | Callees: 3 | Imports: 4

// Calls external APIs: _ZdlPv, _Znwm, memmove, strlen

void sub_266e4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 50 instructions
    /* 0x266e4 */ str x30, [sp, #-0x30]!;
    /* 0x266e8 */ stp x22, x21, [sp, #0x10];
    /* 0x266ec */ stp x20, x19, [sp, #0x20];
    /* 0x266f0 */ mov x19, x0;
    /* 0x266f4 */ mov x0, x1;
    /* 0x266f8 */ mov x21, x1;
    strlen();
    /* 0x26700 */ cmn x0, #0x10;
    /* 0x26704 */ b.hs #0x26764;
    /* 0x26708 */ mov x20, x0;
    /* 0x2670c */ cmp x0, #0x17;
    _Znwm();
    memmove();
    return x0;
    sub_267f0();
    sub_4e8f0();
    sub_4e5dc();
    _ZdlPv();
    return x0;
}

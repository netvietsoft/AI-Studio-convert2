// Library: libarkernel3.so
// Function ID: libarkernel3::0x6192dc
// Recovered Name: sub_6192dc
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x6192dc | Size: 320 bytes | SHA256: 0d98486158704afc113b5752717212ef34c05ed1d3a8b92e728d0e13b14e79ed
// Callers: 0 | Callees: 11 | Imports: 2

// Calls external APIs: _ZdlPv, _Znwm
// Strings referenced:
//   "Invalid number of parameters (expected 3)."
//   "Rectangle"
//   "lua_GPGlobalState_getSegmentEyePupilRectF - Failed to match the given parameters to a valid function signature."

void sub_6192dc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 80 instructions
    /* 0x6192dc */ stp x29, x30, [sp, #-0x40]!;
    /* 0x6192e0 */ str x23, [sp, #0x10];
    /* 0x6192e4 */ stp x22, x21, [sp, #0x20];
    /* 0x6192e8 */ stp x20, x19, [sp, #0x30];
    /* 0x6192ec */ mov x29, sp;
    /* 0x6192f0 */ mov x19, x0;
    sub_b783a0();
    /* 0x6192f8 */ cmp w0, #3;
    /* 0x6192fc */ b.ne #0x6193c8;
    /* 0x619300 */ mov x0, x19;
    /* 0x619304 */ mov w1, #1;
    sub_b7868c();
    sub_b7868c();
    sub_b7868c();
    sub_b7adb8();
    sub_b7adb8();
    sub_6156c0();
    _Znwm();
    sub_5fa10c();
    sub_b79dc8();
    sub_b791a8();
    sub_b79670();
    sub_b78de0();
    sub_b79ca8();
    return x0;
    _ZdlPv();
    sub_106b814();
}

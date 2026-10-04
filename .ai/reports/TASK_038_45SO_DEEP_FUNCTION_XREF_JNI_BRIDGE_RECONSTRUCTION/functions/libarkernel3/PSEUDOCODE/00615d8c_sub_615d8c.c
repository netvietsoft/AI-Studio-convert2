// Library: libarkernel3.so
// Function ID: libarkernel3::0x615d8c
// Recovered Name: sub_615d8c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x615d8c | Size: 272 bytes | SHA256: 9a2fdf7e1bcfb88da9632b947446c95887423dcc4d740d16c239a54762e41cab
// Callers: 0 | Callees: 11 | Imports: 2

// Calls external APIs: _ZdlPv, _Znwm
// Strings referenced:
//   "Invalid number of parameters (expected 2)."
//   "Rectangle"
//   "lua_GPGlobalState_getSegmentMaskRectF - Failed to match the given parameters to a valid function signature."

void sub_615d8c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 68 instructions
    /* 0x615d8c */ stp x29, x30, [sp, #-0x30]!;
    /* 0x615d90 */ stp x22, x21, [sp, #0x10];
    /* 0x615d94 */ stp x20, x19, [sp, #0x20];
    /* 0x615d98 */ mov x29, sp;
    /* 0x615d9c */ mov x19, x0;
    sub_b783a0();
    /* 0x615da4 */ cmp w0, #2;
    /* 0x615da8 */ b.ne #0x615e4c;
    /* 0x615dac */ mov x0, x19;
    /* 0x615db0 */ mov w1, #1;
    sub_b7868c();
    sub_b7868c();
    sub_b7adb8();
    sub_6156c0();
    _Znwm();
    sub_5f8298();
    sub_b79dc8();
    sub_b791a8();
    sub_b79670();
    sub_b78de0();
    sub_b79ca8();
    return x0;
    _ZdlPv();
    sub_106b814();
}

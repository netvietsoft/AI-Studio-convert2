// Library: libarkernel3.so
// Function ID: libarkernel3::0x61c7e0
// Recovered Name: sub_61c7e0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x61c7e0 | Size: 272 bytes | SHA256: 503ca1b1bd60a04276ea6fbaa71fd0d050119cf36427658e09c37f096b201ba6
// Callers: 0 | Callees: 11 | Imports: 2

// Calls external APIs: _ZdlPv, _Znwm
// Strings referenced:
//   "Invalid number of parameters (expected 3)."
//   "Rectangle"
//   "lua_GPInstanceSegmentData_getInstanceSegmentRectF - Failed to match the given parameters to a valid function signature."

void sub_61c7e0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 68 instructions
    /* 0x61c7e0 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x61c7e4 */ stp x22, x21, [sp, #0x10];
    /* 0x61c7e8 */ stp x20, x19, [sp, #0x20];
    /* 0x61c7ec */ mov x29, sp;
    /* 0x61c7f0 */ mov x19, x0;
    sub_b783a0();
    /* 0x61c7f8 */ cmp w0, #2;
    /* 0x61c7fc */ b.ne #0x61c8a0;
    /* 0x61c800 */ mov x0, x19;
    /* 0x61c804 */ mov w1, #1;
    sub_b7868c();
    sub_b7868c();
    sub_b7adb8();
    sub_61c794();
    _Znwm();
    sub_600fd4();
    sub_b79dc8();
    sub_b791a8();
    sub_b79670();
    sub_b78de0();
    sub_b79ca8();
    return x0;
    _ZdlPv();
    sub_106b814();
}

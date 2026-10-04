// Library: libarkernel3.so
// Function ID: libarkernel3::0x61c974
// Recovered Name: sub_61c974
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x61c974 | Size: 160 bytes | SHA256: fa7d0f2d3806437375ebbdbec261138b6044f1a07e780dba08052395b3531c28
// Callers: 0 | Callees: 7 | Imports: 0

// Strings referenced:
//   "Invalid number of parameters (expected 3)."
//   "lua_GPInstanceSegmentData_getInstanceSegmentRectF - Failed to match the given parameters to a valid function signature."

void sub_61c974(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 40 instructions
    /* 0x61c974 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x61c978 */ stp x20, x19, [sp, #0x10];
    /* 0x61c97c */ mov x29, sp;
    /* 0x61c980 */ mov x19, x0;
    sub_b783a0();
    /* 0x61c988 */ cmp w0, #2;
    /* 0x61c98c */ b.ne #0x61c9e0;
    /* 0x61c990 */ mov x0, x19;
    /* 0x61c994 */ mov w1, #1;
    sub_b7868c();
    /* 0x61c99c */ cmp w0, #7;
    sub_b7868c();
    sub_e2c398();
    sub_61c794();
    sub_600d10();
    sub_b78de0();
    sub_b79ca8();
    return x0;
}

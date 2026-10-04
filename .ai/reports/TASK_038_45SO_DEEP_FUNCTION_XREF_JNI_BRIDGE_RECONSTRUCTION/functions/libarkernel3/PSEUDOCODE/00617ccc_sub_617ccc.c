// Library: libarkernel3.so
// Function ID: libarkernel3::0x617ccc
// Recovered Name: sub_617ccc
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x617ccc | Size: 132 bytes | SHA256: 02804c43223641b95a6fc748a02aff0bc1847c016dd0a4546045195a3f078f16
// Callers: 0 | Callees: 7 | Imports: 0

// Strings referenced:
//   "Invalid number of parameters (expected 1)."
//   "lua_GPGlobalState_getSegmentMaskEdgePointCount - Failed to match the given parameters to a valid function signature."

void sub_617ccc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 33 instructions
    /* 0x617ccc */ stp x29, x30, [sp, #-0x20]!;
    /* 0x617cd0 */ str x19, [sp, #0x10];
    /* 0x617cd4 */ mov x29, sp;
    /* 0x617cd8 */ mov x19, x0;
    sub_b783a0();
    /* 0x617ce0 */ cmp w0, #1;
    /* 0x617ce4 */ b.ne #0x617d1c;
    /* 0x617ce8 */ mov x0, x19;
    /* 0x617cec */ mov w1, #1;
    sub_b7868c();
    /* 0x617cf4 */ cmp w0, #7;
    sub_6156c0();
    sub_5f8b80();
    sub_b78d10();
    sub_b78de0();
    sub_b79ca8();
    return x0;
}

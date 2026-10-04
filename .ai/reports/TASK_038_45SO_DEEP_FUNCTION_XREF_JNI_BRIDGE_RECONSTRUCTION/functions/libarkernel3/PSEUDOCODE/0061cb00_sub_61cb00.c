// Library: libarkernel3.so
// Function ID: libarkernel3::0x61cb00
// Recovered Name: sub_61cb00
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x61cb00 | Size: 236 bytes | SHA256: 9e5902b6a3d66b02c8803382b0ff77fa83058dd0cdc92e1716c427783fa6cf23
// Callers: 0 | Callees: 11 | Imports: 0

// Strings referenced:
//   "Invalid number of parameters (expected 3)."
//   "TextureSampler"
//   "lua_GPInstanceSegmentData_getInstanceSegmentMask - Failed to match the given parameters to a valid function signature."

void sub_61cb00(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 59 instructions
    /* 0x61cb00 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x61cb04 */ stp x20, x19, [sp, #0x10];
    /* 0x61cb08 */ mov x29, sp;
    /* 0x61cb0c */ mov x19, x0;
    sub_b783a0();
    /* 0x61cb14 */ cmp w0, #2;
    /* 0x61cb18 */ b.ne #0x61cba8;
    /* 0x61cb1c */ mov x0, x19;
    /* 0x61cb20 */ mov w1, #1;
    sub_b7868c();
    /* 0x61cb28 */ cmp w0, #7;
    sub_b7868c();
    sub_b7adb8();
    sub_61c794();
    sub_6010a0();
    sub_b79dc8();
    sub_b791a8();
    sub_b79670();
    sub_b78de0();
    sub_b79ca8();
    return x0;
    sub_b78cdc();
}

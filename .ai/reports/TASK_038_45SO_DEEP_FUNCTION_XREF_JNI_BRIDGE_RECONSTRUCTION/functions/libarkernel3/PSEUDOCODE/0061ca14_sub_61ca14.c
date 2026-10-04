// Library: libarkernel3.so
// Function ID: libarkernel3::0x61ca14
// Recovered Name: sub_61ca14
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x61ca14 | Size: 236 bytes | SHA256: 900cd7a28e6e1731df2d985ed98f5056c79398795660d7c4fd0cd28aec55c4ca
// Callers: 0 | Callees: 11 | Imports: 0

// Strings referenced:
//   "Invalid number of parameters (expected 3)."
//   "TextureSampler"
//   "lua_GPInstanceSegmentData_getFaceMappingInstanceSegmentMask - Failed to match the given parameters to a valid function signature."

void sub_61ca14(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 59 instructions
    /* 0x61ca14 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x61ca18 */ stp x20, x19, [sp, #0x10];
    /* 0x61ca1c */ mov x29, sp;
    /* 0x61ca20 */ mov x19, x0;
    sub_b783a0();
    /* 0x61ca28 */ cmp w0, #2;
    /* 0x61ca2c */ b.ne #0x61cabc;
    /* 0x61ca30 */ mov x0, x19;
    /* 0x61ca34 */ mov w1, #1;
    sub_b7868c();
    /* 0x61ca3c */ cmp w0, #7;
    sub_b7868c();
    sub_b7adb8();
    sub_61c794();
    sub_600f00();
    sub_b79dc8();
    sub_b791a8();
    sub_b79670();
    sub_b78de0();
    sub_b79ca8();
    return x0;
    sub_b78cdc();
}

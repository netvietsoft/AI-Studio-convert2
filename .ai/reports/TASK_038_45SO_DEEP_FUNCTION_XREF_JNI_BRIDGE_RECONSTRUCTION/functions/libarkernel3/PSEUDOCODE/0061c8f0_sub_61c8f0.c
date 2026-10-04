// Library: libarkernel3.so
// Function ID: libarkernel3::0x61c8f0
// Recovered Name: sub_61c8f0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x61c8f0 | Size: 132 bytes | SHA256: 1bee0ada402dce61b694fa53d905ab0bc6a9ec31de749fa2289ef855880f04f8
// Callers: 0 | Callees: 7 | Imports: 0

// Strings referenced:
//   "Invalid number of parameters (expected 1)."
//   "lua_GPInstanceSegmentData_getCurrentInsSegDataSize - Failed to match the given parameters to a valid function signature."

void sub_61c8f0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 33 instructions
    /* 0x61c8f0 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x61c8f4 */ str x19, [sp, #0x10];
    /* 0x61c8f8 */ mov x29, sp;
    /* 0x61c8fc */ mov x19, x0;
    sub_b783a0();
    /* 0x61c904 */ cmp w0, #1;
    /* 0x61c908 */ b.ne #0x61c940;
    /* 0x61c90c */ mov x0, x19;
    /* 0x61c910 */ mov w1, #1;
    sub_b7868c();
    /* 0x61c918 */ cmp w0, #7;
    sub_61c794();
    sub_601090();
    sub_b78d10();
    sub_b78de0();
    sub_b79ca8();
    return x0;
}

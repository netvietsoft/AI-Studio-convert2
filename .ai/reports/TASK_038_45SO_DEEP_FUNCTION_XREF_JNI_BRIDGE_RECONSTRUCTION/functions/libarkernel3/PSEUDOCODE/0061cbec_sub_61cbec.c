// Library: libarkernel3.so
// Function ID: libarkernel3::0x61cbec
// Recovered Name: sub_61cbec
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x61cbec | Size: 196 bytes | SHA256: 7e0f95489f4779ff1d18e101d387e1a1e784a259b646c3a7e7cdc651aa2f123f
// Callers: 0 | Callees: 10 | Imports: 0

// Strings referenced:
//   "Invalid number of parameters (expected 3)."
//   "TextureSampler"
//   "lua_GPInstanceSegmentData_getNoFaceMask - Failed to match the given parameters to a valid function signature."

void sub_61cbec(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 49 instructions
    /* 0x61cbec */ stp x29, x30, [sp, #-0x20]!;
    /* 0x61cbf0 */ stp x20, x19, [sp, #0x10];
    /* 0x61cbf4 */ mov x29, sp;
    /* 0x61cbf8 */ mov x19, x0;
    sub_b783a0();
    /* 0x61cc00 */ cmp w0, #1;
    /* 0x61cc04 */ b.ne #0x61cc6c;
    /* 0x61cc08 */ mov x0, x19;
    /* 0x61cc0c */ mov w1, #1;
    sub_b7868c();
    /* 0x61cc14 */ cmp w0, #7;
    sub_61c794();
    sub_601170();
    sub_b79dc8();
    sub_b791a8();
    sub_b79670();
    sub_b78de0();
    sub_b79ca8();
    sub_b78cdc();
    return x0;
}

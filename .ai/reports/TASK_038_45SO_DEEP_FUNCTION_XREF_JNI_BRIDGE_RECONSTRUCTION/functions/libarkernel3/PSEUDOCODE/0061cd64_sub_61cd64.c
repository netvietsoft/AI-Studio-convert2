// Library: libarkernel3.so
// Function ID: libarkernel3::0x61cd64
// Recovered Name: sub_61cd64
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x61cd64 | Size: 180 bytes | SHA256: 696dc06deda6f5ceec52895408ef363d31a2997f793fd80fe83a40d827ecde19
// Callers: 0 | Callees: 6 | Imports: 0

// Strings referenced:
//   "'GPInstanceSegmentData' expected."
//   "GPInstanceSegmentData"
//   "Invalid number of parameters (expected 1)."
//   "lua_GPInstanceSegmentData__gc - Failed to match the given parameters to a valid function signature."

void sub_61cd64(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 45 instructions
    /* 0x61cd64 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x61cd68 */ stp x20, x19, [sp, #0x10];
    /* 0x61cd6c */ mov x29, sp;
    /* 0x61cd70 */ mov x19, x0;
    sub_b783a0();
    /* 0x61cd78 */ cmp w0, #1;
    /* 0x61cd7c */ b.ne #0x61cde4;
    /* 0x61cd80 */ mov x0, x19;
    /* 0x61cd84 */ mov w1, #1;
    sub_b7868c();
    /* 0x61cd8c */ cmp w0, #7;
    sub_b7a990();
    sub_b7a3fc();
    sub_b78de0();
    sub_b79ca8();
    return x0;
}

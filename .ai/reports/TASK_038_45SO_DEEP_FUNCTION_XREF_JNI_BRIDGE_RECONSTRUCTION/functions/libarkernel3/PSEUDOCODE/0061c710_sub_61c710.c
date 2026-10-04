// Library: libarkernel3.so
// Function ID: libarkernel3::0x61c710
// Recovered Name: sub_61c710
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x61c710 | Size: 132 bytes | SHA256: 06723dba79bd368f5ee619f1413e4ba230e98f7bd04e8dcc0662c053bef25686
// Callers: 0 | Callees: 7 | Imports: 0

// Strings referenced:
//   "Invalid number of parameters (expected 1)."
//   "lua_GPInstanceSegmentData_updateInstanceSegmentMaskData - Failed to match the given parameters to a valid function signature."

void sub_61c710(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 33 instructions
    /* 0x61c710 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x61c714 */ str x19, [sp, #0x10];
    /* 0x61c718 */ mov x29, sp;
    /* 0x61c71c */ mov x19, x0;
    sub_b783a0();
    /* 0x61c724 */ cmp w0, #1;
    /* 0x61c728 */ b.ne #0x61c760;
    /* 0x61c72c */ mov x0, x19;
    /* 0x61c730 */ mov w1, #1;
    sub_b7868c();
    /* 0x61c738 */ cmp w0, #7;
    sub_61c794();
    sub_600d18();
    sub_b79080();
    sub_b78de0();
    sub_b79ca8();
    return x0;
}

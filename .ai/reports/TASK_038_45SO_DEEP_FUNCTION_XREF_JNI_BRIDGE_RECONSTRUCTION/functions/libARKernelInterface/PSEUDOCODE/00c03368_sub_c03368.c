// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xc03368
// Recovered Name: sub_c03368
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xc03368 | Size: 160 bytes | SHA256: d93f0285229b899fa3b181226bdcba894579ad6af476575034a8269f5fd273f4
// Callers: 0 | Callees: 7 | Imports: 0

// Strings referenced:
//   "Invalid number of parameters (expected 3)."
//   "lua_GPInstanceSegmentData_getInstanceSegmentRectF - Failed to match the given parameters to a valid function signature."

void sub_c03368(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 40 instructions
    /* 0xc03368 */ stp x29, x30, [sp, #-0x20]!;
    /* 0xc0336c */ stp x20, x19, [sp, #0x10];
    /* 0xc03370 */ mov x29, sp;
    /* 0xc03374 */ mov x19, x0;
    sub_f0cb90();
    /* 0xc0337c */ cmp w0, #2;
    /* 0xc03380 */ b.ne #0xc033d4;
    /* 0xc03384 */ mov x0, x19;
    /* 0xc03388 */ mov w1, #1;
    sub_f0ce7c();
    /* 0xc03390 */ cmp w0, #7;
    sub_f0ce7c();
    sub_d92214();
    sub_c0319c();
    sub_c03e44();
    sub_f0d5d0();
    sub_f0e498();
    return x0;
}

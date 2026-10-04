// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xc034f4
// Recovered Name: sub_c034f4
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xc034f4 | Size: 236 bytes | SHA256: 5de6076f71c61529e2822b94655313547bc602a2797e786f5437ae8c2130926a
// Callers: 0 | Callees: 11 | Imports: 0

// Strings referenced:
//   "Invalid number of parameters (expected 3)."
//   "TextureSampler"
//   "lua_GPInstanceSegmentData_getInstanceSegmentMask - Failed to match the given parameters to a valid function signature."

void sub_c034f4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 59 instructions
    /* 0xc034f4 */ stp x29, x30, [sp, #-0x20]!;
    /* 0xc034f8 */ stp x20, x19, [sp, #0x10];
    /* 0xc034fc */ mov x29, sp;
    /* 0xc03500 */ mov x19, x0;
    sub_f0cb90();
    /* 0xc03508 */ cmp w0, #2;
    /* 0xc0350c */ b.ne #0xc0359c;
    /* 0xc03510 */ mov x0, x19;
    /* 0xc03514 */ mov w1, #1;
    sub_f0ce7c();
    /* 0xc0351c */ cmp w0, #7;
    sub_f0ce7c();
    sub_f0f5a8();
    sub_c0319c();
    sub_c03c84();
    sub_f0e5b8();
    sub_f0d998();
    sub_f0de60();
    sub_f0d5d0();
    sub_f0e498();
    return x0;
    sub_f0d4cc();
}

// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xc03408
// Recovered Name: sub_c03408
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xc03408 | Size: 236 bytes | SHA256: 6aee2c22d138ed53563c2afe13f193c85eb54032e44c31c778a0949c640c1cb1
// Callers: 0 | Callees: 11 | Imports: 0

// Strings referenced:
//   "Invalid number of parameters (expected 3)."
//   "TextureSampler"
//   "lua_GPInstanceSegmentData_getFaceMappingInstanceSegmentMask - Failed to match the given parameters to a valid function signature."

void sub_c03408(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 59 instructions
    /* 0xc03408 */ stp x29, x30, [sp, #-0x20]!;
    /* 0xc0340c */ stp x20, x19, [sp, #0x10];
    /* 0xc03410 */ mov x29, sp;
    /* 0xc03414 */ mov x19, x0;
    sub_f0cb90();
    /* 0xc0341c */ cmp w0, #2;
    /* 0xc03420 */ b.ne #0xc034b0;
    /* 0xc03424 */ mov x0, x19;
    /* 0xc03428 */ mov w1, #1;
    sub_f0ce7c();
    /* 0xc03430 */ cmp w0, #7;
    sub_f0ce7c();
    sub_f0f5a8();
    sub_c0319c();
    sub_c03ba4();
    sub_f0e5b8();
    sub_f0d998();
    sub_f0de60();
    sub_f0d5d0();
    sub_f0e498();
    return x0;
    sub_f0d4cc();
}

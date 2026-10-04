// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xc035e0
// Recovered Name: sub_c035e0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xc035e0 | Size: 196 bytes | SHA256: f9c0c620c38a232b9748d018a8e72669f5e27fbd8997f43cfac8f594e7cbcd94
// Callers: 0 | Callees: 10 | Imports: 0

// Strings referenced:
//   "Invalid number of parameters (expected 3)."
//   "TextureSampler"
//   "lua_GPInstanceSegmentData_getNoFaceMask - Failed to match the given parameters to a valid function signature."

void sub_c035e0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 49 instructions
    /* 0xc035e0 */ stp x29, x30, [sp, #-0x20]!;
    /* 0xc035e4 */ stp x20, x19, [sp, #0x10];
    /* 0xc035e8 */ mov x29, sp;
    /* 0xc035ec */ mov x19, x0;
    sub_f0cb90();
    /* 0xc035f4 */ cmp w0, #1;
    /* 0xc035f8 */ b.ne #0xc03660;
    /* 0xc035fc */ mov x0, x19;
    /* 0xc03600 */ mov w1, #1;
    sub_f0ce7c();
    /* 0xc03608 */ cmp w0, #7;
    sub_c0319c();
    sub_c03d70();
    sub_f0e5b8();
    sub_f0d998();
    sub_f0de60();
    sub_f0d5d0();
    sub_f0e498();
    sub_f0d4cc();
    return x0;
}

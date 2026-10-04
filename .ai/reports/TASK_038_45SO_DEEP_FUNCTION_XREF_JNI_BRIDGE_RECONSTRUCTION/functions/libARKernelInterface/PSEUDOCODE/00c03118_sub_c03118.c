// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xc03118
// Recovered Name: sub_c03118
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xc03118 | Size: 132 bytes | SHA256: 33e9c5bcffa5bb6157f6344cc7a4912e19d3cafc1af206ead05da51627cbf5ea
// Callers: 0 | Callees: 7 | Imports: 0

// Strings referenced:
//   "Invalid number of parameters (expected 1)."
//   "lua_GPInstanceSegmentData_updateInstanceSegmentMaskData - Failed to match the given parameters to a valid function signature."

void sub_c03118(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 33 instructions
    /* 0xc03118 */ stp x29, x30, [sp, #-0x20]!;
    /* 0xc0311c */ str x19, [sp, #0x10];
    /* 0xc03120 */ mov x29, sp;
    /* 0xc03124 */ mov x19, x0;
    sub_f0cb90();
    /* 0xc0312c */ cmp w0, #1;
    /* 0xc03130 */ b.ne #0xc03168;
    /* 0xc03134 */ mov x0, x19;
    /* 0xc03138 */ mov w1, #1;
    sub_f0ce7c();
    /* 0xc03140 */ cmp w0, #7;
    sub_c0319c();
    sub_c038d4();
    sub_f0d870();
    sub_f0d5d0();
    sub_f0e498();
    return x0;
}

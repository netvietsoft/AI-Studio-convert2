// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xc032e4
// Recovered Name: sub_c032e4
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xc032e4 | Size: 132 bytes | SHA256: a3a59985f1e5de61813f5468e32421dc9eaa4d7235f86fcf59c20016e4f8e845
// Callers: 0 | Callees: 7 | Imports: 0

// Strings referenced:
//   "Invalid number of parameters (expected 1)."
//   "lua_GPInstanceSegmentData_getCurrentInsSegDataSize - Failed to match the given parameters to a valid function signature."

void sub_c032e4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 33 instructions
    /* 0xc032e4 */ stp x29, x30, [sp, #-0x20]!;
    /* 0xc032e8 */ str x19, [sp, #0x10];
    /* 0xc032ec */ mov x29, sp;
    /* 0xc032f0 */ mov x19, x0;
    sub_f0cb90();
    /* 0xc032f8 */ cmp w0, #1;
    /* 0xc032fc */ b.ne #0xc03334;
    /* 0xc03300 */ mov x0, x19;
    /* 0xc03304 */ mov w1, #1;
    sub_f0ce7c();
    /* 0xc0330c */ cmp w0, #7;
    sub_c0319c();
    sub_c03e4c();
    sub_f0d500();
    sub_f0d5d0();
    sub_f0e498();
    return x0;
}

// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xc04a78
// Recovered Name: sub_c04a78
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xc04a78 | Size: 312 bytes | SHA256: 62d00c886aa15720d2acc977c73eaeddba1095351088b7e1ca27b1bf090f969e
// Callers: 0 | Callees: 16 | Imports: 1

// Calls external APIs: __dynamic_cast
// Strings referenced:
//   "Invalid number of parameters (expected 1)."
//   "TextureSampler"
//   "lua_GPHairSeamersData_getHairSeamerFilled - Failed to match the given parameters to a valid function signature."

void sub_c04a78(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 78 instructions
    /* 0xc04a78 */ stp x29, x30, [sp, #-0x30]!;
    /* 0xc04a7c */ stp x22, x21, [sp, #0x10];
    /* 0xc04a80 */ stp x20, x19, [sp, #0x20];
    /* 0xc04a84 */ mov x29, sp;
    /* 0xc04a88 */ mov x19, x0;
    sub_f0cb90();
    /* 0xc04a90 */ cmp w0, #1;
    /* 0xc04a94 */ b.ne #0xc04b64;
    /* 0xc04a98 */ mov x0, x19;
    /* 0xc04a9c */ mov w1, #1;
    sub_f0ce7c();
    sub_d44604();
    __dynamic_cast();
    sub_6b2620();
    sub_c04fe8();
    sub_c05018();
    sub_c05028();
    sub_da1d14();
    sub_da2ed4();
    sub_d7ffbc();
    sub_f0e5b8();
    sub_f0d998();
    sub_f0de60();
    sub_f0d5d0();
    sub_f0e498();
    sub_f0d4cc();
    return x0;
}

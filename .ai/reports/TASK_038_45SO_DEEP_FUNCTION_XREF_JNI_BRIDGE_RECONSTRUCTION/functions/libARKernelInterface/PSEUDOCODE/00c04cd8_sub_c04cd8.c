// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xc04cd8
// Recovered Name: sub_c04cd8
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xc04cd8 | Size: 348 bytes | SHA256: 92bd3e4ea98fabcd996d350739273feb8dfc7a718a9efc0c2e7c5cf02cfa0874
// Callers: 0 | Callees: 17 | Imports: 2

// Calls external APIs: _ZdaPv, __dynamic_cast
// Strings referenced:
//   "Invalid number of parameters (expected 1)."
//   "TextureSampler"
//   "lua_GPHairSeamersData_getHairVectorField - Failed to match the given parameters to a valid function signature."

void sub_c04cd8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 87 instructions
    /* 0xc04cd8 */ stp x29, x30, [sp, #-0x40]!;
    /* 0xc04cdc */ str x23, [sp, #0x10];
    /* 0xc04ce0 */ stp x22, x21, [sp, #0x20];
    /* 0xc04ce4 */ stp x20, x19, [sp, #0x30];
    /* 0xc04ce8 */ mov x29, sp;
    /* 0xc04cec */ mov x19, x0;
    sub_f0cb90();
    /* 0xc04cf4 */ cmp w0, #1;
    /* 0xc04cf8 */ b.ne #0xc04de8;
    /* 0xc04cfc */ mov x0, x19;
    /* 0xc04d00 */ mov w1, #1;
    sub_f0ce7c();
    sub_d44604();
    __dynamic_cast();
    sub_6b2620();
    sub_c04ff8();
    sub_c05018();
    sub_c05028();
    sub_c04c84();
    sub_da2264();
    sub_da2ed4();
    _ZdaPv();
    sub_d7ffbc();
    sub_f0e5b8();
    sub_f0d998();
    sub_f0de60();
    sub_f0d5d0();
    sub_f0e498();
    sub_f0d4cc();
    return x0;
}

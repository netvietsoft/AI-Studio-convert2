// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xc04e34
// Recovered Name: sub_c04e34
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xc04e34 | Size: 264 bytes | SHA256: 375ad92b4588c175620ac46f71e6b40db028663407761e03a786a4ff615e02ec
// Callers: 0 | Callees: 13 | Imports: 2

// Calls external APIs: _Znwm, __dynamic_cast
// Strings referenced:
//   "Invalid number of parameters (expected 1)."
//   "Vector4"
//   "lua_GPHairSeamersData_getOptRegion - Failed to match the given parameters to a valid function signature."

void sub_c04e34(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 66 instructions
    /* 0xc04e34 */ stp x29, x30, [sp, #-0x30]!;
    /* 0xc04e38 */ stp x22, x21, [sp, #0x10];
    /* 0xc04e3c */ stp x20, x19, [sp, #0x20];
    /* 0xc04e40 */ mov x29, sp;
    /* 0xc04e44 */ mov x19, x0;
    sub_f0cb90();
    /* 0xc04e4c */ cmp w0, #1;
    /* 0xc04e50 */ b.ne #0xc04f00;
    /* 0xc04e54 */ mov x0, x19;
    /* 0xc04e58 */ mov w1, #1;
    /* 0xc04e5c */ mov w20, #1;
    sub_f0ce7c();
    sub_d44604();
    __dynamic_cast();
    sub_6b2620();
    sub_c05008();
    sub_c05018();
    sub_c05028();
    _Znwm();
    sub_dad750();
    sub_f0e5b8();
    sub_f0d998();
    sub_f0de60();
    sub_f0d5d0();
    sub_f0e498();
    return x0;
}

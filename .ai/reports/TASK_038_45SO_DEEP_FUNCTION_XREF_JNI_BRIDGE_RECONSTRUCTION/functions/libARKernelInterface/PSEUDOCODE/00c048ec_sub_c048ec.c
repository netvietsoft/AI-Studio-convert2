// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xc048ec
// Recovered Name: sub_c048ec
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xc048ec | Size: 396 bytes | SHA256: 8dc64b6ef3f9021d5405fa067120946ea0023e15353e66d5ec7ac4de1b586187
// Callers: 0 | Callees: 16 | Imports: 3

// Calls external APIs: _ZdaPv, _Znam, __dynamic_cast
// Strings referenced:
//   "Invalid number of parameters (expected 1)."
//   "TextureSampler"
//   "lua_GPHairSeamersData_getHairSeamerFilled - Failed to match the given parameters to a valid function signature."

void sub_c048ec(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 99 instructions
    /* 0xc048ec */ stp x29, x30, [sp, #-0x40]!;
    /* 0xc048f0 */ stp x24, x23, [sp, #0x10];
    /* 0xc048f4 */ stp x22, x21, [sp, #0x20];
    /* 0xc048f8 */ stp x20, x19, [sp, #0x30];
    /* 0xc048fc */ mov x29, sp;
    /* 0xc04900 */ mov x19, x0;
    sub_f0cb90();
    /* 0xc04908 */ cmp w0, #1;
    /* 0xc0490c */ b.ne #0xc04a2c;
    /* 0xc04910 */ mov x0, x19;
    /* 0xc04914 */ mov w1, #1;
    sub_f0ce7c();
    sub_d44604();
    __dynamic_cast();
    sub_6b2620();
    sub_c04fd8();
    sub_c05018();
    sub_c05028();
    _Znam();
    sub_da1d14();
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

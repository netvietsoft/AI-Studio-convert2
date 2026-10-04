// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xbde874
// Recovered Name: sub_bde874
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xbde874 | Size: 196 bytes | SHA256: 3347ac5e7b836f5b465ff59923584418adad04467fe01fd8e9981646c699561d
// Callers: 0 | Callees: 10 | Imports: 0

// Strings referenced:
//   "GPHairSeamersData"
//   "Invalid number of parameters (expected 1)."
//   "lua_GPGlobalState_getHairSeamersData - Failed to match the given parameters to a valid function signature."

void sub_bde874(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 49 instructions
    /* 0xbde874 */ stp x29, x30, [sp, #-0x20]!;
    /* 0xbde878 */ stp x20, x19, [sp, #0x10];
    /* 0xbde87c */ mov x29, sp;
    /* 0xbde880 */ mov x19, x0;
    sub_f0cb90();
    /* 0xbde888 */ cmp w0, #1;
    /* 0xbde88c */ b.ne #0xbde8f4;
    /* 0xbde890 */ mov x0, x19;
    /* 0xbde894 */ mov w1, #1;
    sub_f0ce7c();
    /* 0xbde89c */ cmp w0, #7;
    sub_bddc70();
    sub_6b2620();
    sub_f0e5b8();
    sub_f0d998();
    sub_f0de60();
    sub_f0d5d0();
    sub_f0e498();
    sub_f0d4cc();
    return x0;
}

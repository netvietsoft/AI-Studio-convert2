// Library: libarkernel3.so
// Function ID: libarkernel3::0x616024
// Recovered Name: sub_616024
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x616024 | Size: 196 bytes | SHA256: b733359ee01303d8958991e0749d88cf12bf0ffbe942128cefbbab702510c7c8
// Callers: 0 | Callees: 10 | Imports: 0

// Strings referenced:
//   "GPInstanceSegmentData"
//   "Invalid number of parameters (expected 1)."
//   "lua_GPGlobalState_getInstanceSegmentData - Failed to match the given parameters to a valid function signature."

void sub_616024(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 49 instructions
    /* 0x616024 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x616028 */ stp x20, x19, [sp, #0x10];
    /* 0x61602c */ mov x29, sp;
    /* 0x616030 */ mov x19, x0;
    sub_b783a0();
    /* 0x616038 */ cmp w0, #1;
    /* 0x61603c */ b.ne #0x6160a4;
    /* 0x616040 */ mov x0, x19;
    /* 0x616044 */ mov w1, #1;
    sub_b7868c();
    /* 0x61604c */ cmp w0, #7;
    sub_6156c0();
    sub_5f8304();
    sub_b79dc8();
    sub_b791a8();
    sub_b79670();
    sub_b78de0();
    sub_b79ca8();
    sub_b78cdc();
    return x0;
}

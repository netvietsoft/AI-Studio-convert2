// Library: libarkernel3.so
// Function ID: libarkernel3::0x6191c0
// Recovered Name: sub_6191c0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x6191c0 | Size: 284 bytes | SHA256: a5ba0f8842e155832175c04b882b3b4c83f0c42b4aa2991d750be277e67414c7
// Callers: 0 | Callees: 11 | Imports: 0

// Strings referenced:
//   "Invalid number of parameters (expected 3)."
//   "TextureSampler"
//   "lua_GPGlobalState_getSegmentEyePupil - Failed to match the given parameters to a valid function signature."

void sub_6191c0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 71 instructions
    /* 0x6191c0 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x6191c4 */ str x21, [sp, #0x10];
    /* 0x6191c8 */ stp x20, x19, [sp, #0x20];
    /* 0x6191cc */ mov x29, sp;
    /* 0x6191d0 */ mov x19, x0;
    sub_b783a0();
    /* 0x6191d8 */ cmp w0, #3;
    /* 0x6191dc */ b.ne #0x619294;
    /* 0x6191e0 */ mov x0, x19;
    /* 0x6191e4 */ mov w1, #1;
    sub_b7868c();
    sub_b7868c();
    sub_b7868c();
    sub_b7adb8();
    sub_b7adb8();
    sub_6156c0();
    sub_5fb080();
    sub_b79dc8();
    sub_b791a8();
    sub_b79670();
    sub_b78de0();
    sub_b79ca8();
    return x0;
    sub_b78cdc();
}

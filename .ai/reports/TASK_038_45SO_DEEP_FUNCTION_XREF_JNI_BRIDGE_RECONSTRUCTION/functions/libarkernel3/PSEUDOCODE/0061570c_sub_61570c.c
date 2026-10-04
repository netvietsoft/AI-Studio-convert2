// Library: libarkernel3.so
// Function ID: libarkernel3::0x61570c
// Recovered Name: sub_61570c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x61570c | Size: 236 bytes | SHA256: 1982e42b799d17de4af0da0196ce63a40555d447653ef8baf6f1a972415fe934
// Callers: 0 | Callees: 11 | Imports: 0

// Strings referenced:
//   "Invalid number of parameters (expected 2)."
//   "TextureSampler"
//   "lua_GPGlobalState_getSegmentMask - Failed to match the given parameters to a valid function signature."

void sub_61570c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 59 instructions
    /* 0x61570c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x615710 */ stp x20, x19, [sp, #0x10];
    /* 0x615714 */ mov x29, sp;
    /* 0x615718 */ mov x19, x0;
    sub_b783a0();
    /* 0x615720 */ cmp w0, #2;
    /* 0x615724 */ b.ne #0x6157b4;
    /* 0x615728 */ mov x0, x19;
    /* 0x61572c */ mov w1, #1;
    sub_b7868c();
    /* 0x615734 */ cmp w0, #7;
    sub_b7868c();
    sub_b7adb8();
    sub_6156c0();
    sub_5f722c();
    sub_b79dc8();
    sub_b791a8();
    sub_b79670();
    sub_b78de0();
    sub_b79ca8();
    return x0;
    sub_b78cdc();
}

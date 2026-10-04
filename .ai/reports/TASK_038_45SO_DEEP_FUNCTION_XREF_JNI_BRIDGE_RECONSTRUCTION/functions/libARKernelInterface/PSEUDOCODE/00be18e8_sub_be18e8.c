// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xbe18e8
// Recovered Name: sub_be18e8
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xbe18e8 | Size: 284 bytes | SHA256: 67985a11ce95fc7f187125b2c3a80a1b52603e84afbaecbc8327d2b409bdb471
// Callers: 0 | Callees: 11 | Imports: 0

// Strings referenced:
//   "Invalid number of parameters (expected 3)."
//   "TextureSampler"
//   "lua_GPGlobalState_getSegmentEyePupil - Failed to match the given parameters to a valid function signature."

void sub_be18e8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 71 instructions
    /* 0xbe18e8 */ stp x29, x30, [sp, #-0x30]!;
    /* 0xbe18ec */ str x21, [sp, #0x10];
    /* 0xbe18f0 */ stp x20, x19, [sp, #0x20];
    /* 0xbe18f4 */ mov x29, sp;
    /* 0xbe18f8 */ mov x19, x0;
    sub_f0cb90();
    /* 0xbe1900 */ cmp w0, #3;
    /* 0xbe1904 */ b.ne #0xbe19bc;
    /* 0xbe1908 */ mov x0, x19;
    /* 0xbe190c */ mov w1, #1;
    sub_f0ce7c();
    sub_f0ce7c();
    sub_f0ce7c();
    sub_f0f5a8();
    sub_f0f5a8();
    sub_bddc70();
    sub_6affbc();
    sub_f0e5b8();
    sub_f0d998();
    sub_f0de60();
    sub_f0d5d0();
    sub_f0e498();
    return x0;
    sub_f0d4cc();
}

// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xbe1a04
// Recovered Name: sub_be1a04
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xbe1a04 | Size: 300 bytes | SHA256: d05c449423d03a700101f4a228174df7a9ced75e68f92854e01dee7c28c26dce
// Callers: 0 | Callees: 10 | Imports: 1

// Calls external APIs: _Znwm
// Strings referenced:
//   "Invalid number of parameters (expected 3)."
//   "Rectangle"
//   "lua_GPGlobalState_getSegmentEyePupilRectF - Failed to match the given parameters to a valid function signature."

void sub_be1a04(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 75 instructions
    /* 0xbe1a04 */ stp x29, x30, [sp, #-0x40]!;
    /* 0xbe1a08 */ str x23, [sp, #0x10];
    /* 0xbe1a0c */ stp x22, x21, [sp, #0x20];
    /* 0xbe1a10 */ stp x20, x19, [sp, #0x30];
    /* 0xbe1a14 */ mov x29, sp;
    /* 0xbe1a18 */ mov x19, x0;
    sub_f0cb90();
    /* 0xbe1a20 */ cmp w0, #3;
    /* 0xbe1a24 */ b.ne #0xbe1af0;
    /* 0xbe1a28 */ mov x0, x19;
    /* 0xbe1a2c */ mov w1, #1;
    sub_f0ce7c();
    sub_f0ce7c();
    sub_f0ce7c();
    sub_f0f5a8();
    sub_f0f5a8();
    sub_bddc70();
    _Znwm();
    sub_6aff7c();
    sub_f0e5b8();
    sub_f0d998();
    sub_f0de60();
    sub_f0d5d0();
    sub_f0e498();
    return x0;
}

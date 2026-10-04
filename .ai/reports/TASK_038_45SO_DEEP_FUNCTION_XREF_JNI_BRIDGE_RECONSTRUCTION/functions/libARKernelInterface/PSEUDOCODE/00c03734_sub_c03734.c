// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xc03734
// Recovered Name: sub_c03734
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xc03734 | Size: 184 bytes | SHA256: c8e910224a406e219719438107a7b4e6cbfcbbb9f428b4d3fc58166d9706518c
// Callers: 0 | Callees: 7 | Imports: 1

// Calls external APIs: _ZdlPv
// Strings referenced:
//   "'GPInstanceSegmentData' expected."
//   "GPInstanceSegmentData"
//   "Invalid number of parameters (expected 1)."
//   "lua_GPInstanceSegmentData__gc - Failed to match the given parameters to a valid function signature."

void sub_c03734(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 46 instructions
    /* 0xc03734 */ stp x29, x30, [sp, #-0x20]!;
    /* 0xc03738 */ stp x20, x19, [sp, #0x10];
    /* 0xc0373c */ mov x29, sp;
    /* 0xc03740 */ mov x19, x0;
    sub_f0cb90();
    /* 0xc03748 */ cmp w0, #1;
    /* 0xc0374c */ b.ne #0xc037b8;
    /* 0xc03750 */ mov x0, x19;
    /* 0xc03754 */ mov w1, #1;
    sub_f0ce7c();
    /* 0xc0375c */ cmp w0, #7;
    sub_f0f180();
    sub_f0ebec();
    sub_c03850();
    _ZdlPv();
    sub_f0d5d0();
    sub_f0e498();
    return x0;
}

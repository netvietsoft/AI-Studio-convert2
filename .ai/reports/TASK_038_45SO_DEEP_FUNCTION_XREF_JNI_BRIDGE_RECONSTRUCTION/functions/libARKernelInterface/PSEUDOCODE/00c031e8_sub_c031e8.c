// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xc031e8
// Recovered Name: sub_c031e8
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xc031e8 | Size: 252 bytes | SHA256: 5b5677ed83ef8dd69fbc77bddc081c765443d637657bf1e6fc87870781445bf3
// Callers: 0 | Callees: 10 | Imports: 1

// Calls external APIs: _Znwm
// Strings referenced:
//   "Invalid number of parameters (expected 3)."
//   "Rectangle"
//   "lua_GPInstanceSegmentData_getInstanceSegmentRectF - Failed to match the given parameters to a valid function signature."

void sub_c031e8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 63 instructions
    /* 0xc031e8 */ stp x29, x30, [sp, #-0x30]!;
    /* 0xc031ec */ stp x22, x21, [sp, #0x10];
    /* 0xc031f0 */ stp x20, x19, [sp, #0x20];
    /* 0xc031f4 */ mov x29, sp;
    /* 0xc031f8 */ mov x19, x0;
    sub_f0cb90();
    /* 0xc03200 */ cmp w0, #2;
    /* 0xc03204 */ b.ne #0xc032a8;
    /* 0xc03208 */ mov x0, x19;
    /* 0xc0320c */ mov w1, #1;
    sub_f0ce7c();
    sub_f0ce7c();
    sub_f0f5a8();
    sub_c0319c();
    _Znwm();
    sub_c03c68();
    sub_f0e5b8();
    sub_f0d998();
    sub_f0de60();
    sub_f0d5d0();
    sub_f0e498();
    return x0;
}

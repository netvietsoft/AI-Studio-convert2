// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xbde52c
// Recovered Name: sub_bde52c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xbde52c | Size: 252 bytes | SHA256: 3ca5a206dad964808ef70b1713460972d15ae278607f0286ece8134406427684
// Callers: 0 | Callees: 10 | Imports: 1

// Calls external APIs: _Znwm
// Strings referenced:
//   "Invalid number of parameters (expected 2)."
//   "Rectangle"
//   "lua_GPGlobalState_getSegmentMaskRectF - Failed to match the given parameters to a valid function signature."

void sub_bde52c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 63 instructions
    /* 0xbde52c */ stp x29, x30, [sp, #-0x30]!;
    /* 0xbde530 */ stp x22, x21, [sp, #0x10];
    /* 0xbde534 */ stp x20, x19, [sp, #0x20];
    /* 0xbde538 */ mov x29, sp;
    /* 0xbde53c */ mov x19, x0;
    sub_f0cb90();
    /* 0xbde544 */ cmp w0, #2;
    /* 0xbde548 */ b.ne #0xbde5ec;
    /* 0xbde54c */ mov x0, x19;
    /* 0xbde550 */ mov w1, #1;
    sub_f0ce7c();
    sub_f0ce7c();
    sub_f0f5a8();
    sub_bddc70();
    _Znwm();
    sub_6b262c();
    sub_f0e5b8();
    sub_f0d998();
    sub_f0de60();
    sub_f0d5d0();
    sub_f0e498();
    return x0;
}

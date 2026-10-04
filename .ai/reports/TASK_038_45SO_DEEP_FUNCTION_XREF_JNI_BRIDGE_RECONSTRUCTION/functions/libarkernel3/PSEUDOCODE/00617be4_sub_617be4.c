// Library: libarkernel3.so
// Function ID: libarkernel3::0x617be4
// Recovered Name: sub_617be4
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x617be4 | Size: 232 bytes | SHA256: c4b3ab8d115f80070923314d0ce21f373c6b1ba2919a04d9209329adeb85c5fa
// Callers: 0 | Callees: 10 | Imports: 2

// Calls external APIs: _ZdlPv, _Znwm
// Strings referenced:
//   "Invalid number of parameters (expected 1)."
//   "Vector2"
//   "lua_GPGlobalState_getSegmentMaskEdgePointCount - Failed to match the given parameters to a valid function signature."

void sub_617be4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 58 instructions
    /* 0x617be4 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x617be8 */ str x21, [sp, #0x10];
    /* 0x617bec */ stp x20, x19, [sp, #0x20];
    /* 0x617bf0 */ mov x29, sp;
    /* 0x617bf4 */ mov x19, x0;
    sub_b783a0();
    /* 0x617bfc */ cmp w0, #1;
    /* 0x617c00 */ b.ne #0x617c7c;
    /* 0x617c04 */ mov x0, x19;
    /* 0x617c08 */ mov w1, #1;
    sub_b7868c();
    sub_6156c0();
    _Znwm();
    sub_5f8dc8();
    sub_b79dc8();
    sub_b791a8();
    sub_b79670();
    sub_b78de0();
    sub_b79ca8();
    return x0;
    _ZdlPv();
    sub_106b814();
}

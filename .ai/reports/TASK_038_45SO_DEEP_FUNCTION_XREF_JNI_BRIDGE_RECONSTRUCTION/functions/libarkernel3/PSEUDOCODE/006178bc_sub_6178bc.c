// Library: libarkernel3.so
// Function ID: libarkernel3::0x6178bc
// Recovered Name: sub_6178bc
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x6178bc | Size: 276 bytes | SHA256: 0593c391713c5d769475fa51ee8613d9ffd35dfd8239b0f7a7923d9e03afcfcd
// Callers: 0 | Callees: 11 | Imports: 2

// Calls external APIs: _ZdlPv, _Znwm
// Strings referenced:
//   "Invalid number of parameters (expected 2)."
//   "Vector3"
//   "lua_GPGlobalState_getSegmentMaskEdgePoint - Failed to match the given parameters to a valid function signature."

void sub_6178bc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 69 instructions
    /* 0x6178bc */ stp x29, x30, [sp, #-0x30]!;
    /* 0x6178c0 */ stp x22, x21, [sp, #0x10];
    /* 0x6178c4 */ stp x20, x19, [sp, #0x20];
    /* 0x6178c8 */ mov x29, sp;
    /* 0x6178cc */ mov x19, x0;
    sub_b783a0();
    /* 0x6178d4 */ cmp w0, #2;
    /* 0x6178d8 */ b.ne #0x61797c;
    /* 0x6178dc */ mov x0, x19;
    /* 0x6178e0 */ mov w1, #1;
    sub_b7868c();
    sub_b7868c();
    sub_b7adb8();
    sub_6156c0();
    _Znwm();
    sub_5f8b9c();
    sub_b79dc8();
    sub_b791a8();
    sub_b79670();
    sub_b78de0();
    sub_b79ca8();
    return x0;
    _ZdlPv();
    sub_106b814();
}

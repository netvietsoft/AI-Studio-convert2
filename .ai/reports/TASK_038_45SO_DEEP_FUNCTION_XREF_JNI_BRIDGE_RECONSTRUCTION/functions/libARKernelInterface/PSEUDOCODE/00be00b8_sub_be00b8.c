// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xbe00b8
// Recovered Name: sub_be00b8
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xbe00b8 | Size: 256 bytes | SHA256: a0036b6ed6e9655abb2cb203611ea829e144543f65ff1802eec8c8e468c5a655
// Callers: 0 | Callees: 10 | Imports: 1

// Calls external APIs: _Znwm
// Strings referenced:
//   "Invalid number of parameters (expected 2)."
//   "Vector3"
//   "lua_GPGlobalState_getSegmentMaskEdgePoint - Failed to match the given parameters to a valid function signature."

void sub_be00b8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 64 instructions
    /* 0xbe00b8 */ stp x29, x30, [sp, #-0x30]!;
    /* 0xbe00bc */ stp x22, x21, [sp, #0x10];
    /* 0xbe00c0 */ stp x20, x19, [sp, #0x20];
    /* 0xbe00c4 */ mov x29, sp;
    /* 0xbe00c8 */ mov x19, x0;
    sub_f0cb90();
    /* 0xbe00d0 */ cmp w0, #2;
    /* 0xbe00d4 */ b.ne #0xbe0178;
    /* 0xbe00d8 */ mov x0, x19;
    /* 0xbe00dc */ mov w1, #1;
    sub_f0ce7c();
    sub_f0ce7c();
    sub_f0f5a8();
    sub_bddc70();
    _Znwm();
    sub_6b2668();
    sub_f0e5b8();
    sub_f0d998();
    sub_f0de60();
    sub_f0d5d0();
    sub_f0e498();
    return x0;
}

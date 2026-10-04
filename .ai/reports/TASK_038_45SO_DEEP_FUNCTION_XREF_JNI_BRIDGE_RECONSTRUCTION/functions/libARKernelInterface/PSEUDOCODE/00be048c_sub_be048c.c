// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xbe048c
// Recovered Name: sub_be048c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xbe048c | Size: 132 bytes | SHA256: 8d34c9dceae92b2122d33513c27d67107689d81a89e15497b27c74f3d849cac2
// Callers: 0 | Callees: 7 | Imports: 0

// Strings referenced:
//   "Invalid number of parameters (expected 1)."
//   "lua_GPGlobalState_getSegmentMaskEdgePointCount - Failed to match the given parameters to a valid function signature."

void sub_be048c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 33 instructions
    /* 0xbe048c */ stp x29, x30, [sp, #-0x20]!;
    /* 0xbe0490 */ str x19, [sp, #0x10];
    /* 0xbe0494 */ mov x29, sp;
    /* 0xbe0498 */ mov x19, x0;
    sub_f0cb90();
    /* 0xbe04a0 */ cmp w0, #1;
    /* 0xbe04a4 */ b.ne #0xbe04dc;
    /* 0xbe04a8 */ mov x0, x19;
    /* 0xbe04ac */ mov w1, #1;
    sub_f0ce7c();
    /* 0xbe04b4 */ cmp w0, #7;
    sub_bddc70();
    sub_6b2598();
    sub_f0d500();
    sub_f0d5d0();
    sub_f0e498();
    return x0;
}

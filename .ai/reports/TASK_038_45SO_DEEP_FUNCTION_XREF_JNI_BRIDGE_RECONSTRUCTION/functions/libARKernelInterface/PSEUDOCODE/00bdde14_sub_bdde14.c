// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xbdde14
// Recovered Name: sub_bdde14
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xbdde14 | Size: 236 bytes | SHA256: b82faabe50d03275a0433e31e0f67170b9d62beb3f97a5089671288d67fcf5fb
// Callers: 0 | Callees: 11 | Imports: 0

// Strings referenced:
//   "Invalid number of parameters (expected 2)."
//   "TextureSampler"
//   "lua_GPGlobalState_getSegmentMask - Failed to match the given parameters to a valid function signature."

void sub_bdde14(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 59 instructions
    /* 0xbdde14 */ stp x29, x30, [sp, #-0x20]!;
    /* 0xbdde18 */ stp x20, x19, [sp, #0x10];
    /* 0xbdde1c */ mov x29, sp;
    /* 0xbdde20 */ mov x19, x0;
    sub_f0cb90();
    /* 0xbdde28 */ cmp w0, #2;
    /* 0xbdde2c */ b.ne #0xbddebc;
    /* 0xbdde30 */ mov x0, x19;
    /* 0xbdde34 */ mov w1, #1;
    sub_f0ce7c();
    /* 0xbdde3c */ cmp w0, #7;
    sub_f0ce7c();
    sub_f0f5a8();
    sub_bddc70();
    sub_6afe2c();
    sub_f0e5b8();
    sub_f0d998();
    sub_f0de60();
    sub_f0d5d0();
    sub_f0e498();
    return x0;
    sub_f0d4cc();
}

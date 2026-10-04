// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xbe3be0
// Recovered Name: sub_be3be0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xbe3be0 | Size: 284 bytes | SHA256: 538ce6fb61751976eedabb5381ef9ba83da412bbc003c25f2c505d3a6dd71173
// Callers: 0 | Callees: 8 | Imports: 2

// Calls external APIs: _ZdlPv, __stack_chk_fail
// Strings referenced:
//   "Invalid number of parameters (expected 1)."
//   "lua_ScriptHost_getMultiplySegmentType - Failed to match the given parameters to a valid function signature."

void sub_be3be0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 71 instructions
    /* 0xbe3be0 */ stp x29, x30, [sp, #0x20];
    /* 0xbe3be4 */ stp x22, x21, [sp, #0x30];
    /* 0xbe3be8 */ stp x20, x19, [sp, #0x40];
    /* 0xbe3bec */ add x29, sp, #0x20;
    /* 0xbe3bf0 */ mrs x21, tpidr_el0;
    /* 0xbe3bf4 */ mov x19, x0;
    /* 0xbe3bf8 */ ldr x8, [x21, #0x28];
    /* 0xbe3bfc */ stur x8, [x29, #-8];
    sub_f0cb90();
    /* 0xbe3c04 */ cmp w0, #1;
    /* 0xbe3c08 */ b.ne #0xbe3cac;
    sub_f0ce7c();
    sub_be2e88();
    sub_f0da98();
    sub_f0d500();
    sub_f0d500();
    sub_f0dc88();
    _ZdlPv();
    sub_f0d5d0();
    sub_f0e498();
    return x0;
    __stack_chk_fail();
}

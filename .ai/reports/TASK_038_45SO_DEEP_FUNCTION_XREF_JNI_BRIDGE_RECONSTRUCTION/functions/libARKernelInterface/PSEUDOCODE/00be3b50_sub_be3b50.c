// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xbe3b50
// Recovered Name: sub_be3b50
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xbe3b50 | Size: 144 bytes | SHA256: 9fdad860df80bad19b1615751fb9dfb84777e031d1a402f5b07619096cafca53
// Callers: 0 | Callees: 6 | Imports: 0

// Strings referenced:
//   "Invalid number of parameters (expected 1)."
//   "lua_ScriptHost_getSegmentType - Failed to match the given parameters to a valid function signature."

void sub_be3b50(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 36 instructions
    /* 0xbe3b50 */ stp x29, x30, [sp, #-0x20]!;
    /* 0xbe3b54 */ str x19, [sp, #0x10];
    /* 0xbe3b58 */ mov x29, sp;
    /* 0xbe3b5c */ mov x19, x0;
    sub_f0cb90();
    /* 0xbe3b64 */ cmp w0, #1;
    /* 0xbe3b68 */ b.ne #0xbe3ba8;
    /* 0xbe3b6c */ mov x0, x19;
    /* 0xbe3b70 */ mov w1, #1;
    sub_f0ce7c();
    /* 0xbe3b78 */ cmp w0, #7;
    sub_be2e88();
    sub_f0d500();
    sub_f0d5d0();
    sub_f0e498();
    return x0;
}

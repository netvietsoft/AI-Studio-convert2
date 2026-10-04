// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xbddf00
// Recovered Name: sub_bddf00
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xbddf00 | Size: 236 bytes | SHA256: 1de7aac358dca260762981aa95a4fe678e07b8a66ab48bcc32c8aa5357746928
// Callers: 0 | Callees: 11 | Imports: 0

// Strings referenced:
//   "Invalid number of parameters (expected 2)."
//   "TextureSampler"
//   "lua_GPGlobalState_getFaceHairMask - Failed to match the given parameters to a valid function signature."

void sub_bddf00(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 59 instructions
    /* 0xbddf00 */ stp x29, x30, [sp, #-0x20]!;
    /* 0xbddf04 */ stp x20, x19, [sp, #0x10];
    /* 0xbddf08 */ mov x29, sp;
    /* 0xbddf0c */ mov x19, x0;
    sub_f0cb90();
    /* 0xbddf14 */ cmp w0, #2;
    /* 0xbddf18 */ b.ne #0xbddfa8;
    /* 0xbddf1c */ mov x0, x19;
    /* 0xbddf20 */ mov w1, #1;
    sub_f0ce7c();
    /* 0xbddf28 */ cmp w0, #7;
    sub_f0ce7c();
    sub_f0f5a8();
    sub_bddc70();
    sub_6b0500();
    sub_f0e5b8();
    sub_f0d998();
    sub_f0de60();
    sub_f0d5d0();
    sub_f0e498();
    return x0;
    sub_f0d4cc();
}

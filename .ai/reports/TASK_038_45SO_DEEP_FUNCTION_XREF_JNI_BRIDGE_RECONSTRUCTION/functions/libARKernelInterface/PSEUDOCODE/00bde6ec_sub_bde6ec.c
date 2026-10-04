// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xbde6ec
// Recovered Name: sub_bde6ec
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xbde6ec | Size: 196 bytes | SHA256: 9c5daf05c264f444ac99202fd08beb542e9c5ce5d711afd20c8674f78dd93351
// Callers: 0 | Callees: 10 | Imports: 0

// Strings referenced:
//   "GPInstanceSegmentData"
//   "Invalid number of parameters (expected 1)."
//   "lua_GPGlobalState_getInstanceSegmentData - Failed to match the given parameters to a valid function signature."

void sub_bde6ec(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 49 instructions
    /* 0xbde6ec */ stp x29, x30, [sp, #-0x20]!;
    /* 0xbde6f0 */ stp x20, x19, [sp, #0x10];
    /* 0xbde6f4 */ mov x29, sp;
    /* 0xbde6f8 */ mov x19, x0;
    sub_f0cb90();
    /* 0xbde700 */ cmp w0, #1;
    /* 0xbde704 */ b.ne #0xbde76c;
    /* 0xbde708 */ mov x0, x19;
    /* 0xbde70c */ mov w1, #1;
    sub_f0ce7c();
    /* 0xbde714 */ cmp w0, #7;
    sub_bddc70();
    sub_6b260c();
    sub_f0e5b8();
    sub_f0d998();
    sub_f0de60();
    sub_f0d5d0();
    sub_f0e498();
    sub_f0d4cc();
    return x0;
}

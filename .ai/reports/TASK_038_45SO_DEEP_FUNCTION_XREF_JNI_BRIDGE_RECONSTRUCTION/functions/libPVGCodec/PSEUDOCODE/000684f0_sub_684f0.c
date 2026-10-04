// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x684f0
// Recovered Name: sub_684f0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x684f0 | Size: 44 bytes | SHA256: c99e7f8913d904aaa2723b9f9e3a692f333cb875018bd6992482de0b69ab7c5a
// Callers: 2 | Callees: 0 | Imports: 0


void sub_684f0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 11 instructions
    /* 0x684f0 */ movi v0.2d, #0000000000000000;
    /* 0x684f4 */ adrp x8, #0x139000;
    /* 0x684f8 */ add x8, x8, #0x168;
    /* 0x684fc */ str x8, [x0];
    /* 0x68500 */ adrp x8, #0x1e000;
    /* 0x68504 */ ldr d1, [x8, #0xd10];
    /* 0x68508 */ str xzr, [x0, #0x28];
    /* 0x6850c */ stur q0, [x0, #8];
    /* 0x68510 */ stur q0, [x0, #0x18];
    /* 0x68514 */ str d1, [x0, #0x30];
    return x0;
}

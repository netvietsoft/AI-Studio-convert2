// Library: libarkernel3.so
// Function ID: libarkernel3::0xce1df8
// Recovered Name: sub_ce1df8
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xce1df8 | Size: 212 bytes | SHA256: c0b949a1de4a8292d8fbd0401d27dd366648ed5206f0b73fa974f8f85bd5e9e2
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: __assert2, __memset_chk
// Strings referenced:
//   "/Users/zhichenzhang/meitu/Project/PVGThirdParty/libwebp/src/dec/vp8_dec.c"
//   "hdr != NULL"
//   "void ResetSegmentHeader(VP8SegmentHeader *const)"

void sub_ce1df8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 53 instructions
    /* 0xce1df8 */ stp x29, x30, [sp, #0x60];
    /* 0xce1dfc */ add x29, sp, #0x60;
    /* 0xce1e00 */ str x0, [sp, #0x18];
    /* 0xce1e04 */ ldr x8, [sp, #0x18];
    /* 0xce1e08 */ cbz x8, #0xce1e14;
    /* 0xce1e0c */ b #0xce1e10;
    /* 0xce1e10 */ b #0xce1e34;
    /* 0xce1e14 */ adrp x0, #0x25a000;
    /* 0xce1e18 */ add x0, x0, #0x2c0;
    /* 0xce1e1c */ mov w1, #0x97;
    /* 0xce1e20 */ adrp x2, #0x270000;
    __assert2();
    __memset_chk();
    __memset_chk();
    return x0;
}

// Library: libARSPM.so
// Function ID: libARSPM::0x252990
// Recovered Name: sub_252990
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x252990 | Size: 68 bytes | SHA256: ca0f6e95cb4c82e4fc939ae9edb0a3c43b32d252dd1a3d68f189c241670bfc66
// Callers: 1 | Callees: 1 | Imports: 0

// Strings referenced:
//   "SkBlurImageFilter"
//   "SkBlurImageFilterImpl"

void sub_252990(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 17 instructions
    /* 0x252990 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x252994 */ str x19, [sp, #0x10];
    /* 0x252998 */ mov x29, sp;
    /* 0x25299c */ nop ;
    /* 0x2529a0 */ adr x19, #0x2529cc;
    /* 0x2529a4 */ adrp x0, #0x4a000;
    /* 0x2529a8 */ add x0, x0, #0x9d2;
    /* 0x2529ac */ mov x1, x19;
    sub_15ac60();
    /* 0x2529b4 */ adrp x0, #0x57000;
    /* 0x2529b8 */ add x0, x0, #0xa5f;
}

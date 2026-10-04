// Library: libARSPM.so
// Function ID: libARSPM::0x252b74
// Recovered Name: sub_252b74
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x252b74 | Size: 60 bytes | SHA256: c09f4e0b81c2a79b6d08f61251905270d1a679a6d4a5546b01d27eccb2cc02e3
// Callers: 0 | Callees: 1 | Imports: 1

// Calls external APIs: _ZdlPv
// Strings referenced:
//   "SkBlurImageFilter"

void sub_252b74(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 15 instructions
    /* 0x252b74 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x252b78 */ str x19, [sp, #0x10];
    /* 0x252b7c */ mov x29, sp;
    /* 0x252b80 */ mov x19, x0;
    sub_15f858();
    /* 0x252b88 */ mov x0, x19;
    /* 0x252b8c */ ldr x19, [sp, #0x10];
    /* 0x252b90 */ ldp x29, x30, [sp], #0x20;
    /* 0x252b94 */ b #0x4f0a00;
    /* 0x252b98 */ nop ;
    /* 0x252b9c */ adr x0, #0x2529cc;
    return x0;
    return x0;
}

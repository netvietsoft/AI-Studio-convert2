// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x11f800
// Recovered Name: sub_11f800
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x11f800 | Size: 64 bytes | SHA256: 441ff37d977e8266433a88309fbb2693dd2fd7f3dca5125f65309d70ac4d0034
// Callers: 0 | Callees: 1 | Imports: 3

// Dynamic Registration: native_setup()J (table at 0x13a610)
// Calls external APIs: _ZN3PVG11MediaConcatC1Ev, _ZdlPv, _Znwm

jlong sub_11f800(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 16 instructions
    /* 0x11f800 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x11f804 */ stp x20, x19, [sp, #0x10];
    /* 0x11f808 */ mov x29, sp;
    /* 0x11f80c */ mov w0, #0x50;
    _Znwm();
    /* 0x11f814 */ mov x19, x0;
    _ZN3PVG11MediaConcatC1Ev();
    /* 0x11f81c */ mov x0, x19;
    /* 0x11f820 */ ldp x20, x19, [sp, #0x10];
    /* 0x11f824 */ ldp x29, x30, [sp], #0x20;
    return x0;
    _ZdlPv();
    sub_12eab4();
}

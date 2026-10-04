// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x119744
// Recovered Name: sub_119744
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x119744 | Size: 64 bytes | SHA256: b80634dab0512f271443d2e31d8edb02c066b2ed80ec73458a9edf5b36ae8ec8
// Callers: 0 | Callees: 1 | Imports: 3

// Dynamic Registration: native_setup()J (table at 0x13a0a8)
// Calls external APIs: _ZN3PVG17PVGAudioExtractorC1Ev, _ZdlPv, _Znwm

jlong sub_119744(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 16 instructions
    /* 0x119744 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x119748 */ stp x20, x19, [sp, #0x10];
    /* 0x11974c */ mov x29, sp;
    /* 0x119750 */ mov w0, #0xa0;
    _Znwm();
    /* 0x119758 */ mov x19, x0;
    _ZN3PVG17PVGAudioExtractorC1Ev();
    /* 0x119760 */ mov x0, x19;
    /* 0x119764 */ ldp x20, x19, [sp, #0x10];
    /* 0x119768 */ ldp x29, x30, [sp], #0x20;
    return x0;
    _ZdlPv();
    sub_12eab4();
}

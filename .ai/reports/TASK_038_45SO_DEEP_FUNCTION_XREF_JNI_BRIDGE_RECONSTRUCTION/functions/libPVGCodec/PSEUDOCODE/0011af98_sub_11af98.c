// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x11af98
// Recovered Name: sub_11af98
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x11af98 | Size: 64 bytes | SHA256: 039b151974a1fdab716d8db91afd4747a5fc48710e8d869cb8b285c08aab529a
// Callers: 0 | Callees: 1 | Imports: 3

// Dynamic Registration: native_setup()J (table at 0x13a198)
// Calls external APIs: _ZN3PVG19PVGExtractVideoClipC1Ev, _ZdlPv, _Znwm

jlong sub_11af98(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 16 instructions
    /* 0x11af98 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x11af9c */ stp x20, x19, [sp, #0x10];
    /* 0x11afa0 */ mov x29, sp;
    /* 0x11afa4 */ mov w0, #0x70;
    _Znwm();
    /* 0x11afac */ mov x19, x0;
    _ZN3PVG19PVGExtractVideoClipC1Ev();
    /* 0x11afb4 */ mov x0, x19;
    /* 0x11afb8 */ ldp x20, x19, [sp, #0x10];
    /* 0x11afbc */ ldp x29, x30, [sp], #0x20;
    return x0;
    _ZdlPv();
    sub_12eab4();
}

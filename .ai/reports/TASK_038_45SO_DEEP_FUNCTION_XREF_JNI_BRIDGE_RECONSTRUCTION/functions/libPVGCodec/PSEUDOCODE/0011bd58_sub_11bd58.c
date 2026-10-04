// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x11bd58
// Recovered Name: sub_11bd58
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x11bd58 | Size: 64 bytes | SHA256: d574d0eef740dcc05587a2719afcee249d3167fe0bd800eac48362614f555f74
// Callers: 0 | Callees: 1 | Imports: 3

// Dynamic Registration: native_setup()J (table at 0x13a290)
// Calls external APIs: _ZN3PVG14PVGGifMetaDataC1Ev, _ZdlPv, _Znwm

jlong sub_11bd58(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 16 instructions
    /* 0x11bd58 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x11bd5c */ stp x20, x19, [sp, #0x10];
    /* 0x11bd60 */ mov x29, sp;
    /* 0x11bd64 */ mov w0, #0x30;
    _Znwm();
    /* 0x11bd6c */ mov x19, x0;
    _ZN3PVG14PVGGifMetaDataC1Ev();
    /* 0x11bd74 */ mov x0, x19;
    /* 0x11bd78 */ ldp x20, x19, [sp, #0x10];
    /* 0x11bd7c */ ldp x29, x30, [sp], #0x20;
    return x0;
    _ZdlPv();
    sub_12eab4();
}

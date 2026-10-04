// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x11ecb0
// Recovered Name: sub_11ecb0
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x11ecb0 | Size: 64 bytes | SHA256: 763458df953c577a7ec495bf58cebd855735d3f533591c3b1207dbb4da7384e3
// Callers: 0 | Callees: 1 | Imports: 3

// Dynamic Registration: native_setup()J (table at 0x13a580)
// Calls external APIs: _ZN3PVG13MediaCombinerC1Ev, _ZdlPv, _Znwm

jlong sub_11ecb0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 16 instructions
    /* 0x11ecb0 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x11ecb4 */ stp x20, x19, [sp, #0x10];
    /* 0x11ecb8 */ mov x29, sp;
    /* 0x11ecbc */ mov w0, #0xe0;
    _Znwm();
    /* 0x11ecc4 */ mov x19, x0;
    _ZN3PVG13MediaCombinerC1Ev();
    /* 0x11eccc */ mov x0, x19;
    /* 0x11ecd0 */ ldp x20, x19, [sp, #0x10];
    /* 0x11ecd4 */ ldp x29, x30, [sp], #0x20;
    return x0;
    _ZdlPv();
    sub_12eab4();
}

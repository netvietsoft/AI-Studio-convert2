// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x11dfe0
// Recovered Name: sub_11dfe0
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x11dfe0 | Size: 64 bytes | SHA256: 9cc3a47515eb9ae54b29479f41a72c8903720ab2bbaba3a45092834f1043fea8
// Callers: 0 | Callees: 1 | Imports: 3

// Dynamic Registration: native_setup()J (table at 0x13a4d8)
// Calls external APIs: _ZN3PVG12MediaClipperC1Ev, _ZdlPv, _Znwm

jlong sub_11dfe0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 16 instructions
    /* 0x11dfe0 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x11dfe4 */ stp x20, x19, [sp, #0x10];
    /* 0x11dfe8 */ mov x29, sp;
    /* 0x11dfec */ mov w0, #0x88;
    _Znwm();
    /* 0x11dff4 */ mov x19, x0;
    _ZN3PVG12MediaClipperC1Ev();
    /* 0x11dffc */ mov x0, x19;
    /* 0x11e000 */ ldp x20, x19, [sp, #0x10];
    /* 0x11e004 */ ldp x29, x30, [sp], #0x20;
    return x0;
    _ZdlPv();
    sub_12eab4();
}

// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x12133c
// Recovered Name: sub_12133c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x12133c | Size: 64 bytes | SHA256: b3d79381dd532de22394524c40234eb9901adcd3c23edd71d75e471b1a7c764c
// Callers: 0 | Callees: 1 | Imports: 3

// Dynamic Registration: native_setup()J (table at 0x13a7d8)
// Calls external APIs: _ZN3PVG13MediaReverserC1Ev, _ZdlPv, _Znwm

jlong sub_12133c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 16 instructions
    /* 0x12133c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x121340 */ stp x20, x19, [sp, #0x10];
    /* 0x121344 */ mov x29, sp;
    /* 0x121348 */ mov w0, #0xb8;
    _Znwm();
    /* 0x121350 */ mov x19, x0;
    _ZN3PVG13MediaReverserC1Ev();
    /* 0x121358 */ mov x0, x19;
    /* 0x12135c */ ldp x20, x19, [sp, #0x10];
    /* 0x121360 */ ldp x29, x30, [sp], #0x20;
    return x0;
    _ZdlPv();
    sub_12eab4();
}

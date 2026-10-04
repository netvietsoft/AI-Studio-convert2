// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x11cfd4
// Recovered Name: sub_11cfd4
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x11cfd4 | Size: 40 bytes | SHA256: b747ec7f8e955b5cb74197dd00f531fbdf1514b578689b61d034accb1c1239bb
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: setLogCallbackLevel(I)V (table at 0x13a350)
// Calls external APIs: _ZN3PVG9PVGGlobal11getInstanceEv, _ZN3PVG9PVGGlobal19setLogCallbackLevelEi

jlong sub_11cfd4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 10 instructions
    /* 0x11cfd4 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x11cfd8 */ str x19, [sp, #0x10];
    /* 0x11cfdc */ mov x29, sp;
    /* 0x11cfe0 */ mov w19, w2;
    _ZN3PVG9PVGGlobal11getInstanceEv();
    /* 0x11cfe8 */ mov w1, w19;
    /* 0x11cfec */ ldr x19, [sp, #0x10];
    /* 0x11cff0 */ ldp x29, x30, [sp], #0x20;
    /* 0x11cff4 */ b #0x1341c0;
    /* 0x11cff8 */ sub sp, sp, #0xb0;
}

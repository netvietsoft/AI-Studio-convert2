// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x11cfb0
// Recovered Name: sub_11cfb0
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x11cfb0 | Size: 36 bytes | SHA256: f24a675e60faece93f3f5cbcb86f3025b5530b0ff30ea44cf1a91a73f16d67eb
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: setLogLevel(I)V (table at 0x13a338)
// Calls external APIs: _ZN3PVG9PVGGlobal11getInstanceEv, _ZN3PVG9PVGGlobal11setLogLevelENS_11PVGLogLevelE

jlong sub_11cfb0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x11cfb0 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x11cfb4 */ str x19, [sp, #0x10];
    /* 0x11cfb8 */ mov x29, sp;
    /* 0x11cfbc */ mov w19, w2;
    _ZN3PVG9PVGGlobal11getInstanceEv();
    /* 0x11cfc4 */ mov w1, w19;
    /* 0x11cfc8 */ ldr x19, [sp, #0x10];
    /* 0x11cfcc */ ldp x29, x30, [sp], #0x20;
    /* 0x11cfd0 */ b #0x133a80;
}

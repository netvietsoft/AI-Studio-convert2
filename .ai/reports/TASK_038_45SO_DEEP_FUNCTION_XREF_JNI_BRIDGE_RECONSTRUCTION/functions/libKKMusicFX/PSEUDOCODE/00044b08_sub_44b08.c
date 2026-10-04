// Library: libKKMusicFX.so
// Function ID: libKKMusicFX::0x44b08
// Recovered Name: sub_44b08
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x44b08 | Size: 64 bytes | SHA256: d5dc2c630ae15f33e16b352b4f5c16156723af093408371a88ea9119d937ad84
// Callers: 0 | Callees: 1 | Imports: 3

// Dynamic Registration: _initNative()J (table at 0x7f8e8)
// Calls external APIs: _ZN3MFX11EqualizerFXC1Ev, _ZdlPv, _Znwm

jlong sub_44b08(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 16 instructions
    /* 0x44b08 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x44b0c */ stp x20, x19, [sp, #0x10];
    /* 0x44b10 */ mov x29, sp;
    /* 0x44b14 */ mov w0, #0xb8;
    _Znwm();
    /* 0x44b1c */ mov x19, x0;
    _ZN3MFX11EqualizerFXC1Ev();
    /* 0x44b24 */ mov x0, x19;
    /* 0x44b28 */ ldp x20, x19, [sp, #0x10];
    /* 0x44b2c */ ldp x29, x30, [sp], #0x20;
    return x0;
    _ZdlPv();
    sub_76b64();
}

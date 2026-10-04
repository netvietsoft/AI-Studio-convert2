// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d40c0
// Recovered Name: _ZN11LayerFlowNS23LFEffectWakeSkinDataJNI17nCreateBeautyGlowEP7_JNIEnvP7_jclass
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d40c0 | Size: 32 bytes | SHA256: 4456303268dd2451c614755b3073bc6dc0daa838b679530fc5f1644cd2c95b92
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nCreateBeautyGlow()J (table at 0x535708)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS23LFEffectWakeSkinDataJNI17nCreateBeautyGlowEP7_JNIEnvP7_jclass(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x2d40c0 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x2d40c4 */ mov x29, sp;
    /* 0x2d40c8 */ mov w0, #0x18;
    _Znwm();
    /* 0x2d40d0 */ stp xzr, xzr, [x0, #8];
    /* 0x2d40d4 */ str xzr, [x0];
    /* 0x2d40d8 */ ldp x29, x30, [sp], #0x10;
    return x0;
}

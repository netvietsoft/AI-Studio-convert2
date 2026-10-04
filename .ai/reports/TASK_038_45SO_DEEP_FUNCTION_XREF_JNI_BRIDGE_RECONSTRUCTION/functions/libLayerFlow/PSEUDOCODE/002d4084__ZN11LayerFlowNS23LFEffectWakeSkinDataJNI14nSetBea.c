// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d4084
// Recovered Name: _ZN11LayerFlowNS23LFEffectWakeSkinDataJNI14nSetBeautyGlowEP7_JNIEnvP7_jclassll
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d4084 | Size: 60 bytes | SHA256: e51202d71ca0d7eca74a896f37aa38f68d04ad78b7cc9eb885fc5b3e6b6ef5da
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetBeautyGlow(JJ)V (table at 0x535648)

jobject _ZN11LayerFlowNS23LFEffectWakeSkinDataJNI14nSetBeautyGlowEP7_JNIEnvP7_jclassll(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 15 instructions
    /* 0x2d4084 */ cbz x3, #0x2d40a4;
    /* 0x2d4088 */ ldr q0, [x3];
    /* 0x2d408c */ ldrb w8, [x2, #0x78];
    /* 0x2d4090 */ ldr x9, [x3, #0x10];
    /* 0x2d4094 */ str q0, [x2, #0x60];
    /* 0x2d4098 */ str x9, [x2, #0x70];
    /* 0x2d409c */ cbz w8, #0x2d40b4;
    return x0;
    /* 0x2d40a4 */ ldrb w8, [x2, #0x78];
    /* 0x2d40a8 */ cbz w8, #0x2d40a0;
    /* 0x2d40ac */ strb wzr, [x2, #0x78];
    return x0;
    return x0;
}

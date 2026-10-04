// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d20a8
// Recovered Name: _ZN11LayerFlowNS29LFEffectOneClickBeautyDataJNI12nsetMaterialEP7_JNIEnvP7_jclassll
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d20a8 | Size: 20 bytes | SHA256: 1a6b68378b3f856b9d5ebef7d9453a0971b193c0f54883e4cbcebf2b1b734598
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nsetMaterial(JJ)V (table at 0x534c28)

jobject _ZN11LayerFlowNS29LFEffectOneClickBeautyDataJNI12nsetMaterialEP7_JNIEnvP7_jclassll(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x2d20a8 */ ldrb w8, [x3, #0x10];
    /* 0x2d20ac */ ldr q0, [x3];
    /* 0x2d20b0 */ strb w8, [x2, #0x10];
    /* 0x2d20b4 */ str q0, [x2];
    return x0;
}

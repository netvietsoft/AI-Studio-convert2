// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d2074
// Recovered Name: _ZN11LayerFlowNS29LFEffectOneClickBeautyDataJNI12nGetMaterialEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d2074 | Size: 52 bytes | SHA256: dc0a588e25675a5d6cfd532cf29b7f5b91a6f14597a02e62ea1e5b398c0fa494
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nGetMaterial(J)J (table at 0x534c10)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS29LFEffectOneClickBeautyDataJNI12nGetMaterialEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 13 instructions
    /* 0x2d2074 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2d2078 */ str x19, [sp, #0x10];
    /* 0x2d207c */ mov x29, sp;
    /* 0x2d2080 */ mov w0, #0x18;
    /* 0x2d2084 */ mov x19, x2;
    _Znwm();
    /* 0x2d208c */ ldr q0, [x19];
    /* 0x2d2090 */ ldr x8, [x19, #0x10];
    /* 0x2d2094 */ str q0, [x0];
    /* 0x2d2098 */ str x8, [x0, #0x10];
    /* 0x2d209c */ ldr x19, [sp, #0x10];
    return x0;
}

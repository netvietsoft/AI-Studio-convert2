// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d1efc
// Recovered Name: _ZN11LayerFlowNS29LFEffectOneClickBeautyDataJNI11nCreateInfoEP7_JNIEnvP7_jclass
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d1efc | Size: 84 bytes | SHA256: c820ba485304603d9650ad986e143e8494dd60bebb65f7b5713e1f6994b6089b
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nCreate()J (table at 0x534a30)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS29LFEffectOneClickBeautyDataJNI11nCreateInfoEP7_JNIEnvP7_jclass(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 21 instructions
    /* 0x2d1efc */ stp x29, x30, [sp, #-0x10]!;
    /* 0x2d1f00 */ mov x29, sp;
    /* 0x2d1f04 */ mov w0, #0x60;
    _Znwm();
    /* 0x2d1f0c */ movi v0.2d, #0000000000000000;
    /* 0x2d1f10 */ mov w9, #1;
    /* 0x2d1f14 */ mov w8, #-1;
    /* 0x2d1f18 */ stp xzr, xzr, [x0, #0x50];
    /* 0x2d1f1c */ str q0, [x0, #0x40];
    /* 0x2d1f20 */ stp q0, q0, [x0];
    /* 0x2d1f24 */ stp q0, q0, [x0, #0x20];
    return x0;
}

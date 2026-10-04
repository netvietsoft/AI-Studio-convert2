// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2ca0f8
// Recovered Name: _ZN11LayerFlowNS24LFEffectBodyShapeDataJNI13nSetAigcAlphaEP7_JNIEnvP7_jclassld
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2ca0f8 | Size: 56 bytes | SHA256: 13c8ced785d14112972802aaeaad8b6a2cdf362d5e294b12f21bcaaaf52857aa
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nSetAigcAlpha(JD)V (table at 0x533620)
// Calls external APIs: __android_log_print
// Strings referenced:
//   "BodyShapeModel set aigcAlpha, type=%d, materialId=%lld, alpha=%f, aigcAlpha=%f, faceId=%d, bgProtect=%d"

jobject _ZN11LayerFlowNS24LFEffectBodyShapeDataJNI13nSetAigcAlphaEP7_JNIEnvP7_jclassld(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 14 instructions
    /* 0x2ca0f8 */ fmov d1, d0;
    /* 0x2ca0fc */ ldr w3, [x2];
    /* 0x2ca100 */ ldr x4, [x2, #0x20];
    /* 0x2ca104 */ ldr d0, [x2, #8];
    /* 0x2ca108 */ ldr w5, [x2, #0x28];
    /* 0x2ca10c */ mov x8, x2;
    /* 0x2ca110 */ ldrb w6, [x2, #0x18];
    /* 0x2ca114 */ nop ;
    /* 0x2ca118 */ adr x1, #0x1e1361;
    /* 0x2ca11c */ adrp x2, #0x1eb000;
    /* 0x2ca120 */ add x2, x2, #0x8af;
}

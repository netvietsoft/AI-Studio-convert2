// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2ca18c
// Recovered Name: _ZN11LayerFlowNS24LFEffectBodyShapeDataJNI15nSetModelFaceIdEP7_JNIEnvP7_jclassli
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2ca18c | Size: 52 bytes | SHA256: 71c0fbf2ee75397c8b090bc59f11fca052117b99d0db4f62daa6b7d1c8983b23
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nSetFaceId(JI)V (table at 0x5336b0)
// Calls external APIs: __android_log_print
// Strings referenced:
//   "BodyShapeModel set faceId, type=%d, materialId=%lld, alpha=%f, aigcAlpha=%f, faceId=%d, bgProtect=%d"

jobject _ZN11LayerFlowNS24LFEffectBodyShapeDataJNI15nSetModelFaceIdEP7_JNIEnvP7_jclassli(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 13 instructions
    /* 0x2ca18c */ ldp d0, d1, [x2, #8];
    /* 0x2ca190 */ mov w5, w3;
    /* 0x2ca194 */ ldr w3, [x2];
    /* 0x2ca198 */ ldr x4, [x2, #0x20];
    /* 0x2ca19c */ mov x8, x2;
    /* 0x2ca1a0 */ ldrb w6, [x2, #0x18];
    /* 0x2ca1a4 */ nop ;
    /* 0x2ca1a8 */ adr x1, #0x1e1361;
    /* 0x2ca1ac */ adrp x2, #0x1dc000;
    /* 0x2ca1b0 */ add x2, x2, #0xf5e;
    /* 0x2ca1b4 */ mov w0, #4;
}

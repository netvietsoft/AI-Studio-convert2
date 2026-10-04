// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2ca150
// Recovered Name: _ZN11LayerFlowNS24LFEffectBodyShapeDataJNI14nSetMaterialIdEP7_JNIEnvP7_jclassll
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2ca150 | Size: 52 bytes | SHA256: 48d93abce39103d748adba2d400846a949aefe55f261ce612aed14f1ceb2bd66
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nSetMaterialId(JJ)V (table at 0x533680)
// Calls external APIs: __android_log_print
// Strings referenced:
//   "BodyShapeModel set materialId, type=%d, materialId=%lld, alpha=%f, aigcAlpha=%f, faceId=%d, bgProtect=%d"

jobject _ZN11LayerFlowNS24LFEffectBodyShapeDataJNI14nSetMaterialIdEP7_JNIEnvP7_jclassll(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 13 instructions
    /* 0x2ca150 */ ldp d0, d1, [x2, #8];
    /* 0x2ca154 */ mov x4, x3;
    /* 0x2ca158 */ ldr w3, [x2];
    /* 0x2ca15c */ ldr w5, [x2, #0x28];
    /* 0x2ca160 */ mov x8, x2;
    /* 0x2ca164 */ ldrb w6, [x2, #0x18];
    /* 0x2ca168 */ nop ;
    /* 0x2ca16c */ adr x1, #0x1e1361;
    /* 0x2ca170 */ adrp x2, #0x1ee000;
    /* 0x2ca174 */ add x2, x2, #0xad5;
    /* 0x2ca178 */ mov w0, #4;
}

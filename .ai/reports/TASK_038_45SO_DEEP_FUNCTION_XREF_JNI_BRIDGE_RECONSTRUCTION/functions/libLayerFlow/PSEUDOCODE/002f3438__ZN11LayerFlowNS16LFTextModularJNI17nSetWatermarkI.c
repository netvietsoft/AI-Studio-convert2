// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2f3438
// Recovered Name: _ZN11LayerFlowNS16LFTextModularJNI17nSetWatermarkInfoEP7_JNIEnvP8_jobjectll
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2f3438 | Size: 32 bytes | SHA256: da9b820b5d47a055b79793e9995dc4ee62d7b6b0389e86afccbc8743bd1f12b8
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetWatermarkInfo(JJ)V (table at 0x53b1b8)

jobject _ZN11LayerFlowNS16LFTextModularJNI17nSetWatermarkInfoEP7_JNIEnvP8_jobjectll(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x2f3438 */ ldp q2, q0, [x3, #0x10];
    /* 0x2f343c */ ldr x8, [x3, #0x30];
    /* 0x2f3440 */ ldr q1, [x3];
    /* 0x2f3444 */ str x8, [x2, #0xa8];
    /* 0x2f3448 */ stur q0, [x2, #0x98];
    /* 0x2f344c */ stur q2, [x2, #0x88];
    /* 0x2f3450 */ stur q1, [x2, #0x78];
    return x0;
}

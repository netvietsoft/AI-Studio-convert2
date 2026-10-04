// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3bfe90
// Recovered Name: _ZN11LayerFlowNS24LFCreativeStickerInfoJNI23nSetStickerLocateStatusEP7_JNIEnvP8_jobjectll
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x3bfe90 | Size: 20 bytes | SHA256: 7bb7e6df82d80fe8ae885309c5f888cc96010b1b8f7e6edb2f6723bae717c7a2
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetStickerLocateStatus(JJ)V (table at 0x540210)

jobject _ZN11LayerFlowNS24LFCreativeStickerInfoJNI23nSetStickerLocateStatusEP7_JNIEnvP8_jobjectll(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x3bfe90 */ ldp q1, q0, [x3];
    /* 0x3bfe94 */ ldr w8, [x3, #0x20];
    /* 0x3bfe98 */ str w8, [x2, #0x50];
    /* 0x3bfe9c */ stp q1, q0, [x2, #0x30];
    return x0;
}

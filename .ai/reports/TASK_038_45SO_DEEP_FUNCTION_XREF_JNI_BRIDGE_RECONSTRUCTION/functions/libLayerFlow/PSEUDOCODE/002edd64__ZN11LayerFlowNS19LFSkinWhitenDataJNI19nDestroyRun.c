// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2edd64
// Recovered Name: _ZN11LayerFlowNS19LFSkinWhitenDataJNI19nDestroyRuntimeDataEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2edd64 | Size: 16 bytes | SHA256: 6a8c2575c6d58124353b96b4545e162463cb4b09875272c4c3b2559ca32dfb65
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nDestroy(J)V (table at 0x539528)
// Calls external APIs: _ZdlPv

jobject _ZN11LayerFlowNS19LFSkinWhitenDataJNI19nDestroyRuntimeDataEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2edd64 */ cbz x2, #0x2edd70;
    /* 0x2edd68 */ mov x0, x2;
    /* 0x2edd6c */ b #0x52a280;
    return x0;
}

// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2e6a00
// Recovered Name: _ZN11LayerFlowNS23LFLiveStickerModularJNI17nModularSetIsLiveEP7_JNIEnvP8_jobjectlh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2e6a00 | Size: 16 bytes | SHA256: 8e2f3c58e1cea637aa223ea19229a2ac9592935a41f962dfb1d010b4fe2a3b47
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nModularSetIsLive(JZ)V (table at 0x538548)

jobject _ZN11LayerFlowNS23LFLiveStickerModularJNI17nModularSetIsLiveEP7_JNIEnvP8_jobjectlh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2e6a00 */ tst w3, #0xff;
    /* 0x2e6a04 */ cset w8, ne;
    /* 0x2e6a08 */ strb w8, [x2, #0x50];
    return x0;
}

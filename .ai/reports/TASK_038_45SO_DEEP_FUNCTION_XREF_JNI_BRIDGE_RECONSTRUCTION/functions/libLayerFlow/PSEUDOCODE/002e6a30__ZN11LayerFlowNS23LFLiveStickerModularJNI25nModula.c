// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2e6a30
// Recovered Name: _ZN11LayerFlowNS23LFLiveStickerModularJNI25nModularSetHorizontalFlipEP7_JNIEnvP8_jobjectlh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2e6a30 | Size: 16 bytes | SHA256: 474afb84b9475d740f2f3819704317548d77bdb9e864b0e3278e83cfa9a23cc5
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nModularSetHorizontalFlip(JZ)V (table at 0x5385a8)

jobject _ZN11LayerFlowNS23LFLiveStickerModularJNI25nModularSetHorizontalFlipEP7_JNIEnvP8_jobjectlh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2e6a30 */ tst w3, #0xff;
    /* 0x2e6a34 */ cset w8, ne;
    /* 0x2e6a38 */ strb w8, [x2, #0x52];
    return x0;
}

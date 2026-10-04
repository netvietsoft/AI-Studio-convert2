// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2f0788
// Recovered Name: _ZN11LayerFlowNS19LFStickerModularJNI16nSetVerticalFlipEP7_JNIEnvP8_jobjectlh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2f0788 | Size: 16 bytes | SHA256: 8cd13be423c99c506a23b86751239fdb08a00dbd3a6203e8e15361882e683066
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetVerticalFlip(JZ)V (table at 0x53a140)

jobject _ZN11LayerFlowNS19LFStickerModularJNI16nSetVerticalFlipEP7_JNIEnvP8_jobjectlh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2f0788 */ tst w3, #0xff;
    /* 0x2f078c */ cset w8, ne;
    /* 0x2f0790 */ strb w8, [x2, #0x51];
    return x0;
}

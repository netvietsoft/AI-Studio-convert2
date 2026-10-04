// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2f0bd8
// Recovered Name: _ZN11LayerFlowNS19LFStickerModularJNI15nSetIsStretchedEP7_JNIEnvP8_jobjectlh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2f0bd8 | Size: 16 bytes | SHA256: 90a728bd66076c1c2a7123431835570b90d4685737297dad65f03625edba232d
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetIsStretched(JZ)V (table at 0x53a320)

jobject _ZN11LayerFlowNS19LFStickerModularJNI15nSetIsStretchedEP7_JNIEnvP8_jobjectlh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2f0bd8 */ tst w3, #0xff;
    /* 0x2f0bdc */ cset w8, ne;
    /* 0x2f0be0 */ strb w8, [x2, #0xc4];
    return x0;
}

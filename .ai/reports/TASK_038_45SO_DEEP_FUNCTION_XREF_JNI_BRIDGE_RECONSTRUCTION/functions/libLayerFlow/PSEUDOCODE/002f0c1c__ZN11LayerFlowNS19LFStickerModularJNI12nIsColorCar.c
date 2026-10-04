// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2f0c1c
// Recovered Name: _ZN11LayerFlowNS19LFStickerModularJNI12nIsColorCardEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2f0c1c | Size: 16 bytes | SHA256: d16790510058f60fd6a64f4341e5a0f8e0faa17926419a8f3cbaacf2e44a2b3b
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nIsColorCard(J)Z (table at 0x53a3b0)

jobject _ZN11LayerFlowNS19LFStickerModularJNI12nIsColorCardEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2f0c1c */ ldr w8, [x2, #0xc0];
    /* 0x2f0c20 */ cmp w8, #3;
    /* 0x2f0c24 */ cset w0, eq;
    return x0;
}

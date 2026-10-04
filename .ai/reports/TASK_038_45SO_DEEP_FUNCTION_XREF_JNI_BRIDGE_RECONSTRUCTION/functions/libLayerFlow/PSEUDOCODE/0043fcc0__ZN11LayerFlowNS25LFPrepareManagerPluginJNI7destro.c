// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x43fcc0
// Recovered Name: _ZN11LayerFlowNS25LFPrepareManagerPluginJNI7destroyEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x43fcc0 | Size: 24 bytes | SHA256: 6c7b6b31556e275d8969e0b5f15964139d49ddda128e289fcae4a94737dbedfa
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nDestroy(J)V (table at 0x545de8)

jobject _ZN11LayerFlowNS25LFPrepareManagerPluginJNI7destroyEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x43fcc0 */ cbz x2, #0x43fcd4;
    /* 0x43fcc4 */ ldr x8, [x2];
    /* 0x43fcc8 */ mov x0, x2;
    /* 0x43fccc */ ldr x1, [x8, #8];
    /* 0x43fcd0 */ br x1;
    return x0;
}

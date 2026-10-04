// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3d264c
// Recovered Name: _ZN11LayerFlowNS18LFGenericPluginJNI7destroyEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x3d264c | Size: 24 bytes | SHA256: 6c7b6b31556e275d8969e0b5f15964139d49ddda128e289fcae4a94737dbedfa
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nDestroy(J)V (table at 0x541d60)

jobject _ZN11LayerFlowNS18LFGenericPluginJNI7destroyEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x3d264c */ cbz x2, #0x3d2660;
    /* 0x3d2650 */ ldr x8, [x2];
    /* 0x3d2654 */ mov x0, x2;
    /* 0x3d2658 */ ldr x1, [x8, #8];
    /* 0x3d265c */ br x1;
    return x0;
}

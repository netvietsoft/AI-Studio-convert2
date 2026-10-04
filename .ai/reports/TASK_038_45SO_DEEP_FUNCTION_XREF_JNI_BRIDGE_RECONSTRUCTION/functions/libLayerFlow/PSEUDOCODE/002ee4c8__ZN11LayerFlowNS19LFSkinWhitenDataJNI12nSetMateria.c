// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2ee4c8
// Recovered Name: _ZN11LayerFlowNS19LFSkinWhitenDataJNI12nSetMaterialEP7_JNIEnvP7_jclassll
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2ee4c8 | Size: 20 bytes | SHA256: a0a24feaadc3293eec3511d51dc744a6e16895a3d89195755fdc10b05259def3
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetMaterial(JJ)V (table at 0x539708)

jobject _ZN11LayerFlowNS19LFSkinWhitenDataJNI12nSetMaterialEP7_JNIEnvP7_jclassll(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x2ee4c8 */ ldrb w8, [x3, #8];
    /* 0x2ee4cc */ ldr x9, [x3];
    /* 0x2ee4d0 */ strb w8, [x2, #8];
    /* 0x2ee4d4 */ str x9, [x2];
    return x0;
}

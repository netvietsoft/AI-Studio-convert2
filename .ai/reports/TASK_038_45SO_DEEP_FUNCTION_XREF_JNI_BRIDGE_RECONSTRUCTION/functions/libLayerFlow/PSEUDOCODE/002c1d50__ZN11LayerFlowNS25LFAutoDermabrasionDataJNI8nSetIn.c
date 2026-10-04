// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2c1d50
// Recovered Name: _ZN11LayerFlowNS25LFAutoDermabrasionDataJNI8nSetInfoEP7_JNIEnvP7_jclassll
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2c1d50 | Size: 20 bytes | SHA256: 3a4739182fdb44a75871ea9ee50b037e33f519f840695633852bf668cc6f6213
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetInfo(JJ)V (table at 0x531e38)

jobject _ZN11LayerFlowNS25LFAutoDermabrasionDataJNI8nSetInfoEP7_JNIEnvP7_jclassll(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x2c1d50 */ ldr w8, [x3, #8];
    /* 0x2c1d54 */ ldr x9, [x3];
    /* 0x2c1d58 */ str w8, [x2, #0x28];
    /* 0x2c1d5c */ str x9, [x2, #0x20];
    return x0;
}

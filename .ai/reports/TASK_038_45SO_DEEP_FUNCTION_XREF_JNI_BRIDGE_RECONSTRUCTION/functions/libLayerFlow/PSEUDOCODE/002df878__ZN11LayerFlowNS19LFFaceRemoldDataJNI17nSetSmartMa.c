// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2df878
// Recovered Name: _ZN11LayerFlowNS19LFFaceRemoldDataJNI17nSetSmartMaterialEP7_JNIEnvP7_jclassll
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2df878 | Size: 24 bytes | SHA256: 0b899f0011669e961d8701088038990a8b8e08af7803c45d311e597d79e8dc4a
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetSmartMaterial(JJ)V (table at 0x537810)

jobject _ZN11LayerFlowNS19LFFaceRemoldDataJNI17nSetSmartMaterialEP7_JNIEnvP7_jclassll(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x2df878 */ ldp q1, q0, [x3];
    /* 0x2df87c */ ldr w8, [x3, #0x20];
    /* 0x2df880 */ str w8, [x2, #0x38];
    /* 0x2df884 */ stur q0, [x2, #0x28];
    /* 0x2df888 */ stur q1, [x2, #0x18];
    return x0;
}

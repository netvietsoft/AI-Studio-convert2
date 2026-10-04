// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2eec50
// Recovered Name: _ZN11LayerFlowNS19LFSkinWhitenDataJNI14nSetBeautyGlowEP7_JNIEnvP7_jclassll
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2eec50 | Size: 60 bytes | SHA256: c58ef6c9fe66b8d4df127ec0363154875716f394ab8c49fa269b76e4c5add0d7
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetBeautyGlow(JJ)V (table at 0x539c18)

jobject _ZN11LayerFlowNS19LFSkinWhitenDataJNI14nSetBeautyGlowEP7_JNIEnvP7_jclassll(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 15 instructions
    /* 0x2eec50 */ cbz x3, #0x2eec70;
    /* 0x2eec54 */ ldr q0, [x3];
    /* 0x2eec58 */ ldrb w8, [x2, #0x50];
    /* 0x2eec5c */ ldr x9, [x3, #0x10];
    /* 0x2eec60 */ stur q0, [x2, #0x38];
    /* 0x2eec64 */ str x9, [x2, #0x48];
    /* 0x2eec68 */ cbz w8, #0x2eec80;
    return x0;
    /* 0x2eec70 */ ldrb w8, [x2, #0x50];
    /* 0x2eec74 */ cbz w8, #0x2eec6c;
    /* 0x2eec78 */ strb wzr, [x2, #0x50];
    return x0;
    return x0;
}

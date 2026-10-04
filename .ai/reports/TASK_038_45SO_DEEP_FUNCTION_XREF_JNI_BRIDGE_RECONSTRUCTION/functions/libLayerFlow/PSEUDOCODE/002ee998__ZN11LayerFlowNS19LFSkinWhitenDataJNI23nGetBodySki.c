// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2ee998
// Recovered Name: _ZN11LayerFlowNS19LFSkinWhitenDataJNI23nGetBodySkinCustomColorEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2ee998 | Size: 32 bytes | SHA256: e8cbb37326f1a0b8aa6b0576e189740b5c8424b47958251a3e2d80a3a57b8021
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nGetBodySkinCustomColor(J)Ljava/lang/String; (table at 0x539900)

jobject _ZN11LayerFlowNS19LFSkinWhitenDataJNI23nGetBodySkinCustomColorEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x2ee998 */ ldrb w8, [x2, #0xc8];
    /* 0x2ee99c */ ldr x10, [x0];
    /* 0x2ee9a0 */ add x11, x2, #0xc9;
    /* 0x2ee9a4 */ ldr x9, [x2, #0xd8];
    /* 0x2ee9a8 */ tst w8, #1;
    /* 0x2ee9ac */ ldr x2, [x10, #0x538];
    /* 0x2ee9b0 */ csel x1, x11, x9, eq;
    /* 0x2ee9b4 */ br x2;
}

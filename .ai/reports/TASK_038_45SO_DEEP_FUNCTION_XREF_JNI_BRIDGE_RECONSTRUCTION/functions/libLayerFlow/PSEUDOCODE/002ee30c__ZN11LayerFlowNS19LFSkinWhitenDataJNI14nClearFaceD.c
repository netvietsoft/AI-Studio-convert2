// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2ee30c
// Recovered Name: _ZN11LayerFlowNS19LFSkinWhitenDataJNI14nClearFaceDataEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2ee30c | Size: 48 bytes | SHA256: 3be189dde3f4e0c472c1a7d531e89c3fe5250f5a2478f4ec001e0bbc42fd8a77
// Callers: 0 | Callees: 1 | Imports: 0

// Dynamic Registration: nClearFaceData(J)V (table at 0x539618)

jobject _ZN11LayerFlowNS19LFSkinWhitenDataJNI14nClearFaceDataEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 12 instructions
    /* 0x2ee30c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2ee310 */ str x19, [sp, #0x10];
    /* 0x2ee314 */ mov x29, sp;
    /* 0x2ee318 */ mov x19, x2;
    /* 0x2ee31c */ ldr x1, [x19, #0x30]!;
    /* 0x2ee320 */ sub x0, x19, #8;
    sub_2efac4();
    /* 0x2ee328 */ stp x19, xzr, [x19, #-8];
    /* 0x2ee32c */ str xzr, [x19, #8];
    /* 0x2ee330 */ ldr x19, [sp, #0x10];
    /* 0x2ee334 */ ldp x29, x30, [sp], #0x20;
    return x0;
}

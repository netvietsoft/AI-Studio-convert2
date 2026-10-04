// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2ede40
// Recovered Name: _ZN11LayerFlowNS19LFSkinWhitenDataJNI23nGetFaceIdsFromFaceMapsEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2ede40 | Size: 192 bytes | SHA256: c239b2d17b6df38efac6060a5c5e1b6109da1d048e20ef03489b681b8685b5ba
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nGetFaceIdsFromFaceMaps(J)[I (table at 0x5395b8)

jobject _ZN11LayerFlowNS19LFSkinWhitenDataJNI23nGetFaceIdsFromFaceMapsEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 48 instructions
    /* 0x2ede40 */ stp x29, x30, [sp, #-0x40]!;
    /* 0x2ede44 */ str x23, [sp, #0x10];
    /* 0x2ede48 */ stp x22, x21, [sp, #0x20];
    /* 0x2ede4c */ stp x20, x19, [sp, #0x30];
    /* 0x2ede50 */ mov x29, sp;
    /* 0x2ede54 */ ldr x8, [x0];
    /* 0x2ede58 */ ldr w1, [x2, #0x38];
    /* 0x2ede5c */ mov x20, x2;
    /* 0x2ede60 */ mov x19, x0;
    /* 0x2ede64 */ ldr x8, [x8, #0x598];
    /* 0x2ede68 */ blr x8;
    return x0;
}

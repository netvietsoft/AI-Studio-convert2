// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2ee0fc
// Recovered Name: _ZN11LayerFlowNS19LFSkinWhitenDataJNI23nRemoveFaceDataByFaceIdEP7_JNIEnvP7_jclassli
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2ee0fc | Size: 92 bytes | SHA256: a8852bb5b68ba1056aa6754778df9210630bfd7d8f1ac7ed08b66aa8d5a38633
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nRemoveFaceDataByFaceId(JI)V (table at 0x5395e8)

jobject _ZN11LayerFlowNS19LFSkinWhitenDataJNI23nRemoveFaceDataByFaceIdEP7_JNIEnvP7_jclassli(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 23 instructions
    /* 0x2ee0fc */ ldr x9, [x2, #0x30]!;
    /* 0x2ee100 */ cbz x9, #0x2ee144;
    /* 0x2ee104 */ mov x8, x2;
    /* 0x2ee108 */ ldr w10, [x9, #0x20];
    /* 0x2ee10c */ cmp w10, w3;
    /* 0x2ee110 */ add x10, x9, #8;
    /* 0x2ee114 */ csel x10, x9, x10, ge;
    /* 0x2ee118 */ csel x8, x9, x8, ge;
    /* 0x2ee11c */ ldr x9, [x10];
    /* 0x2ee120 */ cbnz x9, #0x2ee108;
    /* 0x2ee124 */ cmp x8, x2;
    return x0;
}

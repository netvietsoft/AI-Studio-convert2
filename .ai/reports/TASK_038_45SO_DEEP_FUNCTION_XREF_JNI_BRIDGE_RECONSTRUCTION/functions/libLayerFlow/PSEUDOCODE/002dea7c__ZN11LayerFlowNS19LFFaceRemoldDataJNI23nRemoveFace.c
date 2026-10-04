// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2dea7c
// Recovered Name: _ZN11LayerFlowNS19LFFaceRemoldDataJNI23nRemoveFaceDataByFaceIdEP7_JNIEnvP7_jclassli
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2dea7c | Size: 92 bytes | SHA256: ee52b46a6e3ebf1986e05e4cf912d132701cc125a6d1cc716864194392e9e5b9
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nRemoveFaceDataByFaceId(JI)V (table at 0x5376f0)

jobject _ZN11LayerFlowNS19LFFaceRemoldDataJNI23nRemoveFaceDataByFaceIdEP7_JNIEnvP7_jclassli(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 23 instructions
    /* 0x2dea7c */ ldr x9, [x2, #0x30]!;
    /* 0x2dea80 */ cbz x9, #0x2deac4;
    /* 0x2dea84 */ mov x8, x2;
    /* 0x2dea88 */ ldr w10, [x9, #0x20];
    /* 0x2dea8c */ cmp w10, w3;
    /* 0x2dea90 */ add x10, x9, #8;
    /* 0x2dea94 */ csel x10, x9, x10, ge;
    /* 0x2dea98 */ csel x8, x9, x8, ge;
    /* 0x2dea9c */ ldr x9, [x10];
    /* 0x2deaa0 */ cbnz x9, #0x2dea88;
    /* 0x2deaa4 */ cmp x8, x2;
    return x0;
}

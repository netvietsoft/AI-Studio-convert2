// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2ddd70
// Recovered Name: _ZN11LayerFlowNS17LFFaceFullDataJNI23nRemoveFaceDataByFaceIdEP7_JNIEnvP7_jclassli
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2ddd70 | Size: 196 bytes | SHA256: fb46eaf922b1a42aa2e9dd5054c0814244fc91db3222ee1d9fa6b2b7a324c7f1
// Callers: 0 | Callees: 1 | Imports: 1

// Dynamic Registration: nRemoveFaceDataByFaceId(JI)V (table at 0x537180)
// Calls external APIs: _ZdlPv

jobject _ZN11LayerFlowNS17LFFaceFullDataJNI23nRemoveFaceDataByFaceIdEP7_JNIEnvP7_jclassli(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 49 instructions
    /* 0x2ddd70 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2ddd74 */ str x19, [sp, #0x10];
    /* 0x2ddd78 */ mov x29, sp;
    /* 0x2ddd7c */ mov x8, x2;
    /* 0x2ddd80 */ ldr x0, [x8, #0x30]!;
    /* 0x2ddd84 */ cbz x0, #0x2dddc4;
    /* 0x2ddd88 */ mov x9, x8;
    /* 0x2ddd8c */ mov x10, x0;
    /* 0x2ddd90 */ ldr w11, [x10, #0x1c];
    /* 0x2ddd94 */ cmp w11, w3;
    /* 0x2ddd98 */ add x11, x10, #8;
    return x0;
    sub_2c23f4();
}

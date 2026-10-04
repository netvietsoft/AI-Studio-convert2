// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2c29f4
// Recovered Name: _ZN11LayerFlowNS25LFAutoWrinkleCleanDataJNI23nRemoveFaceDataByFaceIdEP7_JNIEnvP7_jclassli
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2c29f4 | Size: 196 bytes | SHA256: ad2f9b25931719eb569183440941ed8f7e1e8008fbe291d6a3c280fbb425f26d
// Callers: 0 | Callees: 1 | Imports: 1

// Dynamic Registration: nRemoveFaceDataByFaceId(JI)V (table at 0x5321f8)
// Calls external APIs: _ZdlPv

jobject _ZN11LayerFlowNS25LFAutoWrinkleCleanDataJNI23nRemoveFaceDataByFaceIdEP7_JNIEnvP7_jclassli(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 49 instructions
    /* 0x2c29f4 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2c29f8 */ str x19, [sp, #0x10];
    /* 0x2c29fc */ mov x29, sp;
    /* 0x2c2a00 */ mov x8, x2;
    /* 0x2c2a04 */ ldr x0, [x8, #0x28]!;
    /* 0x2c2a08 */ cbz x0, #0x2c2a48;
    /* 0x2c2a0c */ mov x9, x8;
    /* 0x2c2a10 */ mov x10, x0;
    /* 0x2c2a14 */ ldr w11, [x10, #0x1c];
    /* 0x2c2a18 */ cmp w11, w3;
    /* 0x2c2a1c */ add x11, x10, #8;
    return x0;
    sub_2c23f4();
}

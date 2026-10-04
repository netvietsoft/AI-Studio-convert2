// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2c2978
// Recovered Name: _ZN11LayerFlowNS25LFAutoWrinkleCleanDataJNI20nGetFaceDataByFaceIdEP7_JNIEnvP7_jclassli
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2c2978 | Size: 124 bytes | SHA256: 9d91830fa71395aaf8a87d0919beef1ae248c55e4a65c73505a2aff7c1b872c5
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nGetFaceDataByFaceId(JI)J (table at 0x5321e0)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS25LFAutoWrinkleCleanDataJNI20nGetFaceDataByFaceIdEP7_JNIEnvP7_jclassli(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 31 instructions
    /* 0x2c2978 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2c297c */ str x19, [sp, #0x10];
    /* 0x2c2980 */ mov x29, sp;
    /* 0x2c2984 */ ldr x8, [x2, #0x28]!;
    /* 0x2c2988 */ cbz x8, #0x2c29c0;
    /* 0x2c298c */ mov x19, x2;
    /* 0x2c2990 */ ldr w9, [x8, #0x1c];
    /* 0x2c2994 */ cmp w9, w3;
    /* 0x2c2998 */ add x9, x8, #8;
    /* 0x2c299c */ csel x9, x8, x9, ge;
    /* 0x2c29a0 */ csel x19, x8, x19, ge;
    return x0;
    _Znwm();
    return x0;
}

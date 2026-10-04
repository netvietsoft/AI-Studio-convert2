// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2c2028
// Recovered Name: _ZN11LayerFlowNS17LFAutoSlimDataJNI20nGetFaceDataByFaceIdEP7_JNIEnvP7_jclassli
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2c2028 | Size: 124 bytes | SHA256: d86fc303609b90c93fd0e8f29a5f507f2f289ce5578894998d93040a82d34f0e
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nGetFaceDataByFaceId(JI)J (table at 0x531fa0)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS17LFAutoSlimDataJNI20nGetFaceDataByFaceIdEP7_JNIEnvP7_jclassli(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 31 instructions
    /* 0x2c2028 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2c202c */ str x19, [sp, #0x10];
    /* 0x2c2030 */ mov x29, sp;
    /* 0x2c2034 */ ldr x8, [x2, #0x28]!;
    /* 0x2c2038 */ cbz x8, #0x2c2070;
    /* 0x2c203c */ mov x19, x2;
    /* 0x2c2040 */ ldr w9, [x8, #0x1c];
    /* 0x2c2044 */ cmp w9, w3;
    /* 0x2c2048 */ add x9, x8, #8;
    /* 0x2c204c */ csel x9, x8, x9, ge;
    /* 0x2c2050 */ csel x19, x8, x19, ge;
    return x0;
    _Znwm();
    return x0;
}

// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2c2168
// Recovered Name: _ZN11LayerFlowNS17LFAutoSlimDataJNI20nPutFaceDataByFaceIdEP7_JNIEnvP7_jclasslil
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2c2168 | Size: 216 bytes | SHA256: b651da8012e65a89aa6159bda936874db1ea188fe6a5f4fc6a98fcc0bed03a64
// Callers: 0 | Callees: 1 | Imports: 1

// Dynamic Registration: nPutFaceDataByFaceId(JIJ)V (table at 0x531fd0)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS17LFAutoSlimDataJNI20nPutFaceDataByFaceIdEP7_JNIEnvP7_jclasslil(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 54 instructions
    /* 0x2c2168 */ stp x29, x30, [sp, #-0x40]!;
    /* 0x2c216c */ stp x24, x23, [sp, #0x10];
    /* 0x2c2170 */ stp x22, x21, [sp, #0x20];
    /* 0x2c2174 */ stp x20, x19, [sp, #0x30];
    /* 0x2c2178 */ mov x29, sp;
    /* 0x2c217c */ mov x23, x2;
    /* 0x2c2180 */ mov x19, x4;
    /* 0x2c2184 */ mov x20, x2;
    /* 0x2c2188 */ ldr x8, [x23, #0x28]!;
    /* 0x2c218c */ mov w22, w3;
    /* 0x2c2190 */ cbnz x8, #0x2c21a8;
    _Znwm();
    sub_2bc34c();
    return x0;
}

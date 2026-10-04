// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2dde34
// Recovered Name: _ZN11LayerFlowNS17LFFaceFullDataJNI20nPutFaceDataByFaceIdEP7_JNIEnvP7_jclasslil
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2dde34 | Size: 248 bytes | SHA256: d013ddbe5419b411345af7bdefeb39289c8910b9f5aa5ae3a96322ea580a504f
// Callers: 0 | Callees: 1 | Imports: 1

// Dynamic Registration: nPutFaceDataByFaceId(JIJ)V (table at 0x537198)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS17LFFaceFullDataJNI20nPutFaceDataByFaceIdEP7_JNIEnvP7_jclasslil(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 62 instructions
    /* 0x2dde34 */ stp x29, x30, [sp, #-0x40]!;
    /* 0x2dde38 */ stp x24, x23, [sp, #0x10];
    /* 0x2dde3c */ stp x22, x21, [sp, #0x20];
    /* 0x2dde40 */ stp x20, x19, [sp, #0x30];
    /* 0x2dde44 */ mov x29, sp;
    /* 0x2dde48 */ mov x23, x2;
    /* 0x2dde4c */ mov x19, x4;
    /* 0x2dde50 */ mov x20, x2;
    /* 0x2dde54 */ ldr x8, [x23, #0x30]!;
    /* 0x2dde58 */ mov w22, w3;
    /* 0x2dde5c */ cbnz x8, #0x2dde74;
    _Znwm();
    sub_2bc34c();
    return x0;
}

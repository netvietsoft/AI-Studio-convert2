// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d8c1c
// Recovered Name: _ZN11LayerFlowNS16LFEnhanceDataJNI15nSetParticularsEP7_JNIEnvP8_jobjectlS4_
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d8c1c | Size: 204 bytes | SHA256: 65cf7b44dba84d88bc2255353903f1102196562ab492aaf159c47cb17e7c9810
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetParticulars(JLcom/layer/flow/datas/LFEnhanceData$ParticularsParam;)V (table at 0x5367d0)
// Strings referenced:
//   "com/layer/flow/datas/LFEnhanceData$ParticularsParam"
//   "nativeHandler"

jobject _ZN11LayerFlowNS16LFEnhanceDataJNI15nSetParticularsEP7_JNIEnvP8_jobjectlS4_(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 51 instructions
    /* 0x2d8c1c */ stp x29, x30, [sp, #-0x30]!;
    /* 0x2d8c20 */ str x21, [sp, #0x10];
    /* 0x2d8c24 */ stp x20, x19, [sp, #0x20];
    /* 0x2d8c28 */ mov x29, sp;
    /* 0x2d8c2c */ ldr x8, [x0];
    /* 0x2d8c30 */ adrp x1, #0x1d1000;
    /* 0x2d8c34 */ add x1, x1, #0xa4a;
    /* 0x2d8c38 */ mov x20, x3;
    /* 0x2d8c3c */ mov x21, x0;
    /* 0x2d8c40 */ mov x19, x2;
    /* 0x2d8c44 */ ldr x8, [x8, #0x30];
    return x0;
    return x0;
    return x0;
}

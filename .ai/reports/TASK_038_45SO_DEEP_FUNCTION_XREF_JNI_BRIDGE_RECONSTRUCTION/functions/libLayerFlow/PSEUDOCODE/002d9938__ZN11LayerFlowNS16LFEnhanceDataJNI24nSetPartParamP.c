// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d9938
// Recovered Name: _ZN11LayerFlowNS16LFEnhanceDataJNI24nSetPartParamParticularsEP7_JNIEnvP8_jobjectlS4_
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d9938 | Size: 196 bytes | SHA256: 020321c4e88e5416d0a3d4420b5835b9900e39d36f2f37d95360b34bc18ee718
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetPartParamParticulars(JLcom/layer/flow/datas/LFEnhanceData$ParticularsParam;)V (table at 0x536b18)
// Strings referenced:
//   "com/layer/flow/datas/LFEnhanceData$ParticularsParam"
//   "nativeHandler"

jobject _ZN11LayerFlowNS16LFEnhanceDataJNI24nSetPartParamParticularsEP7_JNIEnvP8_jobjectlS4_(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 49 instructions
    /* 0x2d9938 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x2d993c */ str x21, [sp, #0x10];
    /* 0x2d9940 */ stp x20, x19, [sp, #0x20];
    /* 0x2d9944 */ mov x29, sp;
    /* 0x2d9948 */ ldr x8, [x0];
    /* 0x2d994c */ adrp x1, #0x1d1000;
    /* 0x2d9950 */ add x1, x1, #0xa4a;
    /* 0x2d9954 */ mov x20, x3;
    /* 0x2d9958 */ mov x21, x0;
    /* 0x2d995c */ mov x19, x2;
    /* 0x2d9960 */ ldr x8, [x8, #0x30];
    return x0;
    return x0;
    return x0;
}

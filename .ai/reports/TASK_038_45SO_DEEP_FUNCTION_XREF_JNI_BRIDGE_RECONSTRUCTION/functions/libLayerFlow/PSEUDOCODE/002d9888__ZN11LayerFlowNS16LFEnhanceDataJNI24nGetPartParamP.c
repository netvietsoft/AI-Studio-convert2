// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d9888
// Recovered Name: _ZN11LayerFlowNS16LFEnhanceDataJNI24nGetPartParamParticularsEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d9888 | Size: 176 bytes | SHA256: 208f21ec8b3688c46bc7472fdd25a28a06d2c32807e5428b000237c6b04984a0
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nGetPartParamParticulars(J)Lcom/layer/flow/datas/LFEnhanceData$ParticularsParam; (table at 0x536b00)
// Calls external APIs: _Znwm
// Strings referenced:
//   "(JZ)V"
//   "<init>"
//   "com/layer/flow/datas/LFEnhanceData$ParticularsParam"

jobject _ZN11LayerFlowNS16LFEnhanceDataJNI24nGetPartParamParticularsEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 44 instructions
    /* 0x2d9888 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x2d988c */ stp x22, x21, [sp, #0x10];
    /* 0x2d9890 */ stp x20, x19, [sp, #0x20];
    /* 0x2d9894 */ mov x29, sp;
    /* 0x2d9898 */ ldr x8, [x0];
    /* 0x2d989c */ adrp x1, #0x1d1000;
    /* 0x2d98a0 */ add x1, x1, #0xa4a;
    /* 0x2d98a4 */ mov x19, x0;
    /* 0x2d98a8 */ mov x20, x2;
    /* 0x2d98ac */ ldr x8, [x8, #0x30];
    /* 0x2d98b0 */ blr x8;
    _Znwm();
    return x0;
}

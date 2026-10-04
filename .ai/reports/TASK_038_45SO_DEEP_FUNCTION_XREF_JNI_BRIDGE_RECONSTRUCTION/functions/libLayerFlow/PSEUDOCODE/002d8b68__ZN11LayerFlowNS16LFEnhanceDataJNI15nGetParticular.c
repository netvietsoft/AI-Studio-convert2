// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d8b68
// Recovered Name: _ZN11LayerFlowNS16LFEnhanceDataJNI15nGetParticularsEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d8b68 | Size: 180 bytes | SHA256: 7b1a860bd69328814a7910fbab23210cc49c0c6475321b7d2635804107e42523
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nGetParticulars(J)Lcom/layer/flow/datas/LFEnhanceData$ParticularsParam; (table at 0x5367b8)
// Calls external APIs: _Znwm
// Strings referenced:
//   "(JZ)V"
//   "<init>"
//   "com/layer/flow/datas/LFEnhanceData$ParticularsParam"

jobject _ZN11LayerFlowNS16LFEnhanceDataJNI15nGetParticularsEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 45 instructions
    /* 0x2d8b68 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x2d8b6c */ stp x22, x21, [sp, #0x10];
    /* 0x2d8b70 */ stp x20, x19, [sp, #0x20];
    /* 0x2d8b74 */ mov x29, sp;
    /* 0x2d8b78 */ ldr x8, [x0];
    /* 0x2d8b7c */ adrp x1, #0x1d1000;
    /* 0x2d8b80 */ add x1, x1, #0xa4a;
    /* 0x2d8b84 */ mov x19, x0;
    /* 0x2d8b88 */ mov x21, x2;
    /* 0x2d8b8c */ ldr x8, [x8, #0x30];
    /* 0x2d8b90 */ blr x8;
    _Znwm();
    return x0;
}

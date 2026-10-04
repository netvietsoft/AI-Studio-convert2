// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2c7ff4
// Recovered Name: _ZN11LayerFlowNS13LFEditDataJNI10getCorrectEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2c7ff4 | Size: 116 bytes | SHA256: 81384f354ca39c766f725f78318607c7381e9465088923d64632526250153c26
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: getCorrect(J)Lcom/layer/flow/datas/LFEffectEditData$CorrectParams; (table at 0x533098)
// Strings referenced:
//   "(J)V"
//   "<init>"
//   "com/layer/flow/datas/LFEffectEditData$CorrectParams"

jobject _ZN11LayerFlowNS13LFEditDataJNI10getCorrectEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 29 instructions
    /* 0x2c7ff4 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x2c7ff8 */ str x21, [sp, #0x10];
    /* 0x2c7ffc */ stp x20, x19, [sp, #0x20];
    /* 0x2c8000 */ mov x29, sp;
    /* 0x2c8004 */ ldr x8, [x0];
    /* 0x2c8008 */ adrp x1, #0x1d9000;
    /* 0x2c800c */ add x1, x1, #0x9f0;
    /* 0x2c8010 */ mov x19, x0;
    /* 0x2c8014 */ mov x20, x2;
    /* 0x2c8018 */ ldr x8, [x8, #0x30];
    /* 0x2c801c */ blr x8;
}

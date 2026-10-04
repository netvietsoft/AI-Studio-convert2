// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2c7f80
// Recovered Name: _ZN11LayerFlowNS13LFEditDataJNI9getRotateEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2c7f80 | Size: 116 bytes | SHA256: 2bfa253463bababa44400e6e8794384be626d68388fb4bfe3c408a1cdbae6023
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: getRotate(J)Lcom/layer/flow/datas/LFEffectEditData$RotateParams; (table at 0x533080)
// Strings referenced:
//   "(J)V"
//   "<init>"
//   "com/layer/flow/datas/LFEffectEditData$RotateParams"

jobject _ZN11LayerFlowNS13LFEditDataJNI9getRotateEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 29 instructions
    /* 0x2c7f80 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x2c7f84 */ str x21, [sp, #0x10];
    /* 0x2c7f88 */ stp x20, x19, [sp, #0x20];
    /* 0x2c7f8c */ mov x29, sp;
    /* 0x2c7f90 */ ldr x8, [x0];
    /* 0x2c7f94 */ adrp x1, #0x1ec000;
    /* 0x2c7f98 */ add x1, x1, #0x979;
    /* 0x2c7f9c */ mov x19, x0;
    /* 0x2c7fa0 */ mov x20, x2;
    /* 0x2c7fa4 */ ldr x8, [x8, #0x30];
    /* 0x2c7fa8 */ blr x8;
}

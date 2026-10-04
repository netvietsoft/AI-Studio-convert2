// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2c8068
// Recovered Name: _ZN11LayerFlowNS13LFEditDataJNI8getPixelEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2c8068 | Size: 116 bytes | SHA256: 76dc7531e9a37186d55edeaf087a599407f8106e374de9a909c9e858c29c89cb
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: getPixel(J)Lcom/layer/flow/datas/LFEffectEditData$PixelParams; (table at 0x5330b0)
// Strings referenced:
//   "(J)V"
//   "<init>"
//   "com/layer/flow/datas/LFEffectEditData$PixelParams"

jobject _ZN11LayerFlowNS13LFEditDataJNI8getPixelEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 29 instructions
    /* 0x2c8068 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x2c806c */ str x21, [sp, #0x10];
    /* 0x2c8070 */ stp x20, x19, [sp, #0x20];
    /* 0x2c8074 */ mov x29, sp;
    /* 0x2c8078 */ ldr x8, [x0];
    /* 0x2c807c */ adrp x1, #0x1ec000;
    /* 0x2c8080 */ add x1, x1, #0x9ac;
    /* 0x2c8084 */ mov x19, x0;
    /* 0x2c8088 */ mov x20, x2;
    /* 0x2c808c */ ldr x8, [x8, #0x30];
    /* 0x2c8090 */ blr x8;
}

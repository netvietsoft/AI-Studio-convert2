// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2c7f0c
// Recovered Name: _ZN11LayerFlowNS13LFEditDataJNI7getClipEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2c7f0c | Size: 116 bytes | SHA256: ced4b36d5acef209909c9d91b0bb14e345fef2d82577f1258d352c600146ad97
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: getClip(J)Lcom/layer/flow/datas/LFEffectEditData$ClipParams; (table at 0x533068)
// Strings referenced:
//   "(J)V"
//   "<init>"

jobject _ZN11LayerFlowNS13LFEditDataJNI7getClipEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 29 instructions
    /* 0x2c7f0c */ stp x29, x30, [sp, #-0x30]!;
    /* 0x2c7f10 */ str x21, [sp, #0x10];
    /* 0x2c7f14 */ stp x20, x19, [sp, #0x20];
    /* 0x2c7f18 */ mov x29, sp;
    /* 0x2c7f1c */ ldr x8, [x0];
    /* 0x2c7f20 */ nop ;
    /* 0x2c7f24 */ adr x1, #0x1cf54a;
    /* 0x2c7f28 */ mov x19, x0;
    /* 0x2c7f2c */ mov x20, x2;
    /* 0x2c7f30 */ ldr x8, [x8, #0x30];
    /* 0x2c7f34 */ blr x8;
}

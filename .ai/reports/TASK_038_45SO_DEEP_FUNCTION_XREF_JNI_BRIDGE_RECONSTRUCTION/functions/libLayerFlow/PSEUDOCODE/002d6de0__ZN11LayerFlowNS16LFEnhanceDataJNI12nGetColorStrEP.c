// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d6de0
// Recovered Name: _ZN11LayerFlowNS16LFEnhanceDataJNI12nGetColorStrEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d6de0 | Size: 28 bytes | SHA256: 2000ff82407cecd7afc9230caac505ef98b1c7905e854fbce2cfe6626d3bf7fe
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nGetColorStr(J)Ljava/lang/String; (table at 0x536038)

jobject _ZN11LayerFlowNS16LFEnhanceDataJNI12nGetColorStrEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x2d6de0 */ ldrb w8, [x2];
    /* 0x2d6de4 */ ldr x9, [x2, #0x10];
    /* 0x2d6de8 */ ldr x10, [x0];
    /* 0x2d6dec */ tst w8, #1;
    /* 0x2d6df0 */ csinc x1, x9, x2, ne;
    /* 0x2d6df4 */ ldr x2, [x10, #0x538];
    /* 0x2d6df8 */ br x2;
}

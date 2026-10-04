// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2e83cc
// Recovered Name: _ZN11LayerFlowNS18LFMakeUpModularJNI23nRemoveFaceDataByFaceIdEP7_JNIEnvP8_jobjectli
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2e83cc | Size: 92 bytes | SHA256: d9dfb70eb1c72d8744b118f6576eabfb9000a859f8e759c03bbdf979dfa7fb0b
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nRemoveFaceDataByFaceId(JI)V (table at 0x538b78)

jobject _ZN11LayerFlowNS18LFMakeUpModularJNI23nRemoveFaceDataByFaceIdEP7_JNIEnvP8_jobjectli(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 23 instructions
    /* 0x2e83cc */ ldr x9, [x2, #0x30]!;
    /* 0x2e83d0 */ cbz x9, #0x2e8414;
    /* 0x2e83d4 */ mov x8, x2;
    /* 0x2e83d8 */ ldr w10, [x9, #0x20];
    /* 0x2e83dc */ cmp w10, w3;
    /* 0x2e83e0 */ add x10, x9, #8;
    /* 0x2e83e4 */ csel x10, x9, x10, ge;
    /* 0x2e83e8 */ csel x8, x9, x8, ge;
    /* 0x2e83ec */ ldr x9, [x10];
    /* 0x2e83f0 */ cbnz x9, #0x2e83d8;
    /* 0x2e83f4 */ cmp x8, x2;
    return x0;
}

// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2ee158
// Recovered Name: _ZN11LayerFlowNS19LFSkinWhitenDataJNI20nPutFaceDataByFaceIdEP7_JNIEnvP7_jclasslil
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2ee158 | Size: 436 bytes | SHA256: 349060bfb7ca34b59ad023e116a793e143f333f0f52f8917b8b593d63d2ad2ef
// Callers: 0 | Callees: 2 | Imports: 2

// Dynamic Registration: nPutFaceDataByFaceId(JIJ)V (table at 0x539600)
// Calls external APIs: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_, _Znwm

jobject _ZN11LayerFlowNS19LFSkinWhitenDataJNI20nPutFaceDataByFaceIdEP7_JNIEnvP7_jclasslil(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 109 instructions
    /* 0x2ee158 */ stp x29, x30, [sp, #-0x40]!;
    /* 0x2ee15c */ stp x24, x23, [sp, #0x10];
    /* 0x2ee160 */ stp x22, x21, [sp, #0x20];
    /* 0x2ee164 */ stp x20, x19, [sp, #0x30];
    /* 0x2ee168 */ mov x29, sp;
    /* 0x2ee16c */ mov x23, x2;
    /* 0x2ee170 */ mov x19, x4;
    /* 0x2ee174 */ mov x21, x2;
    /* 0x2ee178 */ ldr x8, [x23, #0x30]!;
    /* 0x2ee17c */ mov w22, w3;
    /* 0x2ee180 */ cbnz x8, #0x2ee198;
    _Znwm();
    sub_2bc34c();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_();
    sub_2dbf14();
}

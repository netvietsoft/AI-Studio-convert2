// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2e833c
// Recovered Name: _ZN11LayerFlowNS18LFMakeUpModularJNI20nGetFaceDataByFaceIdEP7_JNIEnvP8_jobjectli
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2e833c | Size: 144 bytes | SHA256: bf6f4fbf55164008ad960bf598360e842884182473b983301163918c32ec2ccd
// Callers: 0 | Callees: 2 | Imports: 2

// Dynamic Registration: nGetFaceDataByFaceId(JI)J (table at 0x538b60)
// Calls external APIs: _ZdlPv, _Znwm

jobject _ZN11LayerFlowNS18LFMakeUpModularJNI20nGetFaceDataByFaceIdEP7_JNIEnvP8_jobjectli(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 36 instructions
    /* 0x2e833c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2e8340 */ stp x20, x19, [sp, #0x10];
    /* 0x2e8344 */ mov x29, sp;
    /* 0x2e8348 */ ldr x8, [x2, #0x30]!;
    /* 0x2e834c */ cbz x8, #0x2e8384;
    /* 0x2e8350 */ mov x19, x2;
    /* 0x2e8354 */ ldr w9, [x8, #0x20];
    /* 0x2e8358 */ cmp w9, w3;
    /* 0x2e835c */ add x9, x8, #8;
    /* 0x2e8360 */ csel x9, x8, x9, ge;
    /* 0x2e8364 */ csel x19, x8, x19, ge;
    return x0;
    _Znwm();
    _ZN10MakeUpInfoC2ERKS_();
    return x0;
    _ZdlPv();
    sub_526544();
}

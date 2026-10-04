// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2de810
// Recovered Name: _ZN11LayerFlowNS19LFFaceRemoldDataJNI20nGetFaceDataByFaceIdEP7_JNIEnvP7_jclassli
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2de810 | Size: 144 bytes | SHA256: fa9bb9290a8674febc05da9f31c0f470f9f1a1050e2aa15d04ad24497b912412
// Callers: 0 | Callees: 2 | Imports: 2

// Dynamic Registration: nGetFaceDataByFaceId(JI)J (table at 0x5376d8)
// Calls external APIs: _ZdlPv, _Znwm

jobject _ZN11LayerFlowNS19LFFaceRemoldDataJNI20nGetFaceDataByFaceIdEP7_JNIEnvP7_jclassli(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 36 instructions
    /* 0x2de810 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2de814 */ stp x20, x19, [sp, #0x10];
    /* 0x2de818 */ mov x29, sp;
    /* 0x2de81c */ ldr x8, [x2, #0x30]!;
    /* 0x2de820 */ cbz x8, #0x2de858;
    /* 0x2de824 */ mov x19, x2;
    /* 0x2de828 */ ldr w9, [x8, #0x20];
    /* 0x2de82c */ cmp w9, w3;
    /* 0x2de830 */ add x9, x8, #8;
    /* 0x2de834 */ csel x9, x8, x9, ge;
    /* 0x2de838 */ csel x19, x8, x19, ge;
    return x0;
    _Znwm();
    _ZN14FaceRemoldInfoC2ERKS_();
    return x0;
    _ZdlPv();
    sub_526544();
}

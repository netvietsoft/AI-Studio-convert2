// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2cdcf4
// Recovered Name: _ZN11LayerFlowNS18LFEffectEyeDataJNI37nSetGazeCorrectCacheDataImageCropInfoEP7_JNIEnvP7_jclassll
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2cdcf4 | Size: 292 bytes | SHA256: 46a32b656ec67843918aab7e58a49c4d6da99ffbe213d34d3667443ef3e9bc7b
// Callers: 0 | Callees: 5 | Imports: 4

// Dynamic Registration: nSetImageCropInfo(JJ)V (table at 0x534170)
// Calls external APIs: _ZNSt6__ndk119__shared_weak_count14__release_weakEv, _ZNSt6__ndk119__shared_weak_countD2Ev, _ZdlPv, _Znwm

jobject _ZN11LayerFlowNS18LFEffectEyeDataJNI37nSetGazeCorrectCacheDataImageCropInfoEP7_JNIEnvP7_jclassll(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 73 instructions
    /* 0x2cdcf4 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x2cdcf8 */ stp x22, x21, [sp, #0x10];
    /* 0x2cdcfc */ stp x20, x19, [sp, #0x20];
    /* 0x2cdd00 */ mov x29, sp;
    /* 0x2cdd04 */ mov x19, x2;
    /* 0x2cdd08 */ cbz x3, #0x2cdd84;
    /* 0x2cdd0c */ mov w0, #0x68;
    /* 0x2cdd10 */ mov x21, x3;
    _Znwm();
    /* 0x2cdd18 */ adrp x8, #0x54a000;
    /* 0x2cdd1c */ mov x20, x0;
    sub_5263b0();
    sub_2bc260();
    sub_5263e0();
    return x0;
    sub_2bbdb4();
    _ZNSt6__ndk119__shared_weak_countD2Ev();
    _ZdlPv();
    sub_526544();
}

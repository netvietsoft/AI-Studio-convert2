// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2cdc24
// Recovered Name: _ZN11LayerFlowNS18LFEffectEyeDataJNI37nGetGazeCorrectCacheDataImageCropInfoEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2cdc24 | Size: 200 bytes | SHA256: 4533241f00309ae5ee7aefccbb575abbfbbb242798cd4506aa2799d500b83918
// Callers: 0 | Callees: 4 | Imports: 2

// Dynamic Registration: nGetImageCropInfo(J)J (table at 0x534140)
// Calls external APIs: _ZdlPv, _Znwm

jobject _ZN11LayerFlowNS18LFEffectEyeDataJNI37nGetGazeCorrectCacheDataImageCropInfoEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 50 instructions
    /* 0x2cdc24 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x2cdc28 */ str x21, [sp, #0x10];
    /* 0x2cdc2c */ stp x20, x19, [sp, #0x20];
    /* 0x2cdc30 */ mov x29, sp;
    /* 0x2cdc34 */ ldr x21, [x2];
    /* 0x2cdc38 */ cbz x21, #0x2cdca8;
    /* 0x2cdc3c */ mov w0, #0x50;
    _Znwm();
    /* 0x2cdc44 */ ldp q1, q0, [x21];
    /* 0x2cdc48 */ mov x19, x0;
    /* 0x2cdc4c */ ldr x8, [x21, #0x20];
    sub_5263b0();
    return x0;
    return x0;
    sub_2bc260();
    sub_2bbdb4();
    _ZdlPv();
    sub_526544();
}

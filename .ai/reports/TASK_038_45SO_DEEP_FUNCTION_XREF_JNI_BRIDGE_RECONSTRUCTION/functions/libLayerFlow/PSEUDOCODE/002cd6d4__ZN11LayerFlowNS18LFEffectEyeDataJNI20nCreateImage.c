// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2cd6d4
// Recovered Name: _ZN11LayerFlowNS18LFEffectEyeDataJNI20nCreateImageCropInfoEP7_JNIEnvP7_jclass
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2cd6d4 | Size: 84 bytes | SHA256: 246e9f24a6456cec3b7b1edce08483fe0f4248b7ae0871a9c1b6dd99e9fe5fe7
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nCreate()J (table at 0x533f48)
// Calls external APIs: _Znwm, __android_log_print
// Strings referenced:
//   "nCreateImageCropInfo addr => %p"

jobject _ZN11LayerFlowNS18LFEffectEyeDataJNI20nCreateImageCropInfoEP7_JNIEnvP7_jclass(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 21 instructions
    /* 0x2cd6d4 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2cd6d8 */ str x19, [sp, #0x10];
    /* 0x2cd6dc */ mov x29, sp;
    /* 0x2cd6e0 */ mov w0, #0x50;
    _Znwm();
    /* 0x2cd6e8 */ movi v0.2d, #0000000000000000;
    /* 0x2cd6ec */ mov x19, x0;
    /* 0x2cd6f0 */ nop ;
    /* 0x2cd6f4 */ adr x1, #0x1e1361;
    /* 0x2cd6f8 */ adrp x2, #0x1e6000;
    /* 0x2cd6fc */ add x2, x2, #0xb76;
    __android_log_print();
    return x0;
}

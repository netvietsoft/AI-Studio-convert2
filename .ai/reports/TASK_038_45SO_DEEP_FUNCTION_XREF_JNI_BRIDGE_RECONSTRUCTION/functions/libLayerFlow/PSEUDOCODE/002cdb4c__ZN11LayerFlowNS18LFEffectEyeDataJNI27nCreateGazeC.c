// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2cdb4c
// Recovered Name: _ZN11LayerFlowNS18LFEffectEyeDataJNI27nCreateGazeCorrectCacheDataEP7_JNIEnvP7_jclass
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2cdb4c | Size: 76 bytes | SHA256: 633a6c23c2dc174654fbe55de90aa21b1938df2f0bebbc5714c29719053f7f9a
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nCreate()J (table at 0x534110)
// Calls external APIs: _Znwm, __android_log_print
// Strings referenced:
//   "nCreateGazeCorrectCacheData addr => %p"

jobject _ZN11LayerFlowNS18LFEffectEyeDataJNI27nCreateGazeCorrectCacheDataEP7_JNIEnvP7_jclass(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 19 instructions
    /* 0x2cdb4c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2cdb50 */ str x19, [sp, #0x10];
    /* 0x2cdb54 */ mov x29, sp;
    /* 0x2cdb58 */ mov w0, #0x18;
    _Znwm();
    /* 0x2cdb60 */ mov x19, x0;
    /* 0x2cdb64 */ stp xzr, xzr, [x0, #8];
    /* 0x2cdb68 */ nop ;
    /* 0x2cdb6c */ adr x1, #0x1e1361;
    /* 0x2cdb70 */ str xzr, [x0];
    /* 0x2cdb74 */ adrp x2, #0x1e6000;
    __android_log_print();
    return x0;
}

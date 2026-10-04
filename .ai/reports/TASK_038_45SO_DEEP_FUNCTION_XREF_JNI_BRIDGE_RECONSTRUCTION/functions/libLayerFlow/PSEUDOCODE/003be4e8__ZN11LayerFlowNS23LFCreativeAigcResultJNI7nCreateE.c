// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3be4e8
// Recovered Name: _ZN11LayerFlowNS23LFCreativeAigcResultJNI7nCreateEP7_JNIEnvP8_jobject
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x3be4e8 | Size: 180 bytes | SHA256: 1035501f131aad7b8c257dff44551484e9041305b5b8065bd0e8eccc2d682ab6
// Callers: 0 | Callees: 5 | Imports: 2

// Dynamic Registration: nCreate()J (table at 0x540018)
// Calls external APIs: _ZdlPv, _Znwm
// Strings referenced:
//   "creative_aigc"

jobject _ZN11LayerFlowNS23LFCreativeAigcResultJNI7nCreateEP7_JNIEnvP8_jobject(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 45 instructions
    /* 0x3be4e8 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x3be4ec */ str x21, [sp, #0x10];
    /* 0x3be4f0 */ stp x20, x19, [sp, #0x20];
    /* 0x3be4f4 */ mov x29, sp;
    /* 0x3be4f8 */ mov w0, #0xb0;
    _Znwm();
    /* 0x3be500 */ adrp x8, #0x54a000;
    /* 0x3be504 */ movi v0.2d, #0000000000000000;
    /* 0x3be508 */ mov x19, x0;
    /* 0x3be50c */ ldr x8, [x8, #0xdc0];
    /* 0x3be510 */ mov x21, x19;
    sub_525b68();
    return x0;
    sub_3bed84();
    sub_3bee44();
    _ZdlPv();
    _ZN12MTImageKitNS21CMTIKNetRequestResultD2Ev();
    _ZdlPv();
    sub_526544();
}

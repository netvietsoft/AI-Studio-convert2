// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3cad7c
// Recovered Name: sub_3cad7c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x3cad7c | Size: 324 bytes | SHA256: adee32f116c37cb4dfb32255f0b3602dceed7b3ebd41ef751560e2d03bf0379a
// Callers: 0 | Callees: 1 | Imports: 3

// Calls external APIs: _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z, _ZN12MTImageKitNS8JniUtils18jintArrayTocIntVecEP7_JNIEnvP10_jintArray, __stack_chk_fail
// Strings referenced:
//   "(II)[I"
//   "ZN11LayerFlowNS21LFFormulaRenderPlugin18setupBlurCallbacksEPS0_NSt6__ndk110shared_ptrINS_22CLFFormulaRenderPluginEEEE3$_1"
//   "cbBlurGetAutoMaskSize"
//   "iklf"
//   "jniFormulaRender<%s:%d> env or callbackObj is null, unable to callback blurGetAutoMaskSize"

void sub_3cad7c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 81 instructions
    /* 0x3cad7c */ stp x29, x30, [sp, #0x10];
    /* 0x3cad80 */ str x23, [sp, #0x20];
    /* 0x3cad84 */ stp x22, x21, [sp, #0x30];
    /* 0x3cad88 */ stp x20, x19, [sp, #0x40];
    /* 0x3cad8c */ add x29, sp, #0x10;
    /* 0x3cad90 */ mrs x22, tpidr_el0;
    /* 0x3cad94 */ mov x19, x8;
    /* 0x3cad98 */ ldr x9, [x22, #0x28];
    /* 0x3cad9c */ str x9, [sp, #8];
    /* 0x3cada0 */ ldr x23, [x0, #8];
    /* 0x3cada4 */ str xzr, [sp];
    sub_2c598c();
    _ZN12MTImageKitNS8JniUtils18jintArrayTocIntVecEP7_JNIEnvP10_jintArray();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    return x0;
    __stack_chk_fail();
    return x0;
    return x0;
}

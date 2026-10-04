// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3cb3b8
// Recovered Name: sub_3cb3b8
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x3cb3b8 | Size: 508 bytes | SHA256: 57fe25f85602229e6f51746eb79843e99ea22f3d59c6a0c1fa98771b8988d4cf
// Callers: 0 | Callees: 4 | Imports: 5

// Calls external APIs: _ZN12MTImageKitNS12Bitmap2ImageEP7_JNIEnvP8_jobjectb, _ZN12MTImageKitNS12Image2BitmapEP7_JNIEnvNSt6__ndk110shared_ptrINS_5ImageEEEb, _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z, _ZNSt6__ndk119__shared_weak_count14__release_weakEv, __stack_chk_fail
// Strings referenced:
//   "(Landroid/graphics/Bitmap;)Landroid/graphics/Bitmap;"
//   "ZN11LayerFlowNS21LFFormulaRenderPlugin18setupBlurCallbacksEPS0_NSt6__ndk110shared_ptrINS_22CLFFormulaRenderPluginEEEE3$_3"
//   "cbBlurFullBodySegment"
//   "iklf"
//   "jniFormulaRender<%s:%d> env or callbackObj is null, unable to callback blurFullBodySegment"

void sub_3cb3b8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 127 instructions
    /* 0x3cb3b8 */ stp x29, x30, [sp, #0x30];
    /* 0x3cb3bc */ stp x24, x23, [sp, #0x40];
    /* 0x3cb3c0 */ stp x22, x21, [sp, #0x50];
    /* 0x3cb3c4 */ stp x20, x19, [sp, #0x60];
    /* 0x3cb3c8 */ add x29, sp, #0x30;
    /* 0x3cb3cc */ mrs x23, tpidr_el0;
    /* 0x3cb3d0 */ mov x19, x8;
    /* 0x3cb3d4 */ ldr x8, [x23, #0x28];
    /* 0x3cb3d8 */ stur x8, [x29, #-8];
    /* 0x3cb3dc */ ldp x21, x22, [x1];
    /* 0x3cb3e0 */ stp xzr, xzr, [x1];
    _ZN12MTImageKitNS12Image2BitmapEP7_JNIEnvNSt6__ndk110shared_ptrINS_5ImageEEEb();
    sub_5263e0();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    sub_2c598c();
    _ZN12MTImageKitNS12Bitmap2ImageEP7_JNIEnvP8_jobjectb();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    sub_5263e0();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    return x0;
    sub_2bbdb4();
    sub_2bbdb4();
    sub_526544();
    __stack_chk_fail();
    return x0;
    return x0;
}

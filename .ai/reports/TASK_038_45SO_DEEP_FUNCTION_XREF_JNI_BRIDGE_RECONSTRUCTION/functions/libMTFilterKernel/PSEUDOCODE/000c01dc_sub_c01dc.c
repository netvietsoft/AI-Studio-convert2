// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xc01dc
// Recovered Name: sub_c01dc
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xc01dc | Size: 1164 bytes | SHA256: 4d5f9aa9925bf018b6a54fa6b453b369c95c09ccc1db619fe7fab98a2c5b8f4a
// Callers: 0 | Callees: 6 | Imports: 2

// Calls external APIs: __android_log_print, __stack_chk_fail
// Strings referenced:
//   "()I"
//   "FilterKernel_jni"
//   "JNI OnLoad: failed to set %s class reference"
//   "Landroid/graphics/PointF;"
//   "Landroid/graphics/Rect;"

void sub_c01dc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 291 instructions
    /* 0xc01dc */ stp x29, x30, [sp, #0x40];
    /* 0xc01e0 */ stp x26, x25, [sp, #0x50];
    /* 0xc01e4 */ stp x24, x23, [sp, #0x60];
    /* 0xc01e8 */ stp x22, x21, [sp, #0x70];
    /* 0xc01ec */ stp x20, x19, [sp, #0x80];
    /* 0xc01f0 */ add x29, sp, #0x40;
    /* 0xc01f4 */ mrs x26, tpidr_el0;
    /* 0xc01f8 */ ldr x8, [x26, #0x28];
    /* 0xc01fc */ stur x8, [x29, #-0x18];
    /* 0xc0200 */ cbz x2, #0xc0634;
    /* 0xc0204 */ mov x20, x0;
    _ZN14MTFilterKernel32MTlabFilterKernelRenderInterface17getRtEffectConfigEv();
    _ZN20MTFilterKernelRender15getRectFromJavaEP7_JNIEnvP8_jobjectS3_();
    _ZN14MTFilterKernel32MTlabFilterKernelRenderInterface18setDisplayViewRectENS_6CGRectE();
    _ZN7_JNIEnv13CallIntMethodEP8_jobjectP10_jmethodIDz();
    __android_log_print();
    _ZN14MTFilterKernel32MTlabFilterKernelRenderInterface19setPreviewRatioTypeENS_24MTFilterPreviewRatioTypeE();
    _ZN14MTFilterKernel32MTlabFilterKernelRenderInterface17setRtEffectConfigERNS_20RtFilterKernelConfigE();
    return x0;
    __stack_chk_fail();
}

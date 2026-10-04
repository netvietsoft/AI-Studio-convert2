// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3cb0b0
// Recovered Name: sub_3cb0b0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x3cb0b0 | Size: 276 bytes | SHA256: 5616ebd1972cbb85b5fd1294335b09d14262138841fb3a5cd2f7bff0fdf57caa
// Callers: 0 | Callees: 1 | Imports: 2

// Calls external APIs: _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z, __stack_chk_fail
// Strings referenced:
//   "()Z"
//   "ZN11LayerFlowNS21LFFormulaRenderPlugin18setupBlurCallbacksEPS0_NSt6__ndk110shared_ptrINS_22CLFFormulaRenderPluginEEEE3$_2"
//   "cbIsFullBodySegmentSrcImageNeeded"
//   "iklf"
//   "jniFormulaRender<%s:%d> env or callbackObj is null, unable to callback blurIsFullBodySegmentSrcImageNeeded"

void sub_3cb0b0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 69 instructions
    /* 0x3cb0b0 */ stp x29, x30, [sp, #0x10];
    /* 0x3cb0b4 */ stp x20, x19, [sp, #0x20];
    /* 0x3cb0b8 */ add x29, sp, #0x10;
    /* 0x3cb0bc */ mrs x19, tpidr_el0;
    /* 0x3cb0c0 */ mov x1, sp;
    /* 0x3cb0c4 */ mov x2, xzr;
    /* 0x3cb0c8 */ ldr x8, [x19, #0x28];
    /* 0x3cb0cc */ str x8, [sp, #8];
    /* 0x3cb0d0 */ ldr x20, [x0, #8];
    /* 0x3cb0d4 */ str xzr, [sp];
    /* 0x3cb0d8 */ ldr x0, [x20, #0x5e0];
    sub_2c5a28();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    return x0;
    __stack_chk_fail();
    return x0;
    return x0;
}

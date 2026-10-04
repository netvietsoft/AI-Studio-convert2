// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x44e718
// Recovered Name: _ZN11LayerFlowNS22LFOutputImagePluginJNI7destroyEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x44e718 | Size: 96 bytes | SHA256: a97f63495fe7ff41b40d25b88279b1766cae422e9dc2d257b5d0202932dcc26e
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nDestroy(J)V (table at 0x5466c8)
// Calls external APIs: _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z
// Strings referenced:
//   "destroy"
//   "iklf"
//   "jniOutImgPlg<%s:%d> ------ destroying LFOutputImagePluginJNI %p"

jobject _ZN11LayerFlowNS22LFOutputImagePluginJNI7destroyEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 24 instructions
    /* 0x44e718 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x44e71c */ str x19, [sp, #0x10];
    /* 0x44e720 */ mov x29, sp;
    /* 0x44e724 */ mov x19, x2;
    /* 0x44e728 */ adrp x0, #0x1d9000;
    /* 0x44e72c */ add x0, x0, #0x93c;
    /* 0x44e730 */ adrp x2, #0x1ed000;
    /* 0x44e734 */ add x2, x2, #0x588;
    /* 0x44e738 */ adrp x3, #0x1e7000;
    /* 0x44e73c */ add x3, x3, #0x9e6;
    /* 0x44e740 */ mov w1, #3;
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    return x0;
}

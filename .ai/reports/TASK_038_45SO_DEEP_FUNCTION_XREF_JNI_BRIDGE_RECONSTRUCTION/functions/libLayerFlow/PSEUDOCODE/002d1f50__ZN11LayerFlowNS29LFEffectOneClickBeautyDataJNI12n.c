// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d1f50
// Recovered Name: _ZN11LayerFlowNS29LFEffectOneClickBeautyDataJNI12nDestroyInfoEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d1f50 | Size: 140 bytes | SHA256: cc59c102b08ac312785db772cbe45fc91398391e879c41bcde2014144f983899
// Callers: 0 | Callees: 1 | Imports: 3

// Dynamic Registration: nDestroy(J)V (table at 0x534a48)
// Calls external APIs: _ZNSt6__ndk119__shared_weak_count14__release_weakEv, _ZdlPv, __android_log_print
// Strings referenced:
//   "iklf_"
//   "nDestroyInfo is called,addr => %p"

jobject _ZN11LayerFlowNS29LFEffectOneClickBeautyDataJNI12nDestroyInfoEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 35 instructions
    /* 0x2d1f50 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2d1f54 */ stp x20, x19, [sp, #0x10];
    /* 0x2d1f58 */ mov x29, sp;
    /* 0x2d1f5c */ mov x19, x2;
    /* 0x2d1f60 */ adrp x1, #0x1e1000;
    /* 0x2d1f64 */ add x1, x1, #0x361;
    /* 0x2d1f68 */ adrp x2, #0x1dd000;
    /* 0x2d1f6c */ add x2, x2, #0xecd;
    /* 0x2d1f70 */ mov w0, #6;
    /* 0x2d1f74 */ mov x3, x19;
    __android_log_print();
    sub_5263e0();
    return x0;
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
}

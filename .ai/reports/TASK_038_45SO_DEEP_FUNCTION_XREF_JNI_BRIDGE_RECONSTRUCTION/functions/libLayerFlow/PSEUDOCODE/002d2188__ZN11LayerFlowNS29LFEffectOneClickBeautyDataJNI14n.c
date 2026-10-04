// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d2188
// Recovered Name: _ZN11LayerFlowNS29LFEffectOneClickBeautyDataJNI14nDestroyResultEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d2188 | Size: 188 bytes | SHA256: 290945d318bf0838430670c2b2ec49652078c9cabadc9d987bae2fd9f8b9da23
// Callers: 0 | Callees: 1 | Imports: 3

// Dynamic Registration: nDestroyResult(J)V (table at 0x534da8)
// Calls external APIs: _ZNSt6__ndk119__shared_weak_count14__release_weakEv, _ZdlPv, __android_log_print
// Strings referenced:
//   "iklf_"
//   "nDestroyResult is called, addr => %p"

jobject _ZN11LayerFlowNS29LFEffectOneClickBeautyDataJNI14nDestroyResultEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 47 instructions
    /* 0x2d2188 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2d218c */ stp x20, x19, [sp, #0x10];
    /* 0x2d2190 */ mov x29, sp;
    /* 0x2d2194 */ mov x19, x2;
    /* 0x2d2198 */ adrp x1, #0x1e1000;
    /* 0x2d219c */ add x1, x1, #0x361;
    /* 0x2d21a0 */ adrp x2, #0x1d5000;
    /* 0x2d21a4 */ add x2, x2, #0x426;
    /* 0x2d21a8 */ mov w0, #6;
    /* 0x2d21ac */ mov x3, x19;
    __android_log_print();
    sub_5263e0();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    sub_5263e0();
    return x0;
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
}

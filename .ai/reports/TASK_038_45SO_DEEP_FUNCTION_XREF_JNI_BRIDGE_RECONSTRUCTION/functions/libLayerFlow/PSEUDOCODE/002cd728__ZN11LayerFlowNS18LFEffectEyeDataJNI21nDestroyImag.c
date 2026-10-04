// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2cd728
// Recovered Name: _ZN11LayerFlowNS18LFEffectEyeDataJNI21nDestroyImageCropInfoEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2cd728 | Size: 156 bytes | SHA256: 2d48e28bdd4cd98d4c1078ca27e1dd31c55068082992db3b167f08ea9538bd76
// Callers: 0 | Callees: 1 | Imports: 3

// Dynamic Registration: nDestroy(J)V (table at 0x533f60)
// Calls external APIs: _ZNSt6__ndk119__shared_weak_count14__release_weakEv, _ZdlPv, __android_log_print
// Strings referenced:
//   "nDestroyImageCropInfo is called, addr => %p"

jobject _ZN11LayerFlowNS18LFEffectEyeDataJNI21nDestroyImageCropInfoEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 39 instructions
    /* 0x2cd728 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2cd72c */ stp x20, x19, [sp, #0x10];
    /* 0x2cd730 */ mov x29, sp;
    /* 0x2cd734 */ mov x19, x2;
    /* 0x2cd738 */ nop ;
    /* 0x2cd73c */ adr x1, #0x1e1361;
    /* 0x2cd740 */ adrp x2, #0x1e3000;
    /* 0x2cd744 */ add x2, x2, #0x70d;
    /* 0x2cd748 */ mov w0, #6;
    /* 0x2cd74c */ mov x3, x19;
    __android_log_print();
    _ZdlPv();
    sub_5263e0();
    return x0;
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
}

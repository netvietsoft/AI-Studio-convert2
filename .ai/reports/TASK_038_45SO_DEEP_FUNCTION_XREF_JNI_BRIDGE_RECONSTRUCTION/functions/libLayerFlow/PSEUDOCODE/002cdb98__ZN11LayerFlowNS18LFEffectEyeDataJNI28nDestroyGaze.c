// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2cdb98
// Recovered Name: _ZN11LayerFlowNS18LFEffectEyeDataJNI28nDestroyGazeCorrectCacheDataEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2cdb98 | Size: 140 bytes | SHA256: f38467c4d844fc26d64655a29bc2dc99e26badb4e85b878bd95a35f939e78ea4
// Callers: 0 | Callees: 1 | Imports: 3

// Dynamic Registration: nDestroy(J)V (table at 0x534128)
// Calls external APIs: _ZNSt6__ndk119__shared_weak_count14__release_weakEv, _ZdlPv, __android_log_print
// Strings referenced:
//   "nDestroyGazeCorrectCacheData is called, addr => %p"

jobject _ZN11LayerFlowNS18LFEffectEyeDataJNI28nDestroyGazeCorrectCacheDataEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 35 instructions
    /* 0x2cdb98 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2cdb9c */ stp x20, x19, [sp, #0x10];
    /* 0x2cdba0 */ mov x29, sp;
    /* 0x2cdba4 */ mov x19, x2;
    /* 0x2cdba8 */ nop ;
    /* 0x2cdbac */ adr x1, #0x1e1361;
    /* 0x2cdbb0 */ adrp x2, #0x1d7000;
    /* 0x2cdbb4 */ add x2, x2, #0x964;
    /* 0x2cdbb8 */ mov w0, #6;
    /* 0x2cdbbc */ mov x3, x19;
    __android_log_print();
    sub_5263e0();
    return x0;
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
}

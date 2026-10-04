// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2bb440
// Recovered Name: _ZN11LayerFlowNS18LFAigcCacheDataJNI22nSetThinBellyAigcCacheEP7_JNIEnvP7_jclassll
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2bb440 | Size: 276 bytes | SHA256: 713b2eda26636b59717d5da043e21812d588183a047931153e020b77fb8cf4da
// Callers: 0 | Callees: 5 | Imports: 4

// Dynamic Registration: nSetThinBellyAigcCache(JJ)V (table at 0x531210)
// Calls external APIs: _ZNSt6__ndk119__shared_weak_count14__release_weakEv, _ZNSt6__ndk119__shared_weak_countD2Ev, _ZdlPv, _Znwm

jobject _ZN11LayerFlowNS18LFAigcCacheDataJNI22nSetThinBellyAigcCacheEP7_JNIEnvP7_jclassll(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 69 instructions
    /* 0x2bb440 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x2bb444 */ stp x22, x21, [sp, #0x10];
    /* 0x2bb448 */ stp x20, x19, [sp, #0x20];
    /* 0x2bb44c */ mov x29, sp;
    /* 0x2bb450 */ cbz x2, #0x2bb4fc;
    /* 0x2bb454 */ mov x19, x2;
    /* 0x2bb458 */ mov x22, x3;
    /* 0x2bb45c */ cbz x3, #0x2bb4c4;
    /* 0x2bb460 */ mov w0, #0x40;
    _Znwm();
    /* 0x2bb468 */ adrp x8, #0x54a000;
    sub_5263b0();
    sub_2bc260();
    sub_5263e0();
    return x0;
    sub_2bbdb4();
    _ZNSt6__ndk119__shared_weak_countD2Ev();
    _ZdlPv();
    sub_526544();
}

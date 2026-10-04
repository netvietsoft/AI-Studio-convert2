// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2bb2c0
// Recovered Name: _ZN11LayerFlowNS18LFAigcCacheDataJNI25nSetStraightLegsAigcCacheEP7_JNIEnvP7_jclassll
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2bb2c0 | Size: 204 bytes | SHA256: 379d38fc0c1509ed7ddbd8a98a4fdc807d68a8c77902ef343489b28087614398
// Callers: 0 | Callees: 3 | Imports: 4

// Dynamic Registration: nSetStraightLegsAigcCache(JJ)V (table at 0x5311e0)
// Calls external APIs: _ZNSt6__ndk119__shared_weak_count14__release_weakEv, _ZNSt6__ndk119__shared_weak_countD2Ev, _ZdlPv, _Znwm

jobject _ZN11LayerFlowNS18LFAigcCacheDataJNI25nSetStraightLegsAigcCacheEP7_JNIEnvP7_jclassll(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 51 instructions
    /* 0x2bb2c0 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x2bb2c4 */ stp x22, x21, [sp, #0x10];
    /* 0x2bb2c8 */ stp x20, x19, [sp, #0x20];
    /* 0x2bb2cc */ mov x29, sp;
    /* 0x2bb2d0 */ cbz x2, #0x2bb33c;
    /* 0x2bb2d4 */ mov x20, x2;
    /* 0x2bb2d8 */ mov x19, x3;
    /* 0x2bb2dc */ cbz x3, #0x2bb320;
    /* 0x2bb2e0 */ mov w0, #0x48;
    _Znwm();
    /* 0x2bb2e8 */ adrp x8, #0x54a000;
    _ZN11LayerFlowNS31LFStraightLegsAIGCRequestResultC2ERKS0_();
    sub_5263e0();
    return x0;
    _ZNSt6__ndk119__shared_weak_countD2Ev();
    _ZdlPv();
    sub_526544();
}

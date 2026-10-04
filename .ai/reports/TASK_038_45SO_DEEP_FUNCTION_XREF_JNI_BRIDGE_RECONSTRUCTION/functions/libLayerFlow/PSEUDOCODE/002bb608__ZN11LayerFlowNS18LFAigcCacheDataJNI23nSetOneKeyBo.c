// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2bb608
// Recovered Name: _ZN11LayerFlowNS18LFAigcCacheDataJNI23nSetOneKeyBodyAigcCacheEP7_JNIEnvP7_jclassll
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2bb608 | Size: 276 bytes | SHA256: 53d8c7fec10b0317ec788d0492d3a020b5c123aa20ce8a2e43436238713404d2
// Callers: 0 | Callees: 5 | Imports: 4

// Dynamic Registration: nSetOneKeyBodyAigcCache(JJ)V (table at 0x531240)
// Calls external APIs: _ZNSt6__ndk119__shared_weak_count14__release_weakEv, _ZNSt6__ndk119__shared_weak_countD2Ev, _ZdlPv, _Znwm

jobject _ZN11LayerFlowNS18LFAigcCacheDataJNI23nSetOneKeyBodyAigcCacheEP7_JNIEnvP7_jclassll(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 69 instructions
    /* 0x2bb608 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x2bb60c */ stp x22, x21, [sp, #0x10];
    /* 0x2bb610 */ stp x20, x19, [sp, #0x20];
    /* 0x2bb614 */ mov x29, sp;
    /* 0x2bb618 */ cbz x2, #0x2bb6c4;
    /* 0x2bb61c */ mov x19, x2;
    /* 0x2bb620 */ mov x22, x3;
    /* 0x2bb624 */ cbz x3, #0x2bb68c;
    /* 0x2bb628 */ mov w0, #0x40;
    _Znwm();
    /* 0x2bb630 */ adrp x8, #0x54a000;
    sub_5263b0();
    sub_2bc260();
    sub_5263e0();
    return x0;
    sub_2bbdb4();
    _ZNSt6__ndk119__shared_weak_countD2Ev();
    _ZdlPv();
    sub_526544();
}

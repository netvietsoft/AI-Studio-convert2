// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2bb0dc
// Recovered Name: _ZN11LayerFlowNS18LFAigcCacheDataJNI25nGetStraightLegsAigcCacheEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2bb0dc | Size: 96 bytes | SHA256: 7b17f1f984d5d5e42c06f78b65c8e78cacb6f9b03264764e7d8d0a33c64c52d6
// Callers: 0 | Callees: 2 | Imports: 2

// Dynamic Registration: nGetStraightLegsAigcCache(J)J (table at 0x5311c8)
// Calls external APIs: _ZdlPv, _Znwm

jobject _ZN11LayerFlowNS18LFAigcCacheDataJNI25nGetStraightLegsAigcCacheEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 24 instructions
    /* 0x2bb0dc */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2bb0e0 */ stp x20, x19, [sp, #0x10];
    /* 0x2bb0e4 */ mov x29, sp;
    /* 0x2bb0e8 */ cbz x2, #0x2bb118;
    /* 0x2bb0ec */ ldr x19, [x2, #0x90];
    /* 0x2bb0f0 */ cbz x19, #0x2bb118;
    /* 0x2bb0f4 */ mov w0, #0x30;
    _Znwm();
    /* 0x2bb0fc */ mov x1, x19;
    /* 0x2bb100 */ mov x20, x0;
    _ZN11LayerFlowNS31LFStraightLegsAIGCRequestResultC2ERKS0_();
    return x0;
    return x0;
    _ZdlPv();
    sub_526544();
}

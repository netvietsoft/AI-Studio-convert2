// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2bb38c
// Recovered Name: _ZN11LayerFlowNS18LFAigcCacheDataJNI22nGetThinBellyAigcCacheEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2bb38c | Size: 180 bytes | SHA256: 60821b66d99dffbed0f71851b3aa342e29c7962fbb350be88e13b4699570df3f
// Callers: 0 | Callees: 4 | Imports: 2

// Dynamic Registration: nGetThinBellyAigcCache(J)J (table at 0x5311f8)
// Calls external APIs: _ZdlPv, _Znwm

jobject _ZN11LayerFlowNS18LFAigcCacheDataJNI22nGetThinBellyAigcCacheEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 45 instructions
    /* 0x2bb38c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2bb390 */ stp x20, x19, [sp, #0x10];
    /* 0x2bb394 */ mov x29, sp;
    /* 0x2bb398 */ cbz x2, #0x2bb3f4;
    /* 0x2bb39c */ ldr x20, [x2, #0xa0];
    /* 0x2bb3a0 */ cbz x20, #0x2bb3f4;
    /* 0x2bb3a4 */ mov w0, #0x28;
    _Znwm();
    /* 0x2bb3ac */ ldp x9, x8, [x20];
    /* 0x2bb3b0 */ mov x19, x0;
    /* 0x2bb3b4 */ stp x9, x8, [x0];
    sub_5263b0();
    return x0;
    return x0;
    sub_2bc260();
    return x0;
    sub_2bbdb4();
    _ZdlPv();
    sub_526544();
}

// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2bb554
// Recovered Name: _ZN11LayerFlowNS18LFAigcCacheDataJNI23nGetOneKeyBodyAigcCacheEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2bb554 | Size: 180 bytes | SHA256: cf6f16542a7b4d18423f362d2ebe23a2c98c639aa787b2b6bfb52c3ea504ed48
// Callers: 0 | Callees: 4 | Imports: 2

// Dynamic Registration: nGetOneKeyBodyAigcCache(J)J (table at 0x531228)
// Calls external APIs: _ZdlPv, _Znwm

jobject _ZN11LayerFlowNS18LFAigcCacheDataJNI23nGetOneKeyBodyAigcCacheEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 45 instructions
    /* 0x2bb554 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2bb558 */ stp x20, x19, [sp, #0x10];
    /* 0x2bb55c */ mov x29, sp;
    /* 0x2bb560 */ cbz x2, #0x2bb5bc;
    /* 0x2bb564 */ ldr x20, [x2, #0xb0];
    /* 0x2bb568 */ cbz x20, #0x2bb5bc;
    /* 0x2bb56c */ mov w0, #0x28;
    _Znwm();
    /* 0x2bb574 */ ldp x9, x8, [x20];
    /* 0x2bb578 */ mov x19, x0;
    /* 0x2bb57c */ stp x9, x8, [x0];
    sub_5263b0();
    return x0;
    return x0;
    sub_2bc260();
    return x0;
    sub_2bbdb4();
    _ZdlPv();
    sub_526544();
}

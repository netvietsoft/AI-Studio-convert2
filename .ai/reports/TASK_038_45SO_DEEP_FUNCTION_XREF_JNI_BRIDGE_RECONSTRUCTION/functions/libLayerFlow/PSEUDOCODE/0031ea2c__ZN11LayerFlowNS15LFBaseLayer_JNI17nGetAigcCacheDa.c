// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x31ea2c
// Recovered Name: _ZN11LayerFlowNS15LFBaseLayer_JNI17nGetAigcCacheDataEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x31ea2c | Size: 132 bytes | SHA256: 9f7b966170eefc478180a644cb9c17ab15d06ccdec2e843eff92ee92a514ed48
// Callers: 0 | Callees: 2 | Imports: 3

// Dynamic Registration: nGetAigcCacheData(J)J (table at 0x53c3b0)
// Calls external APIs: _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z, _ZdlPv, _Znwm
// Strings referenced:
//   "LFBaseLayerJNI<%s:%d> nGetAigcCacheData: invalid layer pointer"
//   "iklf"
//   "nGetAigcCacheData"

jobject _ZN11LayerFlowNS15LFBaseLayer_JNI17nGetAigcCacheDataEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 33 instructions
    /* 0x31ea2c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x31ea30 */ stp x20, x19, [sp, #0x10];
    /* 0x31ea34 */ mov x29, sp;
    /* 0x31ea38 */ cbz x2, #0x31ea68;
    /* 0x31ea3c */ ldr x19, [x2];
    /* 0x31ea40 */ cbz x19, #0x31ea68;
    /* 0x31ea44 */ mov w0, #0xc0;
    _Znwm();
    /* 0x31ea4c */ add x1, x19, #0x408;
    /* 0x31ea50 */ mov x19, x0;
    _ZN11LayerFlowNS15LFAigcCacheDataC2ERKS0_();
    return x0;
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    return x0;
    _ZdlPv();
    sub_526544();
}

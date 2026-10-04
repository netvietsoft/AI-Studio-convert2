// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2b8db4
// Recovered Name: _ZN11LayerFlowNS18LFAigcCacheDataJNI8nDestroyEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2b8db4 | Size: 84 bytes | SHA256: d74833e2eaf03927102728298caf0b9cf86af94cf20d6039a1c239ea179d7c73
// Callers: 0 | Callees: 1 | Imports: 2

// Dynamic Registration: nDestroy(J)V (table at 0x5310f0)
// Calls external APIs: _ZdlPv, __android_log_print
// Strings referenced:
//   "LFAigcCacheDataJNI::nDestroy addr => %p"

jobject _ZN11LayerFlowNS18LFAigcCacheDataJNI8nDestroyEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 21 instructions
    /* 0x2b8db4 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2b8db8 */ str x19, [sp, #0x10];
    /* 0x2b8dbc */ mov x29, sp;
    /* 0x2b8dc0 */ mov x19, x2;
    /* 0x2b8dc4 */ nop ;
    /* 0x2b8dc8 */ adr x1, #0x1e1361;
    /* 0x2b8dcc */ adrp x2, #0x1e1000;
    /* 0x2b8dd0 */ add x2, x2, #0x367;
    /* 0x2b8dd4 */ mov w0, #6;
    /* 0x2b8dd8 */ mov x3, x19;
    __android_log_print();
    _ZN11LayerFlowNS15LFAigcCacheDataD2Ev();
    return x0;
}

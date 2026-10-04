// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2f291c
// Recovered Name: _ZN11LayerFlowNS16LFTextModularJNI15nSetIsUnderlineEP7_JNIEnvP8_jobjectlh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2f291c | Size: 16 bytes | SHA256: 7195c425eafd4881a2157288f22baddad5953380c86b592c8b6b991f4ad14a47
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetIsUnderline(JZ)V (table at 0x53a9c0)

jobject _ZN11LayerFlowNS16LFTextModularJNI15nSetIsUnderlineEP7_JNIEnvP8_jobjectlh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2f291c */ tst w3, #0xff;
    /* 0x2f2920 */ cset w8, ne;
    /* 0x2f2924 */ strb w8, [x2, #0x4a];
    return x0;
}

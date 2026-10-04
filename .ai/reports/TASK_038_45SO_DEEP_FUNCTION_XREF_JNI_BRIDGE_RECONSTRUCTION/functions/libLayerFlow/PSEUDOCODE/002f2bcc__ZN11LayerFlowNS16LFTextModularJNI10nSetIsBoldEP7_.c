// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2f2bcc
// Recovered Name: _ZN11LayerFlowNS16LFTextModularJNI10nSetIsBoldEP7_JNIEnvP8_jobjectlh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2f2bcc | Size: 16 bytes | SHA256: 574593c6558f5d4d6cf5d40648d74d875f5709a89b25921ee8b0a6fe7aa08fd2
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetIsBold(JZ)V (table at 0x53ad20)

jobject _ZN11LayerFlowNS16LFTextModularJNI10nSetIsBoldEP7_JNIEnvP8_jobjectlh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2f2bcc */ tst w3, #0xff;
    /* 0x2f2bd0 */ cset w8, ne;
    /* 0x2f2bd4 */ strb w8, [x2, #0xf0];
    return x0;
}

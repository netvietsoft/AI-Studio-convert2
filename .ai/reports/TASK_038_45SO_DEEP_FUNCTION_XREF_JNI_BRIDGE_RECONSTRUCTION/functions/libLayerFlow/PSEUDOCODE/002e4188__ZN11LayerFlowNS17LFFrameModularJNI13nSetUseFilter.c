// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2e4188
// Recovered Name: _ZN11LayerFlowNS17LFFrameModularJNI13nSetUseFilterEP7_JNIEnvP8_jobjectlh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2e4188 | Size: 16 bytes | SHA256: 4d9a2b2863279c682ba5b245c3344ea251de9064231cafc4c4168d5b74b20aa3
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetUseFilter(JZ)V (table at 0x538008)

jobject _ZN11LayerFlowNS17LFFrameModularJNI13nSetUseFilterEP7_JNIEnvP8_jobjectlh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2e4188 */ tst w3, #0xff;
    /* 0x2e418c */ cset w8, ne;
    /* 0x2e4190 */ strb w8, [x2, #0x38];
    return x0;
}

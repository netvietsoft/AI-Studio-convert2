// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2f2814
// Recovered Name: _ZN11LayerFlowNS16LFTextModularJNI14nSetIsVerticalEP7_JNIEnvP8_jobjectlh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2f2814 | Size: 16 bytes | SHA256: 57c334fde5f89f396b1b6c9eb27685227127c4a8cdf828ad5cbdb4eced81a110
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetIsVertical(JZ)V (table at 0x53a870)

jobject _ZN11LayerFlowNS16LFTextModularJNI14nSetIsVerticalEP7_JNIEnvP8_jobjectlh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2f2814 */ tst w3, #0xff;
    /* 0x2f2818 */ cset w8, ne;
    /* 0x2f281c */ strb w8, [x2, #0x19];
    return x0;
}

// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2e72fc
// Recovered Name: _ZN11LayerFlowNS18LFMakeUpModularJNI17nDestroyColorInfoEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2e72fc | Size: 16 bytes | SHA256: 6f83e4e365e3b5155b58eaf9863fe09712b0a84e79d387f2679cd08aa552d1e8
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nDestroyColorInfo(J)V (table at 0x538770)
// Calls external APIs: _ZdlPv

jobject _ZN11LayerFlowNS18LFMakeUpModularJNI17nDestroyColorInfoEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2e72fc */ cbz x2, #0x2e7308;
    /* 0x2e7300 */ mov x0, x2;
    /* 0x2e7304 */ b #0x52a280;
    return x0;
}

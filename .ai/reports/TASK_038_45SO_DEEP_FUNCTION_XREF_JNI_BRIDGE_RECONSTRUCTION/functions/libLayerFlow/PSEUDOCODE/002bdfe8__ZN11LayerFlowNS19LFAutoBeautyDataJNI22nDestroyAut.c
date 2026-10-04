// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2bdfe8
// Recovered Name: _ZN11LayerFlowNS19LFAutoBeautyDataJNI22nDestroyAutoBeautyModeEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2bdfe8 | Size: 16 bytes | SHA256: 16adf5b046e88ddf74f657635dcc56413f7fcc182fd110b530ff1b520dffe366
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nDestroy(J)V (table at 0x531820)
// Calls external APIs: _ZdlPv

jobject _ZN11LayerFlowNS19LFAutoBeautyDataJNI22nDestroyAutoBeautyModeEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2bdfe8 */ cbz x2, #0x2bdff4;
    /* 0x2bdfec */ mov x0, x2;
    /* 0x2bdff0 */ b #0x52a280;
    return x0;
}

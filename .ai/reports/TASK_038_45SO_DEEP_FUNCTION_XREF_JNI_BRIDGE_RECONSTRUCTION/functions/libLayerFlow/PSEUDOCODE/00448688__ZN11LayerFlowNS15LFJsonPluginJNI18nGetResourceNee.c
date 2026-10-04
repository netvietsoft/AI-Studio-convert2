// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x448688
// Recovered Name: _ZN11LayerFlowNS15LFJsonPluginJNI18nGetResourceNeededEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x448688 | Size: 28 bytes | SHA256: d59879f266ec38a45237afc37da0f7f5fe26c191db598d4573391d492a99fc7f
// Callers: 0 | Callees: 1 | Imports: 0

// Dynamic Registration: nGetResourceNeeded(J)Z (table at 0x546208)

jobject _ZN11LayerFlowNS15LFJsonPluginJNI18nGetResourceNeededEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x448688 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x44868c */ mov x29, sp;
    /* 0x448690 */ mov x0, x2;
    _ZN11LayerFlowNS12LFJsonPlugin17getResourceNeededEv();
    /* 0x448698 */ and w0, w0, #1;
    /* 0x44869c */ ldp x29, x30, [sp], #0x10;
    return x0;
}

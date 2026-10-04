// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2ded98
// Recovered Name: _ZN11LayerFlowNS19LFFaceRemoldDataJNI28nGetFeatureParamDictListSizeEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2ded98 | Size: 28 bytes | SHA256: baadfe850629dafafbac858efb00bf334c64604e9d1c5e295dec153f98417ecf
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nGetFeatureParamDictListSize(J)I (table at 0x537768)

jobject _ZN11LayerFlowNS19LFFaceRemoldDataJNI28nGetFeatureParamDictListSizeEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x2ded98 */ ldp x9, x8, [x2, #0x40];
    /* 0x2ded9c */ sub x8, x8, x9;
    /* 0x2deda0 */ mov w9, #0xaaab;
    /* 0x2deda4 */ lsr x8, x8, #3;
    /* 0x2deda8 */ movk w9, #0xaaaa, lsl #16;
    /* 0x2dedac */ mul w0, w8, w9;
    return x0;
}

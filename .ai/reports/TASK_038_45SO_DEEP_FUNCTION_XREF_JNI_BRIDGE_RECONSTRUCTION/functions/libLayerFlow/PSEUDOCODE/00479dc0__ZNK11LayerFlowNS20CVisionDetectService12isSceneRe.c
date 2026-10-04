// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x479dc0
// Recovered Name: _ZNK11LayerFlowNS20CVisionDetectService12isSceneReadyEv
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x479dc0 | Size: 32 bytes | SHA256: b4e7856bd869adcb30b2f8b34641b3013ccd4cc9a6b8468e514c2809abac4947
// Callers: 1 | Callees: 0 | Imports: 0


void _ZNK11LayerFlowNS20CVisionDetectService12isSceneReadyEv(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x479dc0 */ ldr x8, [x0, #0x18];
    /* 0x479dc4 */ cbz x8, #0x479dd8;
    /* 0x479dc8 */ ldrb w8, [x8, #0x18];
    /* 0x479dcc */ cmp w8, #0;
    /* 0x479dd0 */ cset w0, ne;
    return x0;
    /* 0x479dd8 */ mov w0, wzr;
    return x0;
}

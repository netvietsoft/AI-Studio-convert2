// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2f0c2c
// Recovered Name: _ZN11LayerFlowNS19LFStickerModularJNI17nIsLocalGeneratedEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2f0c2c | Size: 28 bytes | SHA256: 501b04d7f679ffc8fc1d84d1eca13e50d0051260a162077420a8626a7f32809f
// Callers: 0 | Callees: 1 | Imports: 0

// Dynamic Registration: nIsLocalGenerated(J)Z (table at 0x53a3c8)

jobject _ZN11LayerFlowNS19LFStickerModularJNI17nIsLocalGeneratedEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x2f0c2c */ stp x29, x30, [sp, #-0x10]!;
    /* 0x2f0c30 */ mov x29, sp;
    /* 0x2f0c34 */ mov x0, x2;
    _ZN16LFStickerModular16isLocalGeneratedEv();
    /* 0x2f0c3c */ and w0, w0, #1;
    /* 0x2f0c40 */ ldp x29, x30, [sp], #0x10;
    return x0;
}

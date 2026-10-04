// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3d46a0
// Recovered Name: _ZN11LayerFlowNS24LFStickerLocateStatusJNI8nSetFlipEP7_JNIEnvP8_jobjectlh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x3d46a0 | Size: 16 bytes | SHA256: 6c1313f4ee8c2a98b8437dce91f894fd938a414f7acb7e660e60f6fdc7b6521b
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetFlip(JZ)V (table at 0x542240)

jobject _ZN11LayerFlowNS24LFStickerLocateStatusJNI8nSetFlipEP7_JNIEnvP8_jobjectlh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x3d46a0 */ tst w3, #0xff;
    /* 0x3d46a4 */ cset w8, ne;
    /* 0x3d46a8 */ strb w8, [x2, #0x10];
    return x0;
}

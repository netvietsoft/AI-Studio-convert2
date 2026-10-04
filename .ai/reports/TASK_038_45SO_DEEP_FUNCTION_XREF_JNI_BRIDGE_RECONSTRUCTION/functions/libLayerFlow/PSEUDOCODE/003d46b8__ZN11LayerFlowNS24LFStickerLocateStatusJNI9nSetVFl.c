// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3d46b8
// Recovered Name: _ZN11LayerFlowNS24LFStickerLocateStatusJNI9nSetVFlipEP7_JNIEnvP8_jobjectlh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x3d46b8 | Size: 16 bytes | SHA256: f63178651d3fc8d848473f1018ad92c22256dc35a67bcbbb17555aba21ea3e7b
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetVFlip(JZ)V (table at 0x542270)

jobject _ZN11LayerFlowNS24LFStickerLocateStatusJNI9nSetVFlipEP7_JNIEnvP8_jobjectlh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x3d46b8 */ tst w3, #0xff;
    /* 0x3d46bc */ cset w8, ne;
    /* 0x3d46c0 */ strb w8, [x2, #0x11];
    return x0;
}

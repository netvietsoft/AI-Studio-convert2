// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3d4648
// Recovered Name: _ZN11LayerFlowNS24LFStickerLocateStatusJNI8nDestroyEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x3d4648 | Size: 16 bytes | SHA256: 960efe1637d2722c74f67c797b920493882990bfd54b024cd25913af7812ac93
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nDestroy(J)V (table at 0x542150)
// Calls external APIs: _ZdlPv

jobject _ZN11LayerFlowNS24LFStickerLocateStatusJNI8nDestroyEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x3d4648 */ cbz x2, #0x3d4654;
    /* 0x3d464c */ mov x0, x2;
    /* 0x3d4650 */ b #0x52a280;
    return x0;
}

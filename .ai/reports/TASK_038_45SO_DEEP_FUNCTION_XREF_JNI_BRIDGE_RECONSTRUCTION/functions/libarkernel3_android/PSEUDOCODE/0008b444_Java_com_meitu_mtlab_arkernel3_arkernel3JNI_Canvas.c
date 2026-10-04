// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8b444
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_CanvasProperty_1layerOutlineBorderMarginBottom_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8b444 | Size: 12 bytes | SHA256: a5cebee73c732e782ecd8ec7d41895ef62676786d3eac6a1cfbd8acace568877
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_CanvasProperty_1layerOutlineBorderMarginBottom_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x8b444 */ cbz x2, #0x8b44c;
    /* 0x8b448 */ str w4, [x2, #0x24];
    return x0;
}

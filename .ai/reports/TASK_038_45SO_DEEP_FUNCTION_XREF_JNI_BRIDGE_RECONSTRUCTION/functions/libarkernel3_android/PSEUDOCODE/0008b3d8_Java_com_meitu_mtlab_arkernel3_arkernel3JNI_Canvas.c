// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8b3d8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_CanvasProperty_1layerMaxValue_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8b3d8 | Size: 12 bytes | SHA256: 7defaf0f7508fa958f29388d2024b0e6433a7457c1b3811560b858cb530bbc6a
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_CanvasProperty_1layerMaxValue_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x8b3d8 */ cbz x2, #0x8b3e0;
    /* 0x8b3dc */ str w4, [x2, #0x10];
    return x0;
}

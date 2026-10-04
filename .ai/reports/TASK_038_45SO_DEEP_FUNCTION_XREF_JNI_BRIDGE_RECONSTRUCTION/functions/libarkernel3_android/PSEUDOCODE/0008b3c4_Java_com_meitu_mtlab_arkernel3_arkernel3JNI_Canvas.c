// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8b3c4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_CanvasProperty_1layerMinValue_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8b3c4 | Size: 12 bytes | SHA256: 160ecb4f4aa43e0583cdf7637e028cc6857a339e457358d11554abda93a7d18d
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_CanvasProperty_1layerMinValue_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x8b3c4 */ cbz x2, #0x8b3cc;
    /* 0x8b3c8 */ str w4, [x2, #0xc];
    return x0;
}

// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x87dd4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_RectI_1bottom_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x87dd4 | Size: 12 bytes | SHA256: 160ecb4f4aa43e0583cdf7637e028cc6857a339e457358d11554abda93a7d18d
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_RectI_1bottom_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x87dd4 */ cbz x2, #0x87ddc;
    /* 0x87dd8 */ str w4, [x2, #0xc];
    return x0;
}

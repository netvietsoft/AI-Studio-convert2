// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8c7b0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_WatermarkConfig_1rightTop_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8c7b0 | Size: 16 bytes | SHA256: b7c2e078f998734a4a43b390963f4c17ecbcc8ea5483e5df66aad70c7bc2d828
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_WatermarkConfig_1rightTop_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8c7b0 */ cbz x2, #0x8c7bc;
    /* 0x8c7b4 */ ldr x8, [x4];
    /* 0x8c7b8 */ str x8, [x2, #0x28];
    return x0;
}

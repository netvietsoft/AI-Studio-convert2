// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8c330
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextPathConfig_1spacing_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8c330 | Size: 12 bytes | SHA256: 1eabf71d61208d3c9d341f7e5f3c651e72ca0ed165ca3b8df280d5418b29e01e
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextPathConfig_1spacing_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x8c330 */ cbz x2, #0x8c338;
    /* 0x8c334 */ str s0, [x2, #0x48];
    return x0;
}

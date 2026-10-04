// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8b5b8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ImportBytesData_1ptr_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8b5b8 | Size: 12 bytes | SHA256: 4d09737a3d5b6022354ff1afefc93294808867c29b9444d02ebdf562c85d8d93
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ImportBytesData_1ptr_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x8b5b8 */ cbz x2, #0x8b5c0;
    /* 0x8b5bc */ str x4, [x2];
    return x0;
}

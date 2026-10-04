// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8b774
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ImportStickerData_1bytesData_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8b774 | Size: 16 bytes | SHA256: 5db0153fe4820a99030527929ddc2a02df920a6f9704ca1d422fe0718870cfed
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ImportStickerData_1bytesData_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8b774 */ cbz x2, #0x8b780;
    /* 0x8b778 */ ldr q0, [x4];
    /* 0x8b77c */ str q0, [x2];
    return x0;
}

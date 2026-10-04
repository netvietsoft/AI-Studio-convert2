// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8b7ec
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_MvImportStickerConfigStruct_1data_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8b7ec | Size: 16 bytes | SHA256: 42bb0d1e43a89f64224603b1a92158ad6170b3689dddebb0689930fc108d2312
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_MvImportStickerConfigStruct_1data_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8b7ec */ cbz x2, #0x8b7f8;
    /* 0x8b7f0 */ ldr q0, [x4];
    /* 0x8b7f4 */ stur q0, [x2, #8];
    return x0;
}

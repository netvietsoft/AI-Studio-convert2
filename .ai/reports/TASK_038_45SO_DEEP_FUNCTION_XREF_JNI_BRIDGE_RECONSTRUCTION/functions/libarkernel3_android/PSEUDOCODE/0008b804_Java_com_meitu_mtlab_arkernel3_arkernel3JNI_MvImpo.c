// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8b804
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_MvImportStickerConfigStruct_1defaultSize_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8b804 | Size: 16 bytes | SHA256: f61b63ef11b4c4d8db40496db14796c9aed50b4505df686c99900f18ec4c7655
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_MvImportStickerConfigStruct_1defaultSize_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8b804 */ cbz x2, #0x8b810;
    /* 0x8b808 */ ldr x8, [x4];
    /* 0x8b80c */ str x8, [x2, #0x18];
    return x0;
}

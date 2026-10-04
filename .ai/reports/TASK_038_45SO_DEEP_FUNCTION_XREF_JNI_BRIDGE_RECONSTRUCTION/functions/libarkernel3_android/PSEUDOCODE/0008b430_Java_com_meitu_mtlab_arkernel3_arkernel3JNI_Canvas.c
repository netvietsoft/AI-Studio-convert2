// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8b430
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_CanvasProperty_1layerOutlineBorderMarginTop_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8b430 | Size: 12 bytes | SHA256: 7c128e2299b5ed96885d7115cbd3c610e814e456d4e1c59bc5cc72f1d45d8ad0
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_CanvasProperty_1layerOutlineBorderMarginTop_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x8b430 */ cbz x2, #0x8b438;
    /* 0x8b434 */ str w4, [x2, #0x20];
    return x0;
}

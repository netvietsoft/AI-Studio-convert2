// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8b458
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_CanvasProperty_1layerOutlineBorderMinValue_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8b458 | Size: 12 bytes | SHA256: 108bdf934bd85fe009ae925b3c3124ef196501ae53359b748771fa75236717c7
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_CanvasProperty_1layerOutlineBorderMinValue_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x8b458 */ cbz x2, #0x8b460;
    /* 0x8b45c */ str w4, [x2, #0x28];
    return x0;
}

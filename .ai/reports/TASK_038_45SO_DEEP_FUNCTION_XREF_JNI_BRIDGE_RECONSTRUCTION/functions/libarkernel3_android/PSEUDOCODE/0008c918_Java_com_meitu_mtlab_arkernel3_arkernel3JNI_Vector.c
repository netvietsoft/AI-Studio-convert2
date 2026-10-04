// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8c918
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorSelectHighlightConfig_1size
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8c918 | Size: 16 bytes | SHA256: 848060e9c73c7dfff8a20313e504ce1dfd5acc1a8954da71bb41df0a7efa7254
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorSelectHighlightConfig_1size(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8c918 */ ldp x9, x8, [x2];
    /* 0x8c91c */ sub x8, x8, x9;
    /* 0x8c920 */ asr x0, x8, #5;
    return x0;
}

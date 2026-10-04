// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8ca20
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorSelectHighlightConfig_1isEmpty
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8ca20 | Size: 16 bytes | SHA256: 8872faf05077c5ab467600353dde902aa58d237b4d27b1fc226d45d521bc25c9
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorSelectHighlightConfig_1isEmpty(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8ca20 */ ldp x8, x9, [x2];
    /* 0x8ca24 */ cmp x8, x9;
    /* 0x8ca28 */ cset w0, eq;
    return x0;
}

// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x89ffc
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ParameterFloat3_1x_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x89ffc | Size: 12 bytes | SHA256: 7b3d93824fb7383236a7fbe20bc6c753df316fdf0468bd55ac8c5f27c07f7773
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ParameterFloat3_1x_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x89ffc */ cbz x2, #0x8a004;
    /* 0x8a000 */ str s0, [x2];
    return x0;
}

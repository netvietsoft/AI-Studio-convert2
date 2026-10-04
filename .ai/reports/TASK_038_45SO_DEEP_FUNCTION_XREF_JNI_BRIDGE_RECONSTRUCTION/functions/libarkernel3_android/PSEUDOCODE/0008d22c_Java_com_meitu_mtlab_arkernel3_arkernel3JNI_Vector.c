// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8d22c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorAnimationTimeType_1size
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8d22c | Size: 16 bytes | SHA256: 75f095eaa34ebb160e933f9df958556015cf3db94365beefef29e64cc9536d4e
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorAnimationTimeType_1size(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8d22c */ ldp x9, x8, [x2];
    /* 0x8d230 */ sub x8, x8, x9;
    /* 0x8d234 */ asr x0, x8, #2;
    return x0;
}

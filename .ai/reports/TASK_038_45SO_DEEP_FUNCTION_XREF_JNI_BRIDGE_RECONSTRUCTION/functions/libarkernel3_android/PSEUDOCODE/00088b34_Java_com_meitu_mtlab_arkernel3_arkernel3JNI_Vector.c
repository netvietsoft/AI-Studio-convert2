// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x88b34
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorPoint2F_1size
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x88b34 | Size: 16 bytes | SHA256: 6832c482a29e4012755ae7865d0b0ddd9388a9bd1836031058aa9face78412dd
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorPoint2F_1size(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x88b34 */ ldp x9, x8, [x2];
    /* 0x88b38 */ sub x8, x8, x9;
    /* 0x88b3c */ asr x0, x8, #3;
    return x0;
}

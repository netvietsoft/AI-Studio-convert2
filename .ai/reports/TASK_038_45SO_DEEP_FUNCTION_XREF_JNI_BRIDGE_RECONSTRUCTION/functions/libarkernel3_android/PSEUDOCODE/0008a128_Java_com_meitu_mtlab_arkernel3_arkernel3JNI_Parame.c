// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8a128
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ParameterValue_1_1boolean_1get
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8a128 | Size: 8 bytes | SHA256: 95fd35e42365ae47a0bf8e55489391d905bd03e8574b81a6bae86cf3444ad58b
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ParameterValue_1_1boolean_1get(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 2 instructions
    /* 0x8a128 */ ldrb w0, [x2, #0x18];
    return x0;
}

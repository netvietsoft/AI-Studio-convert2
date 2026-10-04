// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8a130
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ParameterValue_1floating_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8a130 | Size: 12 bytes | SHA256: 0883907a016c8d4b655d23685dc5f0c3ae0884dc18e29fb7cb0980a2c6fd8d9d
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ParameterValue_1floating_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x8a130 */ cbz x2, #0x8a138;
    /* 0x8a134 */ str d0, [x2, #0x20];
    return x0;
}

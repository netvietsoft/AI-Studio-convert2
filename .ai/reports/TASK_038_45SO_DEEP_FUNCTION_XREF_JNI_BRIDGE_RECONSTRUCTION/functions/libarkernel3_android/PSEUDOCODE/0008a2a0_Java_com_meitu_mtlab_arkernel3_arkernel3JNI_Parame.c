// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8a2a0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ParameterValue_1color_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8a2a0 | Size: 16 bytes | SHA256: 1358ae13d1c14e50f1fb04b6df6b0f4ffd0c07a8ae2ec645dd2af0ad27cf4ba4
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ParameterValue_1color_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8a2a0 */ cbz x2, #0x8a2ac;
    /* 0x8a2a4 */ ldr q0, [x4];
    /* 0x8a2a8 */ stur q0, [x2, #0x48];
    return x0;
}

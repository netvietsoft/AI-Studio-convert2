// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8a468
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ParameterValue_1rect2_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8a468 | Size: 16 bytes | SHA256: 4151f1570aefddd7932831c06e4f2b2e32006d4ecedd0f40eb862af312d11b63
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ParameterValue_1rect2_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8a468 */ cbz x2, #0x8a474;
    /* 0x8a46c */ ldr q0, [x4];
    /* 0x8a470 */ stur q0, [x2, #0xa8];
    return x0;
}

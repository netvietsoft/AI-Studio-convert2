// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8a2d0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ParameterValue_1integer2_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8a2d0 | Size: 16 bytes | SHA256: 402fbe41a1552239239a0f3e9fdf6ee03e43c02b52994e4702f67a21e3a6d208
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ParameterValue_1integer2_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8a2d0 */ cbz x2, #0x8a2dc;
    /* 0x8a2d4 */ ldr q0, [x4];
    /* 0x8a2d8 */ str q0, [x2, #0x60];
    return x0;
}

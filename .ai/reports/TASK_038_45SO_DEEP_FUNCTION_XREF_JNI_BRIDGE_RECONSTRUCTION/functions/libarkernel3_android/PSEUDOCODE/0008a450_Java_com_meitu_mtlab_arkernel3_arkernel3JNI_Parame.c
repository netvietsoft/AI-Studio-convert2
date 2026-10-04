// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8a450
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ParameterValue_1quat_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8a450 | Size: 16 bytes | SHA256: a1d93a67fef42479301e95e4d049a237ff971cd2c1d09b2499b5fbe2b6e37b86
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ParameterValue_1quat_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8a450 */ cbz x2, #0x8a45c;
    /* 0x8a454 */ ldr q0, [x4];
    /* 0x8a458 */ stur q0, [x2, #0x98];
    return x0;
}

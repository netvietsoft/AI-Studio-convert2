// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8a2b8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ParameterValue_1float2_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8a2b8 | Size: 16 bytes | SHA256: 00ab7f8ada7b0f87a07ccdc597291c585f4f26c5b60d591dc1c312e907d560be
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ParameterValue_1float2_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8a2b8 */ cbz x2, #0x8a2c4;
    /* 0x8a2bc */ ldr x8, [x4];
    /* 0x8a2c0 */ str x8, [x2, #0x58];
    return x0;
}

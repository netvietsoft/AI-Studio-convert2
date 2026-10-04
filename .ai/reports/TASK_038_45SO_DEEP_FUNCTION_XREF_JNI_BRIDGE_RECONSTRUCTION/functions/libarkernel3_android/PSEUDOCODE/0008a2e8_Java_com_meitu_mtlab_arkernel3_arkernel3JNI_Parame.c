// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8a2e8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ParameterValue_1float3_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8a2e8 | Size: 24 bytes | SHA256: d6a65e601bbe2eed750bf3609018c261b4005c03b3fc7f4f778dd85d82a6b5ab
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ParameterValue_1float3_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x8a2e8 */ cbz x2, #0x8a2fc;
    /* 0x8a2ec */ ldr w8, [x4, #8];
    /* 0x8a2f0 */ ldr x9, [x4];
    /* 0x8a2f4 */ str w8, [x2, #0x78];
    /* 0x8a2f8 */ str x9, [x2, #0x70];
    return x0;
}

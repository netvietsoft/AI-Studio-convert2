// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8a480
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ParameterValue_1colorSpace_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8a480 | Size: 12 bytes | SHA256: 4ea4dc654334a3e11799b25addc9ff76148c90980059b8251d220f65fd558188
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ParameterValue_1colorSpace_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x8a480 */ cbz x2, #0x8a488;
    /* 0x8a484 */ str w4, [x2, #0xb8];
    return x0;
}

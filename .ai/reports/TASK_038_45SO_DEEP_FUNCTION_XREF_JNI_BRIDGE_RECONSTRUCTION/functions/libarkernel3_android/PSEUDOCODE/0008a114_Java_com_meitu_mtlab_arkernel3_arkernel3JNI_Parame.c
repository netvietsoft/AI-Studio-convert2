// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8a114
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ParameterValue_1_1boolean_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8a114 | Size: 20 bytes | SHA256: 4507bcae94b880603c08a498c595eb38cb188ec4f09eeead212d735124163162
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ParameterValue_1_1boolean_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x8a114 */ cbz x2, #0x8a124;
    /* 0x8a118 */ tst w4, #0xff;
    /* 0x8a11c */ cset w8, ne;
    /* 0x8a120 */ strb w8, [x2, #0x18];
    return x0;
}

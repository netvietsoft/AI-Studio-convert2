// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8a074
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ParameterQuat_1w_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8a074 | Size: 12 bytes | SHA256: ae292f0659ad1bf265e021f0090abc712b2d4656416f14a064f71cfd987f3e2c
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ParameterQuat_1w_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x8a074 */ cbz x2, #0x8a07c;
    /* 0x8a078 */ str s0, [x2, #0xc];
    return x0;
}

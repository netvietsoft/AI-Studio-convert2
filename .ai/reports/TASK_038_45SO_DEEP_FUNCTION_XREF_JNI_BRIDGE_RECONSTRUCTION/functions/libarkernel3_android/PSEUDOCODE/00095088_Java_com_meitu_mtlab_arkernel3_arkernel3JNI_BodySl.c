// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x95088
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_BodySlimManualRectangle_1fHeight_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x95088 | Size: 12 bytes | SHA256: ae292f0659ad1bf265e021f0090abc712b2d4656416f14a064f71cfd987f3e2c
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_BodySlimManualRectangle_1fHeight_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x95088 */ cbz x2, #0x95090;
    /* 0x9508c */ str s0, [x2, #0xc];
    return x0;
}

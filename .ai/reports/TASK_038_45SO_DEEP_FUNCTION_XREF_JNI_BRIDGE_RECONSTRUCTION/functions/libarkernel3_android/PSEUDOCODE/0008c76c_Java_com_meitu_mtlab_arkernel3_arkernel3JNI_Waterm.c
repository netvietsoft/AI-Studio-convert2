// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8c76c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_WatermarkConfig_1allRotate_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8c76c | Size: 12 bytes | SHA256: c7e5db9b554490765f68a4318f51f123c26f56e82d0a2e6e5711b5992ea5ff86
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_WatermarkConfig_1allRotate_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x8c76c */ cbz x2, #0x8c774;
    /* 0x8c770 */ str s0, [x2, #0x14];
    return x0;
}

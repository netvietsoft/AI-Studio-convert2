// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8c7f4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_WatermarkConfig_1maxScale_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8c7f4 | Size: 12 bytes | SHA256: d208d15f45cc50c1178816c2a751fe5cbb943046b0a994607217f4fbfb31524e
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_WatermarkConfig_1maxScale_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x8c7f4 */ cbz x2, #0x8c7fc;
    /* 0x8c7f8 */ str s0, [x2, #0x3c];
    return x0;
}

// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8c374
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextPathConfig_1curveTextType_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8c374 | Size: 12 bytes | SHA256: 9730b3e25b66997189df65f3c5e7d10a7915beb8029f2019c466fe294321c737
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextPathConfig_1curveTextType_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x8c374 */ cbz x2, #0x8c37c;
    /* 0x8c378 */ str w4, [x2, #0x54];
    return x0;
}

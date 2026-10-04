// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x87f38
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ColorA_1g_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x87f38 | Size: 12 bytes | SHA256: 45808b20b2ea99977ace429b3691a217a6bc742fdd4021f15167b81793767b22
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ColorA_1g_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x87f38 */ cbz x2, #0x87f40;
    /* 0x87f3c */ str s0, [x2, #8];
    return x0;
}

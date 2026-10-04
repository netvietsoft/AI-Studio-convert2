// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x87d98
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_RectI_1left_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x87d98 | Size: 12 bytes | SHA256: 780f10fc249d2a3fd18c183d58c82fc84f84c01a6c132ef5938a13640d2f45ac
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_RectI_1left_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x87d98 */ cbz x2, #0x87da0;
    /* 0x87d9c */ str w4, [x2];
    return x0;
}

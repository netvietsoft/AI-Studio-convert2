// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x87d78
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_RectF_1width
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x87d78 | Size: 16 bytes | SHA256: e074aece0260678dbe4741e0c729067226d58e43a9e2a6d93adb2229fdcd2286
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_RectF_1width(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x87d78 */ ldr s0, [x2, #8];
    /* 0x87d7c */ ldr s1, [x2];
    /* 0x87d80 */ fsub s0, s0, s1;
    return x0;
}

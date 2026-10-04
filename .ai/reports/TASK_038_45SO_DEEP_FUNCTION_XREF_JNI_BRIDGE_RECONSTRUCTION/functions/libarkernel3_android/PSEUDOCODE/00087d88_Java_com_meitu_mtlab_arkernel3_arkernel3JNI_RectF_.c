// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x87d88
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_RectF_1height
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x87d88 | Size: 16 bytes | SHA256: b9bb91849835168861fbce04755623f685ffea2d317e78836a1f6d5d376d1f18
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_RectF_1height(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x87d88 */ ldr s0, [x2, #0xc];
    /* 0x87d8c */ ldr s1, [x2, #4];
    /* 0x87d90 */ fsub s0, s0, s1;
    return x0;
}

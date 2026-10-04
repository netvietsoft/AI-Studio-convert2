// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x98be8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VisualAllocator_1releaseTexture2D
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x98be8 | Size: 20 bytes | SHA256: cf244b9003f7edb21068e73ad95d32d8a78aeed3ba6643ecdbbd625b055a5bc2
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VisualAllocator_1releaseTexture2D(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x98be8 */ ldr x8, [x2];
    /* 0x98bec */ mov x0, x2;
    /* 0x98bf0 */ mov x1, x4;
    /* 0x98bf4 */ ldr x2, [x8, #0x10];
    /* 0x98bf8 */ br x2;
}

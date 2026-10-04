// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8c0a8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextBubbleBoxConfig_1padding_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8c0a8 | Size: 16 bytes | SHA256: 707260bc22f09e187ea1bf72900b807e39c39d7db60963a143c2419b3506fd4b
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextBubbleBoxConfig_1padding_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8c0a8 */ cbz x2, #0x8c0b4;
    /* 0x8c0ac */ ldr q0, [x4];
    /* 0x8c0b0 */ stur q0, [x2, #4];
    return x0;
}

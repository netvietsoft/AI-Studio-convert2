// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8c7c8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_WatermarkConfig_1rightBottom_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8c7c8 | Size: 16 bytes | SHA256: fcf31854c5dbc965a526f5d9992aac0f4f1afcc843f02e100edc6cd58046469a
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_WatermarkConfig_1rightBottom_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8c7c8 */ cbz x2, #0x8c7d4;
    /* 0x8c7cc */ ldr x8, [x4];
    /* 0x8c7d0 */ str x8, [x2, #0x30];
    return x0;
}

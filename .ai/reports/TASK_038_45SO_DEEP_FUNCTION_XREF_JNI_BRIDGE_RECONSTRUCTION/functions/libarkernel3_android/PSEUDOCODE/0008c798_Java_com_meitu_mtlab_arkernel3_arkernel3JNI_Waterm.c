// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8c798
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_WatermarkConfig_1leftBottom_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8c798 | Size: 16 bytes | SHA256: 44e05fc1aa11d4f9305491a1c61e0f8821f5c45fb83e7b5c3e1bf24b71bd7d84
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_WatermarkConfig_1leftBottom_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8c798 */ cbz x2, #0x8c7a4;
    /* 0x8c79c */ ldr x8, [x4];
    /* 0x8c7a0 */ str x8, [x2, #0x20];
    return x0;
}

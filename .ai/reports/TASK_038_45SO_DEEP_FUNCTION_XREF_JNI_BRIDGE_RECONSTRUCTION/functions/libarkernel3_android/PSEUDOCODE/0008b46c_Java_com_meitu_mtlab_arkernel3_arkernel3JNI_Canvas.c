// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8b46c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_CanvasProperty_1canvasDirectionType_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8b46c | Size: 12 bytes | SHA256: c6c6e04ac3da24266422e0b56d62a3f11b52feef11443f697919b1493c36f228
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_CanvasProperty_1canvasDirectionType_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x8b46c */ cbz x2, #0x8b474;
    /* 0x8b470 */ str w4, [x2, #0x2c];
    return x0;
}

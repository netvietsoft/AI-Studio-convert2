// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8abc4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TimeLineDataInterface_1intervalMs_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8abc4 | Size: 16 bytes | SHA256: b0693c488908fee1632559eab42de73d8f992af7af887cc7246b2a6c84cc00d6
// Callers: 0 | Callees: 0 | Imports: 0


jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TimeLineDataInterface_1intervalMs_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8abc4 */ cbz x2, #0x8abd0;
    /* 0x8abc8 */ sxtw x8, w4;
    /* 0x8abcc */ str x8, [x2, #8];
    return x0;
}

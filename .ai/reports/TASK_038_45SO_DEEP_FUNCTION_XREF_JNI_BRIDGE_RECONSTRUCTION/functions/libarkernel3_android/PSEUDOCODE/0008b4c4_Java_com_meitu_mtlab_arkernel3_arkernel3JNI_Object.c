// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8b4c4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ObjectTrackingData_1bounds_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8b4c4 | Size: 16 bytes | SHA256: 8550e24e56513afe40ad5c3d31728ef9dff9b6572d7b599163e4b85c6ad04ad1
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ObjectTrackingData_1bounds_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8b4c4 */ cbz x2, #0x8b4d0;
    /* 0x8b4c8 */ ldr q0, [x4];
    /* 0x8b4cc */ stur q0, [x2, #0xc];
    return x0;
}

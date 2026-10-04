// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x92a00
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerFaceTrackingInteraction_1setFaceTrackingUseMouth
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x92a00 | Size: 16 bytes | SHA256: 53f60358ff0bc217be62e8d5351efe39bd498ac1e51c013d0903291f16db32b1
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar328LayerFaceTrackingInteraction23setFaceTrackingUseMouthEb

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerFaceTrackingInteraction_1setFaceTrackingUseMouth(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x92a00 */ tst w4, #0xff;
    /* 0x92a04 */ mov x0, x2;
    /* 0x92a08 */ cset w1, ne;
    /* 0x92a0c */ b #0xa3070;
}

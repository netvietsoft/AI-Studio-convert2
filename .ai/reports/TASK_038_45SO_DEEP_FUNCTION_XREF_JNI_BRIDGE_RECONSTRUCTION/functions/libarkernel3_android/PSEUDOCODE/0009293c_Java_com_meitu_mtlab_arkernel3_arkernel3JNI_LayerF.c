// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x9293c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerFaceTrackingInteraction_1setEnableFaceTracking
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x9293c | Size: 16 bytes | SHA256: 5383f60ef955d4aebeb6f9b9b89b4ca5246afcb6f5407d0cebe3b47ba7399d81
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar328LayerFaceTrackingInteraction21setEnableFaceTrackingEb

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerFaceTrackingInteraction_1setEnableFaceTracking(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x9293c */ tst w4, #0xff;
    /* 0x92940 */ mov x0, x2;
    /* 0x92944 */ cset w1, ne;
    /* 0x92948 */ b #0xa2fd0;
}

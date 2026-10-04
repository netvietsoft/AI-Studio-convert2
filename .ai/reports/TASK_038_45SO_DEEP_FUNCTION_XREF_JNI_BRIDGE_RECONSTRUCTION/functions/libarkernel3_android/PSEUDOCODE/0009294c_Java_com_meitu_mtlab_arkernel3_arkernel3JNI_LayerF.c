// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x9294c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerFaceTrackingInteraction_1getEnableFaceTracking
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x9294c | Size: 28 bytes | SHA256: 4bb61fa2c02251c9369ac25515b5caa92e786657eccd3c560acc174806cfee48
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar328LayerFaceTrackingInteraction21getEnableFaceTrackingEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerFaceTrackingInteraction_1getEnableFaceTracking(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x9294c */ stp x29, x30, [sp, #-0x10]!;
    /* 0x92950 */ mov x29, sp;
    /* 0x92954 */ mov x0, x2;
    _ZN8mtlabar328LayerFaceTrackingInteraction21getEnableFaceTrackingEv();
    /* 0x9295c */ and w0, w0, #1;
    /* 0x92960 */ ldp x29, x30, [sp], #0x10;
    return x0;
}

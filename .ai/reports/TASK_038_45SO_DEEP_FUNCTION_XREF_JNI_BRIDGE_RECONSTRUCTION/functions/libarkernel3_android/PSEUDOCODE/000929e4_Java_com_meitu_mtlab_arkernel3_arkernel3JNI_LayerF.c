// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x929e4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerFaceTrackingInteraction_1getFaceTrackingUseMouth
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x929e4 | Size: 28 bytes | SHA256: b157420aa22334b1ce94072324a75c5b7671e59b942059f5458b2ad68c08d691
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar328LayerFaceTrackingInteraction23getFaceTrackingUseMouthEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerFaceTrackingInteraction_1getFaceTrackingUseMouth(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x929e4 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x929e8 */ mov x29, sp;
    /* 0x929ec */ mov x0, x2;
    _ZN8mtlabar328LayerFaceTrackingInteraction23getFaceTrackingUseMouthEv();
    /* 0x929f4 */ and w0, w0, #1;
    /* 0x929f8 */ ldp x29, x30, [sp], #0x10;
    return x0;
}

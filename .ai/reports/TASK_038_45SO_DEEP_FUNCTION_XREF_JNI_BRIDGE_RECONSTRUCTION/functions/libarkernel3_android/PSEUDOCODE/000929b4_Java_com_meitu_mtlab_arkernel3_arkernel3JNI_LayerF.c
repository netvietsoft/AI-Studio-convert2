// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x929b4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerFaceTrackingInteraction_1getFaceTrackingNeedHidden
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x929b4 | Size: 28 bytes | SHA256: 2ae88a0a3780d6f0f3e5e6fe2598e33db480beea09d28eb367fe33e8f7ce06a7
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar328LayerFaceTrackingInteraction25getFaceTrackingNeedHiddenEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerFaceTrackingInteraction_1getFaceTrackingNeedHidden(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x929b4 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x929b8 */ mov x29, sp;
    /* 0x929bc */ mov x0, x2;
    _ZN8mtlabar328LayerFaceTrackingInteraction25getFaceTrackingNeedHiddenEv();
    /* 0x929c4 */ and w0, w0, #1;
    /* 0x929c8 */ ldp x29, x30, [sp], #0x10;
    return x0;
}

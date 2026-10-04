// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x92f08
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerAnimationInteraction_1getStopLastFrame
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x92f08 | Size: 28 bytes | SHA256: 9ef4e73165a93664a97ad83e0f9d33f82958d04ff781a5f8682f09215829d0d7
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar325LayerAnimationInteraction16getStopLastFrameEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerAnimationInteraction_1getStopLastFrame(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x92f08 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x92f0c */ mov x29, sp;
    /* 0x92f10 */ mov x0, x2;
    _ZN8mtlabar325LayerAnimationInteraction16getStopLastFrameEv();
    /* 0x92f18 */ and w0, w0, #1;
    /* 0x92f1c */ ldp x29, x30, [sp], #0x10;
    return x0;
}

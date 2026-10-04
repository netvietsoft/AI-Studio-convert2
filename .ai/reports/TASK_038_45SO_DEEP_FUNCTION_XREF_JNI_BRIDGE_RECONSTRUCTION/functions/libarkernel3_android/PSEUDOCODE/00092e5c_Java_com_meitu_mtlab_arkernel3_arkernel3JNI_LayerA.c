// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x92e5c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerAnimationInteraction_1isFullScreenAnimation
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x92e5c | Size: 28 bytes | SHA256: dd04a2967f5324e10073fc4758ae1d3216f5fd26a45bfe375fbb36aa14638a8f
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar325LayerAnimationInteraction21isFullScreenAnimationEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerAnimationInteraction_1isFullScreenAnimation(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x92e5c */ stp x29, x30, [sp, #-0x10]!;
    /* 0x92e60 */ mov x29, sp;
    /* 0x92e64 */ mov x0, x2;
    _ZN8mtlabar325LayerAnimationInteraction21isFullScreenAnimationEv();
    /* 0x92e6c */ and w0, w0, #1;
    /* 0x92e70 */ ldp x29, x30, [sp], #0x10;
    return x0;
}

// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x92e88
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerAnimationInteraction_1getShowStaticFrame
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x92e88 | Size: 28 bytes | SHA256: 37b906fd3640ab64961cca81d811480ce516bd3fec670d1196c2bd99a54c022e
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar325LayerAnimationInteraction18getShowStaticFrameEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerAnimationInteraction_1getShowStaticFrame(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x92e88 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x92e8c */ mov x29, sp;
    /* 0x92e90 */ mov x0, x2;
    _ZN8mtlabar325LayerAnimationInteraction18getShowStaticFrameEv();
    /* 0x92e98 */ and w0, w0, #1;
    /* 0x92e9c */ ldp x29, x30, [sp], #0x10;
    return x0;
}

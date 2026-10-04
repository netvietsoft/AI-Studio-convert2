// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x92bb4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerAnimationInteraction_1valid
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x92bb4 | Size: 28 bytes | SHA256: 1ded5aa5e7559a509324a0fe461cef1bc59c5cd0dbf093759ff327ffbbb7ef1c
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar325LayerAnimationInteraction5validEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerAnimationInteraction_1valid(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x92bb4 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x92bb8 */ mov x29, sp;
    /* 0x92bbc */ mov x0, x2;
    _ZN8mtlabar325LayerAnimationInteraction5validEv();
    /* 0x92bc4 */ and w0, w0, #1;
    /* 0x92bc8 */ ldp x29, x30, [sp], #0x10;
    return x0;
}

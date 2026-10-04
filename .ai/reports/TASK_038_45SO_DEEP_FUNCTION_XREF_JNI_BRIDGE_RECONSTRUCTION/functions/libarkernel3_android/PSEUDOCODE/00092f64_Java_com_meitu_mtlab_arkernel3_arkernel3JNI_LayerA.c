// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x92f64
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerAnimationInteraction_1getAdvanceAnimation
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x92f64 | Size: 28 bytes | SHA256: 7a3e0f24f330e8800ba3812280beb2e5d265c3bcab58fb2778e4fb67297992a9
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar325LayerAnimationInteraction19getAdvanceAnimationEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerAnimationInteraction_1getAdvanceAnimation(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x92f64 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x92f68 */ mov x29, sp;
    /* 0x92f6c */ mov x0, x2;
    _ZN8mtlabar325LayerAnimationInteraction19getAdvanceAnimationEv();
    /* 0x92f74 */ and w0, w0, #1;
    /* 0x92f78 */ ldp x29, x30, [sp], #0x10;
    return x0;
}

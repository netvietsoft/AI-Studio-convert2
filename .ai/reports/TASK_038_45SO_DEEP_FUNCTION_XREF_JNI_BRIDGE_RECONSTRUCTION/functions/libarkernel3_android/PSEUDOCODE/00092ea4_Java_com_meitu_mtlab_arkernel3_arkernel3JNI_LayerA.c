// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x92ea4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerAnimationInteraction_1isHighlightTextAnimation
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x92ea4 | Size: 28 bytes | SHA256: 7a3e0f24f330e8800ba3812280beb2e5d265c3bcab58fb2778e4fb67297992a9
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar325LayerAnimationInteraction24isHighlightTextAnimationEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerAnimationInteraction_1isHighlightTextAnimation(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x92ea4 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x92ea8 */ mov x29, sp;
    /* 0x92eac */ mov x0, x2;
    _ZN8mtlabar325LayerAnimationInteraction24isHighlightTextAnimationEv();
    /* 0x92eb4 */ and w0, w0, #1;
    /* 0x92eb8 */ ldp x29, x30, [sp], #0x10;
    return x0;
}

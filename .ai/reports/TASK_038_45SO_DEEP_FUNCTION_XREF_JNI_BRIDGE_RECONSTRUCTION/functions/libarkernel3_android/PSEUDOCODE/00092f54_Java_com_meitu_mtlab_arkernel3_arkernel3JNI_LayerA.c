// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x92f54
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerAnimationInteraction_1setAdvanceAnimation
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x92f54 | Size: 16 bytes | SHA256: 4a301386d6a9f32f28b5714c257c24f77262cf7b05897d799dd831498e3ea5c7
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar325LayerAnimationInteraction19setAdvanceAnimationEb

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerAnimationInteraction_1setAdvanceAnimation(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x92f54 */ tst w4, #0xff;
    /* 0x92f58 */ mov x0, x2;
    /* 0x92f5c */ cset w1, ne;
    /* 0x92f60 */ b #0xa33e0;
}

// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x92e78
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerAnimationInteraction_1setShowStaticFrame
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x92e78 | Size: 16 bytes | SHA256: 546663f7008db77a49ccde7eced5786efbc613bcc8af8348561ecd23a2b0b397
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar325LayerAnimationInteraction18setShowStaticFrameEb

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerAnimationInteraction_1setShowStaticFrame(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x92e78 */ tst w4, #0xff;
    /* 0x92e7c */ mov x0, x2;
    /* 0x92e80 */ cset w1, ne;
    /* 0x92e84 */ b #0xa3310;
}

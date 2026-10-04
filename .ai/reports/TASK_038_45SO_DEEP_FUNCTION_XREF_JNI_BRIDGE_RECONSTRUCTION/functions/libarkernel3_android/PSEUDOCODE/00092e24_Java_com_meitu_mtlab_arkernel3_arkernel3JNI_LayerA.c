// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x92e24
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerAnimationInteraction_1setLoopState
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x92e24 | Size: 16 bytes | SHA256: c8f5b86cb6f4b08a07991d0ebbab0b39db9fe4cc1d8eb037cf1734fd247d8729
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar325LayerAnimationInteraction12setLoopStateEb

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerAnimationInteraction_1setLoopState(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x92e24 */ tst w4, #0xff;
    /* 0x92e28 */ mov x0, x2;
    /* 0x92e2c */ cset w1, ne;
    /* 0x92e30 */ b #0xa32d0;
}

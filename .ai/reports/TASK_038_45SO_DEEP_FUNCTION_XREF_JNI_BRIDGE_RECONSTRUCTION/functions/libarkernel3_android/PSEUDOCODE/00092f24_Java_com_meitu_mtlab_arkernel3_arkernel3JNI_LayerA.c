// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x92f24
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerAnimationInteraction_1setStopLastFrame
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x92f24 | Size: 16 bytes | SHA256: d810fed5af6409684db7d9c8f14d85bdc11a35fe32d44e9681ecd0ac41d60cfd
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar325LayerAnimationInteraction16setStopLastFrameEb

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerAnimationInteraction_1setStopLastFrame(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x92f24 */ tst w4, #0xff;
    /* 0x92f28 */ mov x0, x2;
    /* 0x92f2c */ cset w1, ne;
    /* 0x92f30 */ b #0xa33a0;
}

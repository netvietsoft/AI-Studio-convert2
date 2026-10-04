// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8e280
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SelectionAnimationInterface_1setDisplayInASRTime
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8e280 | Size: 16 bytes | SHA256: 6e4d77a0414b23bd5c5b84f50d6bde8d5269175918ed76a73350e322f9b29eb3
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar327SelectionAnimationInterface19setDisplayInASRTimeEb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SelectionAnimationInterface_1setDisplayInASRTime(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8e280 */ tst w4, #0xff;
    /* 0x8e284 */ mov x0, x2;
    /* 0x8e288 */ cset w1, ne;
    /* 0x8e28c */ b #0xa15c0;
}

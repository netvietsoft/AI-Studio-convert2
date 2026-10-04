// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x92cf8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerAnimationInteraction_1disableEndTimestamp
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x92cf8 | Size: 16 bytes | SHA256: 654888097a138fcd83c7e7ec768a9cdaaad567c992a29f78689c3d8f3389b91c
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar325LayerAnimationInteraction19disableEndTimestampEb

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerAnimationInteraction_1disableEndTimestamp(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x92cf8 */ tst w4, #0xff;
    /* 0x92cfc */ mov x0, x2;
    /* 0x92d00 */ cset w1, ne;
    /* 0x92d04 */ b #0xa3250;
}

// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x93fc0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireFaceDataAdditionEmotion
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x93fc0 | Size: 28 bytes | SHA256: 116fed7b68d08d119142fae3103600d5deeded099331b2347876cec41ef0ca73
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire30requireFaceDataAdditionEmotionEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireFaceDataAdditionEmotion(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x93fc0 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x93fc4 */ mov x29, sp;
    /* 0x93fc8 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire30requireFaceDataAdditionEmotionEv();
    /* 0x93fd0 */ and w0, w0, #1;
    /* 0x93fd4 */ ldp x29, x30, [sp], #0x10;
    return x0;
}

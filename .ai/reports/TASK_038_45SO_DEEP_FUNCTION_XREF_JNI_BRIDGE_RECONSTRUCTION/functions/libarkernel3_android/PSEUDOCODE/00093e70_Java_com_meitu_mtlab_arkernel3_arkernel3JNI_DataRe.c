// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x93e70
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireFoodData
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x93e70 | Size: 28 bytes | SHA256: 82eaec9644bf604a3883dcc46f9eb835b788d448d2b09ee7a1d64d1fff6daed7
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire15requireFoodDataEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireFoodData(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x93e70 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x93e74 */ mov x29, sp;
    /* 0x93e78 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire15requireFoodDataEv();
    /* 0x93e80 */ and w0, w0, #1;
    /* 0x93e84 */ ldp x29, x30, [sp], #0x10;
    return x0;
}

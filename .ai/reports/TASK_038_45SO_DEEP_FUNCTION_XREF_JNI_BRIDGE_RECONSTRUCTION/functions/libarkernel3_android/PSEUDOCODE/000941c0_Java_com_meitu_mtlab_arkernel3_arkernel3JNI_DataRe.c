// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x941c0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireNailsData
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x941c0 | Size: 28 bytes | SHA256: 8cd1f365b90da9bf398a445788d6bf043ae4af493d77590cf2a14d8aacf69112
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire16requireNailsDataEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireNailsData(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x941c0 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x941c4 */ mov x29, sp;
    /* 0x941c8 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire16requireNailsDataEv();
    /* 0x941d0 */ and w0, w0, #1;
    /* 0x941d4 */ ldp x29, x30, [sp], #0x10;
    return x0;
}

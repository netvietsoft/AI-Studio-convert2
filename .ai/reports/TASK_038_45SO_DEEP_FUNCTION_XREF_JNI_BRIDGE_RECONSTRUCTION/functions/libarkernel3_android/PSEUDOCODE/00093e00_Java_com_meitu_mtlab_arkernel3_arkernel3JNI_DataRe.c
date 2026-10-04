// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x93e00
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireSourceColorImage
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x93e00 | Size: 28 bytes | SHA256: a4ca53727c50b67d81e60a790fdf730aaf9246eaac600e88b37e8131ca56ee95
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire23requireSourceColorImageEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireSourceColorImage(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x93e00 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x93e04 */ mov x29, sp;
    /* 0x93e08 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire23requireSourceColorImageEv();
    /* 0x93e10 */ and w0, w0, #1;
    /* 0x93e14 */ ldp x29, x30, [sp], #0x10;
    return x0;
}

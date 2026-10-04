// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x9455c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireBodyAdditionContour
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x9455c | Size: 28 bytes | SHA256: da7ffa09a4584f10693b49f849b10472c8d690b436377ac8e4194e902dc27c7b
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire26requireBodyAdditionContourEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireBodyAdditionContour(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x9455c */ stp x29, x30, [sp, #-0x10]!;
    /* 0x94560 */ mov x29, sp;
    /* 0x94564 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire26requireBodyAdditionContourEv();
    /* 0x9456c */ and w0, w0, #1;
    /* 0x94570 */ ldp x29, x30, [sp], #0x10;
    return x0;
}

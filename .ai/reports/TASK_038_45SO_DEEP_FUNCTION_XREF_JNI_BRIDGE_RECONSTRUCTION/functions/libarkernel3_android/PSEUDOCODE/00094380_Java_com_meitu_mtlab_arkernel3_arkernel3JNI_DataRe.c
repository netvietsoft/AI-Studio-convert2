// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x94380
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireNevusMask
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x94380 | Size: 28 bytes | SHA256: f72b6d671bfe44aeb8f2c9856bd2140f54c3b938d03110be9e4d221fd9d0b6d3
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire16requireNevusMaskEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireNevusMask(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x94380 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x94384 */ mov x29, sp;
    /* 0x94388 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire16requireNevusMaskEv();
    /* 0x94390 */ and w0, w0, #1;
    /* 0x94394 */ ldp x29, x30, [sp], #0x10;
    return x0;
}

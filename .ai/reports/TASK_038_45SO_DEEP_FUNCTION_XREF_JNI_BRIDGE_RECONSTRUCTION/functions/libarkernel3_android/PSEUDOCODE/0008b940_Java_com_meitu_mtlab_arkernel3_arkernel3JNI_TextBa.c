// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8b940
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextBackgroundColorConfiguration_1getColorWork
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8b940 | Size: 28 bytes | SHA256: 0028d48c9fd73dafe0d90a1e8ed9efa2d8f0e1608e04ff8571fe2d3f61b29237
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar332TextBackgroundColorConfiguration12getColorWorkEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextBackgroundColorConfiguration_1getColorWork(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x8b940 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8b944 */ mov x29, sp;
    /* 0x8b948 */ mov x0, x2;
    _ZNK8mtlabar332TextBackgroundColorConfiguration12getColorWorkEv();
    /* 0x8b950 */ and w0, w0, #1;
    /* 0x8b954 */ ldp x29, x30, [sp], #0x10;
    return x0;
}

// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8e030
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SelectionHighlightInterface_1getStrikeThrough
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8e030 | Size: 28 bytes | SHA256: 8de870e93d06e6872de0a51d6cb6e1d46606eb3968a1d1d4fc52145ae38f4f8e
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar327SelectionHighlightInterface16getStrikeThroughEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SelectionHighlightInterface_1getStrikeThrough(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x8e030 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8e034 */ mov x29, sp;
    /* 0x8e038 */ mov x0, x2;
    _ZNK8mtlabar327SelectionHighlightInterface16getStrikeThroughEv();
    /* 0x8e040 */ and w0, w0, #1;
    /* 0x8e044 */ ldp x29, x30, [sp], #0x10;
    return x0;
}

// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8e004
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SelectionHighlightInterface_1getUnderline
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8e004 | Size: 28 bytes | SHA256: 6c536cde86cfdd2ab8f819e9c4a5023587684fca0055cb35737bc70de92b31d6
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar327SelectionHighlightInterface12getUnderlineEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SelectionHighlightInterface_1getUnderline(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x8e004 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8e008 */ mov x29, sp;
    /* 0x8e00c */ mov x0, x2;
    _ZNK8mtlabar327SelectionHighlightInterface12getUnderlineEv();
    /* 0x8e014 */ and w0, w0, #1;
    /* 0x8e018 */ ldp x29, x30, [sp], #0x10;
    return x0;
}

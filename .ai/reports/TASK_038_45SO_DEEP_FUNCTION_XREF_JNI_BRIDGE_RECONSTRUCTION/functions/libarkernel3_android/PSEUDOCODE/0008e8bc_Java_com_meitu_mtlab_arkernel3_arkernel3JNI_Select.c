// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8e8bc
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SelectionNoteInterface_1getCustomizeDetail
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8e8bc | Size: 28 bytes | SHA256: dcfaac74b29141450bf85bcdc4e85c14ba4799c1d091468123d70210118693ec
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar322SelectionNoteInterface18getCustomizeDetailEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SelectionNoteInterface_1getCustomizeDetail(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x8e8bc */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8e8c0 */ mov x29, sp;
    /* 0x8e8c4 */ mov x0, x2;
    _ZNK8mtlabar322SelectionNoteInterface18getCustomizeDetailEv();
    /* 0x8e8cc */ and w0, w0, #1;
    /* 0x8e8d0 */ ldp x29, x30, [sp], #0x10;
    return x0;
}

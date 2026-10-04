// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8dd3c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SelectionHighlightInterface_1getHideNonHighlightUnderline
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8dd3c | Size: 28 bytes | SHA256: 2b62396d63bd0eaebf007127a988b95df5fac6b28b8820e5e26ee521f8b6e841
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar327SelectionHighlightInterface28getHideNonHighlightUnderlineEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SelectionHighlightInterface_1getHideNonHighlightUnderline(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x8dd3c */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8dd40 */ mov x29, sp;
    /* 0x8dd44 */ mov x0, x2;
    _ZNK8mtlabar327SelectionHighlightInterface28getHideNonHighlightUnderlineEv();
    /* 0x8dd4c */ and w0, w0, #1;
    /* 0x8dd50 */ ldp x29, x30, [sp], #0x10;
    return x0;
}

// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8decc
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SelectionHighlightInterface_1getCustomizeStyle
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8decc | Size: 28 bytes | SHA256: f81a35328a9eb853413427da3c872d1c5b0bf34171069991f69e779e670a6e71
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar327SelectionHighlightInterface17getCustomizeStyleEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SelectionHighlightInterface_1getCustomizeStyle(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x8decc */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8ded0 */ mov x29, sp;
    /* 0x8ded4 */ mov x0, x2;
    _ZNK8mtlabar327SelectionHighlightInterface17getCustomizeStyleEv();
    /* 0x8dedc */ and w0, w0, #1;
    /* 0x8dee0 */ ldp x29, x30, [sp], #0x10;
    return x0;
}

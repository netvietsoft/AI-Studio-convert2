// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8dfd8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SelectionHighlightInterface_1getItalic
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8dfd8 | Size: 28 bytes | SHA256: 2cb385312cf2be58a0bc6684f59ef674a220778e225f83356db3b95c53a38065
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar327SelectionHighlightInterface9getItalicEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SelectionHighlightInterface_1getItalic(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x8dfd8 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8dfdc */ mov x29, sp;
    /* 0x8dfe0 */ mov x0, x2;
    _ZNK8mtlabar327SelectionHighlightInterface9getItalicEv();
    /* 0x8dfe8 */ and w0, w0, #1;
    /* 0x8dfec */ ldp x29, x30, [sp], #0x10;
    return x0;
}

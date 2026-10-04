// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8dfac
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SelectionHighlightInterface_1getBold
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8dfac | Size: 28 bytes | SHA256: fa5e521d408d1d7e72aacec1c7dee4d6b027fa38ace3b0923f307ec5ad07d5c9
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar327SelectionHighlightInterface7getBoldEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SelectionHighlightInterface_1getBold(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x8dfac */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8dfb0 */ mov x29, sp;
    /* 0x8dfb4 */ mov x0, x2;
    _ZNK8mtlabar327SelectionHighlightInterface7getBoldEv();
    /* 0x8dfbc */ and w0, w0, #1;
    /* 0x8dfc0 */ ldp x29, x30, [sp], #0x10;
    return x0;
}

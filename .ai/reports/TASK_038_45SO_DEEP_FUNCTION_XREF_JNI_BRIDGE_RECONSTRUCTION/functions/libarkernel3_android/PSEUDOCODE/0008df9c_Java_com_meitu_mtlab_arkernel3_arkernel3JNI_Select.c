// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8df9c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SelectionHighlightInterface_1setBold
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8df9c | Size: 16 bytes | SHA256: c43dbb3f158fbe74c59606edbcf629b8e045ed167a9cb99455a2677860a5f17d
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar327SelectionHighlightInterface7setBoldEb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SelectionHighlightInterface_1setBold(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8df9c */ tst w4, #0xff;
    /* 0x8dfa0 */ mov x0, x2;
    /* 0x8dfa4 */ cset w1, ne;
    /* 0x8dfa8 */ b #0xa13d0;
}

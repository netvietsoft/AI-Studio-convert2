// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8dfc8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SelectionHighlightInterface_1setItalic
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8dfc8 | Size: 16 bytes | SHA256: 213c96b296dde65b13c21ef2742fdc46e77d8bf45137b08a369bb00661e387b3
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar327SelectionHighlightInterface9setItalicEb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SelectionHighlightInterface_1setItalic(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8dfc8 */ tst w4, #0xff;
    /* 0x8dfcc */ mov x0, x2;
    /* 0x8dfd0 */ cset w1, ne;
    /* 0x8dfd4 */ b #0xa13f0;
}

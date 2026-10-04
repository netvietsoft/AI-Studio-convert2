// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8dff4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SelectionHighlightInterface_1setUnderline
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8dff4 | Size: 16 bytes | SHA256: 3952cb24228ab87a4b762cc0258723880b1fe0c56958268558613eaf512e5023
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar327SelectionHighlightInterface12setUnderlineEb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SelectionHighlightInterface_1setUnderline(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8dff4 */ tst w4, #0xff;
    /* 0x8dff8 */ mov x0, x2;
    /* 0x8dffc */ cset w1, ne;
    /* 0x8e000 */ b #0xa1410;
}

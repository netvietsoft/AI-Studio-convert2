// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8e8ac
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SelectionNoteInterface_1setCustomizeDetail
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8e8ac | Size: 16 bytes | SHA256: f553edaec61b2c12cea1c3ff3f83a4f97b1d05ac29f10b82cbfd6b7bda0f6ba7
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar322SelectionNoteInterface18setCustomizeDetailEb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SelectionNoteInterface_1setCustomizeDetail(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8e8ac */ tst w4, #0xff;
    /* 0x8e8b0 */ mov x0, x2;
    /* 0x8e8b4 */ cset w1, ne;
    /* 0x8e8b8 */ b #0xa1960;
}

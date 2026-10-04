// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8fed4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_CharBackgroundInterface_1setEditable
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8fed4 | Size: 16 bytes | SHA256: 09f967d2e56a17e0d8d1979f73bee2250c4f15f8f027d8fc077721670c428d0e
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323CharBackgroundInterface11setEditableEb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_CharBackgroundInterface_1setEditable(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8fed4 */ tst w4, #0xff;
    /* 0x8fed8 */ mov x0, x2;
    /* 0x8fedc */ cset w1, ne;
    /* 0x8fee0 */ b #0xa25c0;
}

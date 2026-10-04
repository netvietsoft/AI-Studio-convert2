// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8b8a4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextBackgroundColorConfiguration_1setEditable
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8b8a4 | Size: 16 bytes | SHA256: 64fea3f0f7de611141edae0123fd1c8d228c4734a8276dcf9c0a8936730cf233
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar332TextBackgroundColorConfiguration11setEditableEb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextBackgroundColorConfiguration_1setEditable(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8b8a4 */ tst w4, #0xff;
    /* 0x8b8a8 */ mov x0, x2;
    /* 0x8b8ac */ cset w1, ne;
    /* 0x8b8b0 */ b #0xa0980;
}

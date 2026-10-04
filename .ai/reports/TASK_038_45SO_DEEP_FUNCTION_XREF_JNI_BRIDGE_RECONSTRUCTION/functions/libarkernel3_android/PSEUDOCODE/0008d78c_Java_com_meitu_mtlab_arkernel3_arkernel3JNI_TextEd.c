// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8d78c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextEditableConfiguration_1setLineSpacingEditable
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8d78c | Size: 16 bytes | SHA256: 9f109eeeeb17d6a475a15b1abc774e520c7be1ba868562407d412cb088b90447
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar325TextEditableConfiguration22setLineSpacingEditableEb

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextEditableConfiguration_1setLineSpacingEditable(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8d78c */ tst w4, #0xff;
    /* 0x8d790 */ mov x0, x2;
    /* 0x8d794 */ cset w1, ne;
    /* 0x8d798 */ b #0xa0f60;
}

// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8d760
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextEditableConfiguration_1setSpacingEditable
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8d760 | Size: 16 bytes | SHA256: 30a051b5584cfc6f84ceb0c7a25bc90a43022998583d547883c9bde822c0c14a
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar325TextEditableConfiguration18setSpacingEditableEb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextEditableConfiguration_1setSpacingEditable(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8d760 */ tst w4, #0xff;
    /* 0x8d764 */ mov x0, x2;
    /* 0x8d768 */ cset w1, ne;
    /* 0x8d76c */ b #0xa0f40;
}

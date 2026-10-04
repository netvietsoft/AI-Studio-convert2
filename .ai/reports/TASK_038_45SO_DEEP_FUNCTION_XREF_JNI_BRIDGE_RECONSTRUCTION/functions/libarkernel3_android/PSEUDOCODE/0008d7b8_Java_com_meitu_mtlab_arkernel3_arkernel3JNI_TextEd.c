// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8d7b8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextEditableConfiguration_1setHorizontalEditable
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8d7b8 | Size: 16 bytes | SHA256: 18647482438658388d7d63084a8f48142a90f4ed92a68bff9eefeb24813bc846
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar325TextEditableConfiguration21setHorizontalEditableEb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextEditableConfiguration_1setHorizontalEditable(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8d7b8 */ tst w4, #0xff;
    /* 0x8d7bc */ mov x0, x2;
    /* 0x8d7c0 */ cset w1, ne;
    /* 0x8d7c4 */ b #0xa0f80;
}

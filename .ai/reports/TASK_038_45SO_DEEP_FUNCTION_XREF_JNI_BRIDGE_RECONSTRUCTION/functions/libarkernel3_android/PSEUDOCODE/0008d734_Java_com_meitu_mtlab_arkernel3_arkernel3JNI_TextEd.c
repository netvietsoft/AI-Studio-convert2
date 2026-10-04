// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8d734
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextEditableConfiguration_1setEditable
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8d734 | Size: 16 bytes | SHA256: c1be7874993675568da4e8d8140f58a830b8c8453267995cf9c465d4ca1b4862
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar325TextEditableConfiguration11setEditableEb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextEditableConfiguration_1setEditable(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8d734 */ tst w4, #0xff;
    /* 0x8d738 */ mov x0, x2;
    /* 0x8d73c */ cset w1, ne;
    /* 0x8d740 */ b #0xa0f20;
}

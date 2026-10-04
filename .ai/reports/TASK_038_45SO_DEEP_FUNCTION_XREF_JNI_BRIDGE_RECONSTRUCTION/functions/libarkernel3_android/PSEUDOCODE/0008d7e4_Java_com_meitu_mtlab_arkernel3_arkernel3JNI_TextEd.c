// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8d7e4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextEditableConfiguration_1setVerticalEditable
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8d7e4 | Size: 16 bytes | SHA256: 9185c1c45730555f2fc814fa2982550c8dc01e21a0655738be6a97e77f605421
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar325TextEditableConfiguration19setVerticalEditableEb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextEditableConfiguration_1setVerticalEditable(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8d7e4 */ tst w4, #0xff;
    /* 0x8d7e8 */ mov x0, x2;
    /* 0x8d7ec */ cset w1, ne;
    /* 0x8d7f0 */ b #0xa0fa0;
}

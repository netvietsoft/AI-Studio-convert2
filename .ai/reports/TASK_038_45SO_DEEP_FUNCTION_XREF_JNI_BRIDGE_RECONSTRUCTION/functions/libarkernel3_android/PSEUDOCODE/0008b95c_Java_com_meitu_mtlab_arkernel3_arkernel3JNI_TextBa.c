// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8b95c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextBackgroundColorConfiguration_1setColorWork
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8b95c | Size: 16 bytes | SHA256: 5d6f915abd29d5687d19ffcce7c7cc0bf5d7a475f97c5f017c17c6125b6d48be
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar332TextBackgroundColorConfiguration12setColorWorkEb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextBackgroundColorConfiguration_1setColorWork(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8b95c */ tst w4, #0xff;
    /* 0x8b960 */ mov x0, x2;
    /* 0x8b964 */ cset w1, ne;
    /* 0x8b968 */ b #0xa09c0;
}

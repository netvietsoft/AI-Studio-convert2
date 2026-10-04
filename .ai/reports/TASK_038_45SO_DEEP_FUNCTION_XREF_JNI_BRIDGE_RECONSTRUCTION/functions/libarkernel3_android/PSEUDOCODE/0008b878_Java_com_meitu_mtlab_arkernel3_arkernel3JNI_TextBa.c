// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8b878
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextBackgroundColorConfiguration_1setEnable
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8b878 | Size: 16 bytes | SHA256: 7e86eba5803177e656e5e0e1979e3583fe15d48d8630743320c81bce3418484d
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar332TextBackgroundColorConfiguration9setEnableEb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextBackgroundColorConfiguration_1setEnable(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8b878 */ tst w4, #0xff;
    /* 0x8b87c */ mov x0, x2;
    /* 0x8b880 */ cset w1, ne;
    /* 0x8b884 */ b #0xa0960;
}

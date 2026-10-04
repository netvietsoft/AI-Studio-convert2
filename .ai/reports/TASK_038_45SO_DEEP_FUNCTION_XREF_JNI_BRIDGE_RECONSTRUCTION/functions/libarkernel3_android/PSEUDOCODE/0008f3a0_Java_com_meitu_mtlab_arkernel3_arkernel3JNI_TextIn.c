// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8f3a0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextInactiveTextConfigInterface_1setEnable
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8f3a0 | Size: 16 bytes | SHA256: 546556b55a9d67efcc363c193fd3b35a46cde562de6550e0069bcf41dbdef8ab
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar331TextInactiveTextConfigInterface9setEnableEb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextInactiveTextConfigInterface_1setEnable(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8f3a0 */ tst w4, #0xff;
    /* 0x8f3a4 */ mov x0, x2;
    /* 0x8f3a8 */ cset w1, ne;
    /* 0x8f3ac */ b #0xa2040;
}

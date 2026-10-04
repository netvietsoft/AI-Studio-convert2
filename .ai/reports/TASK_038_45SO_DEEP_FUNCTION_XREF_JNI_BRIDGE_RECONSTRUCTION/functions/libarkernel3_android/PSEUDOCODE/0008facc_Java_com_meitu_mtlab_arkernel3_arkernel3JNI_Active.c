// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8facc
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ActiveWordColorInterface_1setEnable
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8facc | Size: 16 bytes | SHA256: 0898c36e88779fe304fb651d1e1ed854fdd77cb952951fa413719aba9cfe5469
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar324ActiveWordColorInterface9setEnableEb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ActiveWordColorInterface_1setEnable(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8facc */ tst w4, #0xff;
    /* 0x8fad0 */ mov x0, x2;
    /* 0x8fad4 */ cset w1, ne;
    /* 0x8fad8 */ b #0xa24a0;
}

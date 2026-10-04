// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8bb64
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextGlowConfiguration_1setColorWork
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8bb64 | Size: 16 bytes | SHA256: 631e60efde02fecd918114cc956c701dec92703bd76790da4dd290cb3aa0443a
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar321TextGlowConfiguration12setColorWorkEb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextGlowConfiguration_1setColorWork(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8bb64 */ tst w4, #0xff;
    /* 0x8bb68 */ mov x0, x2;
    /* 0x8bb6c */ cset w1, ne;
    /* 0x8bb70 */ b #0xa0b70;
}

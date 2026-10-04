// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8bec4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextShadowConfiguration_1setColorWork
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8bec4 | Size: 16 bytes | SHA256: 536f16a0fb0e4e9f90f878dcce625a5910f7f40973191c6aba3298e7445a1077
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323TextShadowConfiguration12setColorWorkEb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextShadowConfiguration_1setColorWork(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8bec4 */ tst w4, #0xff;
    /* 0x8bec8 */ mov x0, x2;
    /* 0x8becc */ cset w1, ne;
    /* 0x8bed0 */ b #0xa0d10;
}

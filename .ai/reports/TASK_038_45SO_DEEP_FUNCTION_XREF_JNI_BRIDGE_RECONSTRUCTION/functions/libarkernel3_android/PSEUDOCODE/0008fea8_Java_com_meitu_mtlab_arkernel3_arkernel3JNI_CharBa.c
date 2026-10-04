// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8fea8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_CharBackgroundInterface_1setEnable
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8fea8 | Size: 16 bytes | SHA256: a9a533c2bb67111e881ffb5dfd32f0f735094bdb0bdd522c83d90b8e55c7a3ea
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323CharBackgroundInterface9setEnableEb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_CharBackgroundInterface_1setEnable(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8fea8 */ tst w4, #0xff;
    /* 0x8feac */ mov x0, x2;
    /* 0x8feb0 */ cset w1, ne;
    /* 0x8feb4 */ b #0xa25a0;
}

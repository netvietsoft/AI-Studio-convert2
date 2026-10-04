// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8f954
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ActiveWordBgInterface_1setEnableGradientBG
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8f954 | Size: 16 bytes | SHA256: 6281aa867f50144698c7fecafb88e1154be59cfb695733d89219cbfc1f9c0b8d
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar321ActiveWordBgInterface19setEnableGradientBGEb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ActiveWordBgInterface_1setEnableGradientBG(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8f954 */ tst w4, #0xff;
    /* 0x8f958 */ mov x0, x2;
    /* 0x8f95c */ cset w1, ne;
    /* 0x8f960 */ b #0xa22f0;
}

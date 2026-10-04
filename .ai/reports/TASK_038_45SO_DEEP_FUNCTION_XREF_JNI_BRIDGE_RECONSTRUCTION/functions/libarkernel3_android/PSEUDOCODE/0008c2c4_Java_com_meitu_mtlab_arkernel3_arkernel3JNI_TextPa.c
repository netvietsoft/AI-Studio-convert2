// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8c2c4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextPathConfig_1enableBend_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8c2c4 | Size: 20 bytes | SHA256: 175a4d9d70b5c3be3e78b9a6a77c23433d0776e3be86eea56ccc13f48b342eb7
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextPathConfig_1enableBend_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x8c2c4 */ cbz x2, #0x8c2d4;
    /* 0x8c2c8 */ tst w4, #0xff;
    /* 0x8c2cc */ cset w8, ne;
    /* 0x8c2d0 */ strb w8, [x2, #0x34];
    return x0;
}

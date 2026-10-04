// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8c344
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextPathConfig_1enableAspectRatio_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8c344 | Size: 20 bytes | SHA256: 3283b54173422c92134cb5899004fc0410d79988df204d351e8ccdeea2cb2ca2
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextPathConfig_1enableAspectRatio_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x8c344 */ cbz x2, #0x8c354;
    /* 0x8c348 */ tst w4, #0xff;
    /* 0x8c34c */ cset w8, ne;
    /* 0x8c350 */ strb w8, [x2, #0x4c];
    return x0;
}

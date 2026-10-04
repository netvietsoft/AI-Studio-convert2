// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8ba80
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextGlowConfiguration_1setEnable
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8ba80 | Size: 16 bytes | SHA256: 4198c1ba1f57fad2b72e80e1e8a7de6e62ec79dd4bdeb249ac73e19ae1fc0a6d
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar321TextGlowConfiguration9setEnableEb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextGlowConfiguration_1setEnable(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8ba80 */ tst w4, #0xff;
    /* 0x8ba84 */ mov x0, x2;
    /* 0x8ba88 */ cset w1, ne;
    /* 0x8ba8c */ b #0xa0b10;
}

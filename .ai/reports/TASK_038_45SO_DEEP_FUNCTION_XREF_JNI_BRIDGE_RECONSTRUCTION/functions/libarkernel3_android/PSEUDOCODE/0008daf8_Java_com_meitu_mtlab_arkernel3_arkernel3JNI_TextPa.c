// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8daf8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextPathConfiguration_1setEnableAspectRatio
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8daf8 | Size: 16 bytes | SHA256: 3a63e33ee2dabaa84be1be788134a547c9c2f13dd93869174265d0bf2640ea0a
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar321TextPathConfiguration20setEnableAspectRatioEb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextPathConfiguration_1setEnableAspectRatio(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8daf8 */ tst w4, #0xff;
    /* 0x8dafc */ mov x0, x2;
    /* 0x8db00 */ cset w1, ne;
    /* 0x8db04 */ b #0xa11d0;
}

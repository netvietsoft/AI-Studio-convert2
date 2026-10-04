// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8bb28
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextGlowConfiguration_1setColorA
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8bb28 | Size: 32 bytes | SHA256: 80907937795933f49bf701e3bd98cf0e1a4d9fa8268ffa445ceb07ad3c40c580
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar321TextGlowConfiguration9setColorAERKNS_6ColorAE
// Strings referenced:
//   "mtlabar3::ColorA const & reference is null"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextGlowConfiguration_1setColorA(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x8bb28 */ cbz x4, #0x8bb38;
    /* 0x8bb2c */ mov x0, x2;
    /* 0x8bb30 */ mov x1, x4;
    /* 0x8bb34 */ b #0xa0b50;
    /* 0x8bb38 */ adrp x2, #0x6d000;
    /* 0x8bb3c */ add x2, x2, #0xdc9;
    /* 0x8bb40 */ mov w1, #7;
    /* 0x8bb44 */ b #0x882c8;
}

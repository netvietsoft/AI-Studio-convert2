// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8bd68
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextGradientConfiguration_1setColors
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8bd68 | Size: 32 bytes | SHA256: b5de96f39d3077497bfffcbb4671d4ecaad648c743bdca1bf9dab669095afb11
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar325TextGradientConfiguration9setColorsERKNSt6__ndk16vectorINS_6ColorAENS1_9allocatorIS3_EEEE
// Strings referenced:
//   "std::vector< mtlabar3::ColorA > const & reference is null"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextGradientConfiguration_1setColors(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x8bd68 */ cbz x4, #0x8bd78;
    /* 0x8bd6c */ mov x0, x2;
    /* 0x8bd70 */ mov x1, x4;
    /* 0x8bd74 */ b #0xa0c20;
    /* 0x8bd78 */ adrp x2, #0x6e000;
    /* 0x8bd7c */ add x2, x2, #0x133;
    /* 0x8bd80 */ mov w1, #7;
    /* 0x8bd84 */ b #0x882c8;
}

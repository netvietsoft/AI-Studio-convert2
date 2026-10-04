// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8df74
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SelectionHighlightInterface_1setFallbackFontLibraries
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8df74 | Size: 32 bytes | SHA256: c5bd600d2c3420401fc61b1bb49e059b92fe19836fa45fe843b3f6b4dc002314
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar327SelectionHighlightInterface24setFallbackFontLibrariesERKNSt6__ndk16vectorINS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEENS6_IS8_EEEE
// Strings referenced:
//   "std::vector< std::string > const & reference is null"

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SelectionHighlightInterface_1setFallbackFontLibraries(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x8df74 */ cbz x4, #0x8df84;
    /* 0x8df78 */ mov x0, x2;
    /* 0x8df7c */ mov x1, x4;
    /* 0x8df80 */ b #0xa13b0;
    /* 0x8df84 */ adrp x2, #0x6e000;
    /* 0x8df88 */ add x2, x2, #0x539;
    /* 0x8df8c */ mov w1, #7;
    /* 0x8df90 */ b #0x882c8;
}

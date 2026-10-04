// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x91768
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1setFallbackFontLibraries
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x91768 | Size: 32 bytes | SHA256: 707dfc86eda4d64976dbdb52cac6de021ce148cc941052b0bc3be7642c016341
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323SubTextLayerInteraction24setFallbackFontLibrariesERKNSt6__ndk16vectorINS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEENS6_IS8_EEEE
// Strings referenced:
//   "std::vector< std::string > const & reference is null"

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1setFallbackFontLibraries(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x91768 */ cbz x4, #0x91778;
    /* 0x9176c */ mov x0, x2;
    /* 0x91770 */ mov x1, x4;
    /* 0x91774 */ b #0xa27b0;
    /* 0x91778 */ adrp x2, #0x6e000;
    /* 0x9177c */ add x2, x2, #0x539;
    /* 0x91780 */ mov w1, #7;
    /* 0x91784 */ b #0x882c8;
}

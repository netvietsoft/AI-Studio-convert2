// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x92ee0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerAnimationInteraction_1setFontLibraryList
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x92ee0 | Size: 32 bytes | SHA256: a3ec0c02d240bcbfa29f08a69a8aadc7610aee38070eb099e008ed2e8837c9ae
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar325LayerAnimationInteraction18setFontLibraryListERKNSt6__ndk16vectorINS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEENS6_IS8_EEEE
// Strings referenced:
//   "std::vector< std::string > const & reference is null"

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerAnimationInteraction_1setFontLibraryList(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x92ee0 */ cbz x4, #0x92ef0;
    /* 0x92ee4 */ mov x0, x2;
    /* 0x92ee8 */ mov x1, x4;
    /* 0x92eec */ b #0xa3370;
    /* 0x92ef0 */ adrp x2, #0x6e000;
    /* 0x92ef4 */ add x2, x2, #0x539;
    /* 0x92ef8 */ mov w1, #7;
    /* 0x92efc */ b #0x882c8;
}

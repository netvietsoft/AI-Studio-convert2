// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x92160
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerTextInteraction_1setCompositionTextPaths
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x92160 | Size: 32 bytes | SHA256: 424cd8eaab9a7943b959eb461b9a1c169f76f71f7c4ec5519f4045c7a029a901
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar320LayerTextInteraction23setCompositionTextPathsERKNSt6__ndk16vectorINS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEENS6_IS8_EEEE
// Strings referenced:
//   "std::vector< std::string > const & reference is null"

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerTextInteraction_1setCompositionTextPaths(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x92160 */ cbz x4, #0x92170;
    /* 0x92164 */ mov x0, x2;
    /* 0x92168 */ mov x1, x4;
    /* 0x9216c */ b #0xa2e40;
    /* 0x92170 */ adrp x2, #0x6e000;
    /* 0x92174 */ add x2, x2, #0x539;
    /* 0x92178 */ mov w1, #7;
    /* 0x9217c */ b #0x882c8;
}

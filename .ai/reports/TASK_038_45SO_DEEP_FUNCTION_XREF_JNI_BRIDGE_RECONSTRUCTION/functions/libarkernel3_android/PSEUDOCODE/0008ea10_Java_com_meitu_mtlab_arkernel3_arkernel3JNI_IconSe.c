// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8ea10
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_IconSequenceColorInterface_1setPlaceholders
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8ea10 | Size: 32 bytes | SHA256: a73895edd90db0667844ab9c673e283e10f80962144178e9422fc06f8c147501
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar326IconSequenceColorInterface15setPlaceholdersERKNSt6__ndk16vectorINS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEENS6_IS8_EEEE
// Strings referenced:
//   "std::vector< std::string > const & reference is null"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_IconSequenceColorInterface_1setPlaceholders(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x8ea10 */ cbz x4, #0x8ea20;
    /* 0x8ea14 */ mov x0, x2;
    /* 0x8ea18 */ mov x1, x4;
    /* 0x8ea1c */ b #0xa1ab0;
    /* 0x8ea20 */ adrp x2, #0x6e000;
    /* 0x8ea24 */ add x2, x2, #0x539;
    /* 0x8ea28 */ mov w1, #7;
    /* 0x8ea2c */ b #0x882c8;
}

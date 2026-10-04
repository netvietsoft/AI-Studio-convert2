// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x91560
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1setMissText
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x91560 | Size: 32 bytes | SHA256: ed2046943c53d3a893350074a374ff620036d1d42638c6535f27c5034ed4df76
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323SubTextLayerInteraction11setMissTextERKNSt6__ndk16vectorINS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEENS6_IS8_EEEE
// Strings referenced:
//   "std::vector< std::string > const & reference is null"

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1setMissText(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x91560 */ cbz x4, #0x91570;
    /* 0x91564 */ mov x0, x2;
    /* 0x91568 */ mov x1, x4;
    /* 0x9156c */ b #0xa2770;
    /* 0x91570 */ adrp x2, #0x6e000;
    /* 0x91574 */ add x2, x2, #0x539;
    /* 0x91578 */ mov w1, #7;
    /* 0x9157c */ b #0x882c8;
}

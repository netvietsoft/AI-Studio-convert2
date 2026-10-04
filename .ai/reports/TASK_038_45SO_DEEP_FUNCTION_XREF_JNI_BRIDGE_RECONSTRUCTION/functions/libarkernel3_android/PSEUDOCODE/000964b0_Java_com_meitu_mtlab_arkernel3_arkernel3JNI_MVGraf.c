// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x964b0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_MVGraffitiPenControl_1addBrushConfig
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x964b0 | Size: 32 bytes | SHA256: 796b320c6d85fa3d75a3742b7f826e690583361c82fd689a390f2d7b993f87c9
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar320MVGraffitiPenControl14addBrushConfigERKNSt6__ndk16vectorINS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEENS6_IS8_EEEE
// Strings referenced:
//   "std::vector< std::string > const & reference is null"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_MVGraffitiPenControl_1addBrushConfig(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x964b0 */ cbz x4, #0x964c0;
    /* 0x964b4 */ mov x0, x2;
    /* 0x964b8 */ mov x1, x4;
    /* 0x964bc */ b #0xa4c70;
    /* 0x964c0 */ adrp x2, #0x6e000;
    /* 0x964c4 */ add x2, x2, #0x539;
    /* 0x964c8 */ mov w1, #7;
    /* 0x964cc */ b #0x882c8;
}

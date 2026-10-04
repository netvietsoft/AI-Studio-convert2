// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8bc74
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextGradientConfiguration_1setPoints
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8bc74 | Size: 32 bytes | SHA256: c2f71a2c1fac684c51857aba5948c34838070b9d77ef82e2f18972771c383c51
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar325TextGradientConfiguration9setPointsERKNSt6__ndk16vectorINS_6Float2ENS1_9allocatorIS3_EEEE
// Strings referenced:
//   "std::vector< mtlabar3::Point2F > const & reference is null"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextGradientConfiguration_1setPoints(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x8bc74 */ cbz x4, #0x8bc84;
    /* 0x8bc78 */ mov x0, x2;
    /* 0x8bc7c */ mov x1, x4;
    /* 0x8bc80 */ b #0xa0c00;
    /* 0x8bc84 */ adrp x2, #0x6e000;
    /* 0x8bc88 */ add x2, x2, #0x6bf;
    /* 0x8bc8c */ mov w1, #7;
    /* 0x8bc90 */ b #0x882c8;
}

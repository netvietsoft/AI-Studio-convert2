// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8bf08
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextShadowConfiguration_1setOffset
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8bf08 | Size: 32 bytes | SHA256: a0d88e7ebfad144065a3021a45cb3534363584d543e82aaf6465081c0998b6e0
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323TextShadowConfiguration9setOffsetERKNS_6Float2E
// Strings referenced:
//   "mtlabar3::Float2 const & reference is null"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextShadowConfiguration_1setOffset(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x8bf08 */ cbz x4, #0x8bf18;
    /* 0x8bf0c */ mov x0, x2;
    /* 0x8bf10 */ mov x1, x4;
    /* 0x8bf14 */ b #0xa0d30;
    /* 0x8bf18 */ adrp x2, #0x6d000;
    /* 0x8bf1c */ add x2, x2, #0x83b;
    /* 0x8bf20 */ mov w1, #7;
    /* 0x8bf24 */ b #0x882c8;
}

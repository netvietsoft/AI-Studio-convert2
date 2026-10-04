// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8be88
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextShadowConfiguration_1setColorA
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8be88 | Size: 32 bytes | SHA256: 76ddfd32d08493e14668455220a07d54a0fcaa88a8c707f5a82c559ea9a7ed93
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323TextShadowConfiguration9setColorAERKNS_6ColorAE
// Strings referenced:
//   "mtlabar3::ColorA const & reference is null"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextShadowConfiguration_1setColorA(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x8be88 */ cbz x4, #0x8be98;
    /* 0x8be8c */ mov x0, x2;
    /* 0x8be90 */ mov x1, x4;
    /* 0x8be94 */ b #0xa0cf0;
    /* 0x8be98 */ adrp x2, #0x6d000;
    /* 0x8be9c */ add x2, x2, #0xdc9;
    /* 0x8bea0 */ mov w1, #7;
    /* 0x8bea4 */ b #0x882c8;
}

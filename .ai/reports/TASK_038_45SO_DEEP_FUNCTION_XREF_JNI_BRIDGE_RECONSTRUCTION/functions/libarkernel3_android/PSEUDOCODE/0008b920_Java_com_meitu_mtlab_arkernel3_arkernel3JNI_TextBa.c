// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8b920
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextBackgroundColorConfiguration_1setColorA
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8b920 | Size: 32 bytes | SHA256: 9e0b87e0a474896d5022973f49fff6d896b00f5219f0f9e250540106b8ecf150
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar332TextBackgroundColorConfiguration9setColorAERKNS_6ColorAE
// Strings referenced:
//   "mtlabar3::ColorA const & reference is null"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextBackgroundColorConfiguration_1setColorA(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x8b920 */ cbz x4, #0x8b930;
    /* 0x8b924 */ mov x0, x2;
    /* 0x8b928 */ mov x1, x4;
    /* 0x8b92c */ b #0xa09a0;
    /* 0x8b930 */ adrp x2, #0x6d000;
    /* 0x8b934 */ add x2, x2, #0xdc9;
    /* 0x8b938 */ mov w1, #7;
    /* 0x8b93c */ b #0x882c8;
}

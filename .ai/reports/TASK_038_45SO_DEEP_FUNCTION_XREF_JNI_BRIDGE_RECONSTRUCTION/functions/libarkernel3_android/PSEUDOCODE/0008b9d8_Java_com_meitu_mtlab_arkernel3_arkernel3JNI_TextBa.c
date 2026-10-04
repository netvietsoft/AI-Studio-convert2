// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8b9d8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextBackgroundColorConfiguration_1setMarginExtendCoef
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8b9d8 | Size: 32 bytes | SHA256: 1ebef48702a7d561e542763561293f910a6645af5e00048f56f5f16c1f4f5eb2
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar332TextBackgroundColorConfiguration19setMarginExtendCoefERKNS_5RectFE
// Strings referenced:
//   "mtlabar3::RectF const & reference is null"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextBackgroundColorConfiguration_1setMarginExtendCoef(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x8b9d8 */ cbz x4, #0x8b9e8;
    /* 0x8b9dc */ mov x0, x2;
    /* 0x8b9e0 */ mov x1, x4;
    /* 0x8b9e4 */ b #0xa0a20;
    /* 0x8b9e8 */ adrp x2, #0x6e000;
    /* 0x8b9ec */ add x2, x2, #0x63b;
    /* 0x8b9f0 */ mov w1, #7;
    /* 0x8b9f4 */ b #0x882c8;
}

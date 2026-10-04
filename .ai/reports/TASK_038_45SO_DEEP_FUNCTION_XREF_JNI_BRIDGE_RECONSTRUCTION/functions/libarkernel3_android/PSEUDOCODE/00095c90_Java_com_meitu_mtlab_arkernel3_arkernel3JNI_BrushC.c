// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x95c90
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_BrushCache_1setTranslation
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x95c90 | Size: 32 bytes | SHA256: b12cdf4e0d02b554a016646caee46d2bcb3433802d3418f7dd6aa6d1a8880473
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar310BrushCache14setTranslationERKNS_6Float2E
// Strings referenced:
//   "mtlabar3::Float2 const & reference is null"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_BrushCache_1setTranslation(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x95c90 */ cbz x4, #0x95ca0;
    /* 0x95c94 */ mov x0, x2;
    /* 0x95c98 */ mov x1, x4;
    /* 0x95c9c */ b #0xa4b60;
    /* 0x95ca0 */ adrp x2, #0x6d000;
    /* 0x95ca4 */ add x2, x2, #0x83b;
    /* 0x95ca8 */ mov w1, #7;
    /* 0x95cac */ b #0x882c8;
}

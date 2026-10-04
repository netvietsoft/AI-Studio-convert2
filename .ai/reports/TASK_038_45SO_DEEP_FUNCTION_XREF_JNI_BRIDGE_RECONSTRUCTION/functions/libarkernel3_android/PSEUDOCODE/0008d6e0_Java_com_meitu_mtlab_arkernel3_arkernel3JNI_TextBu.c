// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8d6e0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextBubbleConfiguration_1setScaleSize
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8d6e0 | Size: 32 bytes | SHA256: 7da7ecfe1c5f0848187183a722fcc652ccce245f813e09a98b8cd11e3e6c345c
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323TextBubbleConfiguration12setScaleSizeERKNS_5RectFE
// Strings referenced:
//   "mtlabar3::RectF const & reference is null"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextBubbleConfiguration_1setScaleSize(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x8d6e0 */ cbz x4, #0x8d6f0;
    /* 0x8d6e4 */ mov x0, x2;
    /* 0x8d6e8 */ mov x1, x4;
    /* 0x8d6ec */ b #0xa0ed0;
    /* 0x8d6f0 */ adrp x2, #0x6e000;
    /* 0x8d6f4 */ add x2, x2, #0x63b;
    /* 0x8d6f8 */ mov w1, #7;
    /* 0x8d6fc */ b #0x882c8;
}

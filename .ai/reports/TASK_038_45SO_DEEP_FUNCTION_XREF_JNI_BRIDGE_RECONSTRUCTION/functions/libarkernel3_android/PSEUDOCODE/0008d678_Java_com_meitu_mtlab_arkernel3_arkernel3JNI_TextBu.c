// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8d678
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextBubbleConfiguration_1setPadding
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8d678 | Size: 32 bytes | SHA256: c92399d5225558b0c00ec4bd89cd67cb0d4e1d590a5ada3d0cb7e9ce029137bf
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323TextBubbleConfiguration10setPaddingERKNS_5RectFE
// Strings referenced:
//   "mtlabar3::RectF const & reference is null"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextBubbleConfiguration_1setPadding(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x8d678 */ cbz x4, #0x8d688;
    /* 0x8d67c */ mov x0, x2;
    /* 0x8d680 */ mov x1, x4;
    /* 0x8d684 */ b #0xa0eb0;
    /* 0x8d688 */ adrp x2, #0x6e000;
    /* 0x8d68c */ add x2, x2, #0x63b;
    /* 0x8d690 */ mov w1, #7;
    /* 0x8d694 */ b #0x882c8;
}

// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x926f0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerTextBGTextureInteraction_1setColor
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x926f0 | Size: 32 bytes | SHA256: 9d5358cbabda82d61ac80d6b38b4fa277bfe524b927ad6d01040864c8d2d5ce7
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar329LayerTextBGTextureInteraction8setColorERKNS_5ColorE
// Strings referenced:
//   "mtlabar3::Color const & reference is null"

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerTextBGTextureInteraction_1setColor(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x926f0 */ cbz x4, #0x92700;
    /* 0x926f4 */ mov x0, x2;
    /* 0x926f8 */ mov x1, x4;
    /* 0x926fc */ b #0xa2ef0;
    /* 0x92700 */ adrp x2, #0x6e000;
    /* 0x92704 */ add x2, x2, #0x32c;
    /* 0x92708 */ mov w1, #7;
    /* 0x9270c */ b #0x882c8;
}

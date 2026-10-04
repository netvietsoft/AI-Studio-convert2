// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x92b78
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerStickerInteraction_1enableStickerHSL
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x92b78 | Size: 16 bytes | SHA256: 7be0a6076bd0ac479999e5380e1e6561ebbf0ee05745a36c3be05b44db7fbd3c
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323LayerStickerInteraction16enableStickerHSLEb

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerStickerInteraction_1enableStickerHSL(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x92b78 */ tst w4, #0xff;
    /* 0x92b7c */ mov x0, x2;
    /* 0x92b80 */ cset w1, ne;
    /* 0x92b84 */ b #0xa3140;
}

// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x926c4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerTextBGTextureInteraction_1setEnableColor
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x926c4 | Size: 16 bytes | SHA256: fddfca56100500295878a1646ba270acf7eed37fc3e9de8caa92d75f7a80e3e9
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar329LayerTextBGTextureInteraction14setEnableColorEb

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerTextBGTextureInteraction_1setEnableColor(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x926c4 */ tst w4, #0xff;
    /* 0x926c8 */ mov x0, x2;
    /* 0x926cc */ cset w1, ne;
    /* 0x926d0 */ b #0xa2ed0;
}

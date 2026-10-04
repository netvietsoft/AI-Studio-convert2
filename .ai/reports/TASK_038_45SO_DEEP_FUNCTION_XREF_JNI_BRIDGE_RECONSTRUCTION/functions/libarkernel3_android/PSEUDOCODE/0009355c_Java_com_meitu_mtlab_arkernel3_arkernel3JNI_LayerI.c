// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x9355c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerInteraction_1setIsCurrentRenderThumbnail
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x9355c | Size: 16 bytes | SHA256: b4dd30c6b772c863092359827096d840331d37b15a0b83baaab271deb029aaed
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar316LayerInteraction27setIsCurrentRenderThumbnailEb

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerInteraction_1setIsCurrentRenderThumbnail(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x9355c */ tst w4, #0xff;
    /* 0x93560 */ mov x0, x2;
    /* 0x93564 */ cset w1, ne;
    /* 0x93568 */ b #0xa3890;
}

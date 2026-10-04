// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8b3ec
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_CanvasProperty_1layerLimitArea_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8b3ec | Size: 20 bytes | SHA256: 155b4c90fb336676bb4bdd7f73cf8bec0e8c00bb01733f76ef709a10597e2b50
// Callers: 0 | Callees: 0 | Imports: 0


jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_CanvasProperty_1layerLimitArea_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x8b3ec */ cbz x2, #0x8b3fc;
    /* 0x8b3f0 */ tst w4, #0xff;
    /* 0x8b3f4 */ cset w8, ne;
    /* 0x8b3f8 */ strb w8, [x2, #0x14];
    return x0;
}

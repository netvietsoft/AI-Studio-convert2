// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x926d4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerTextBGTextureInteraction_1getEnableColor
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x926d4 | Size: 28 bytes | SHA256: 21043cea1b7f3d75a7c812b12c973eaddf77a99640035b10aade103b9e7069d9
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar329LayerTextBGTextureInteraction14getEnableColorEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerTextBGTextureInteraction_1getEnableColor(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x926d4 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x926d8 */ mov x29, sp;
    /* 0x926dc */ mov x0, x2;
    _ZN8mtlabar329LayerTextBGTextureInteraction14getEnableColorEv();
    /* 0x926e4 */ and w0, w0, #1;
    /* 0x926e8 */ ldp x29, x30, [sp], #0x10;
    return x0;
}

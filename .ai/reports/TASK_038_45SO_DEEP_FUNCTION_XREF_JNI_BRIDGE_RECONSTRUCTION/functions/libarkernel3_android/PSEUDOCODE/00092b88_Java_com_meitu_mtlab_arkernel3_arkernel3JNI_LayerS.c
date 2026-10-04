// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x92b88
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerStickerInteraction_1isStickerHSLEnabled
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x92b88 | Size: 28 bytes | SHA256: 8adde19d10a584406b23ce51bf17386806d32faa85964c59a46e7321127f0202
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar323LayerStickerInteraction19isStickerHSLEnabledEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerStickerInteraction_1isStickerHSLEnabled(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x92b88 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x92b8c */ mov x29, sp;
    /* 0x92b90 */ mov x0, x2;
    _ZNK8mtlabar323LayerStickerInteraction19isStickerHSLEnabledEv();
    /* 0x92b98 */ and w0, w0, #1;
    /* 0x92b9c */ ldp x29, x30, [sp], #0x10;
    return x0;
}

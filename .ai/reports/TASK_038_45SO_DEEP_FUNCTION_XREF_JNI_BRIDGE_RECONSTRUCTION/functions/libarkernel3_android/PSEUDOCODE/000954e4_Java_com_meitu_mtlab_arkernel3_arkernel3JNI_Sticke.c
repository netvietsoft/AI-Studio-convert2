// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x954e4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_StickerControl_1getStickerFPS
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x954e4 | Size: 28 bytes | SHA256: a785e8c5431193ba4c7658e6d9031b60172ffd085c68bf98cd5f4c97a9ac5f64
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar314StickerControl13getStickerFPSEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_StickerControl_1getStickerFPS(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x954e4 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x954e8 */ mov x29, sp;
    /* 0x954ec */ mov x0, x2;
    _ZNK8mtlabar314StickerControl13getStickerFPSEv();
    /* 0x954f4 */ mov w0, w0;
    /* 0x954f8 */ ldp x29, x30, [sp], #0x10;
    return x0;
}

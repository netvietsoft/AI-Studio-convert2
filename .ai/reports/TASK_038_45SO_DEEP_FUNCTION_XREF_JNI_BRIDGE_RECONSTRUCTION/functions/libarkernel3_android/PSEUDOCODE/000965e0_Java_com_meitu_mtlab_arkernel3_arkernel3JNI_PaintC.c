// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x965e0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_PaintControl_1isInPainting
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x965e0 | Size: 28 bytes | SHA256: 43066d21fb319e713c97fade6dfdc5b9d985dc6b42c4e1aa6c3c44de3d352a04
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar312PaintControl12isInPaintingEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_PaintControl_1isInPainting(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x965e0 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x965e4 */ mov x29, sp;
    /* 0x965e8 */ mov x0, x2;
    _ZNK8mtlabar312PaintControl12isInPaintingEv();
    /* 0x965f0 */ and w0, w0, #1;
    /* 0x965f4 */ ldp x29, x30, [sp], #0x10;
    return x0;
}

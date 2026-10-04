// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x96604
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_PaintControl_1canUndo
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x96604 | Size: 28 bytes | SHA256: 889622bf6dd84df0ef7b23d852a6a13704259195b0641172eb03766c40e08722
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar312PaintControl7canUndoEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_PaintControl_1canUndo(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x96604 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x96608 */ mov x29, sp;
    /* 0x9660c */ mov x0, x2;
    _ZNK8mtlabar312PaintControl7canUndoEv();
    /* 0x96614 */ and w0, w0, #1;
    /* 0x96618 */ ldp x29, x30, [sp], #0x10;
    return x0;
}

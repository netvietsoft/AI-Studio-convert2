// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x96620
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_PaintControl_1undoLast
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x96620 | Size: 28 bytes | SHA256: 427ddc10623314bf33520ea2d5fc4ee3691bac4810526f91ae8acda1830b7ec0
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar312PaintControl8undoLastEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_PaintControl_1undoLast(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x96620 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x96624 */ mov x29, sp;
    /* 0x96628 */ mov x0, x2;
    _ZN8mtlabar312PaintControl8undoLastEv();
    /* 0x96630 */ and w0, w0, #1;
    /* 0x96634 */ ldp x29, x30, [sp], #0x10;
    return x0;
}

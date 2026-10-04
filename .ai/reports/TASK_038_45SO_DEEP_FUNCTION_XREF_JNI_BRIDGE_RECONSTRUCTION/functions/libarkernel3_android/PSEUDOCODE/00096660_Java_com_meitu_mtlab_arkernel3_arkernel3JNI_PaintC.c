// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x96660
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_PaintControl_1redoLast
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x96660 | Size: 28 bytes | SHA256: 4cee73255d70cf4be6fc79489c6e0abe7e279365a23d390a9e4d468236b47b88
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar312PaintControl8redoLastEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_PaintControl_1redoLast(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x96660 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x96664 */ mov x29, sp;
    /* 0x96668 */ mov x0, x2;
    _ZN8mtlabar312PaintControl8redoLastEv();
    /* 0x96670 */ and w0, w0, #1;
    /* 0x96674 */ ldp x29, x30, [sp], #0x10;
    return x0;
}

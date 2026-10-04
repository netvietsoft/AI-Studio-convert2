// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x96644
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_PaintControl_1canRedo
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x96644 | Size: 28 bytes | SHA256: 2d39b40ef2065b31f10b327e5f2b5feb79f2a03c847e808fbb84d725ae8b86a7
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar312PaintControl7canRedoEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_PaintControl_1canRedo(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x96644 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x96648 */ mov x29, sp;
    /* 0x9664c */ mov x0, x2;
    _ZNK8mtlabar312PaintControl7canRedoEv();
    /* 0x96654 */ and w0, w0, #1;
    /* 0x96658 */ ldp x29, x30, [sp], #0x10;
    return x0;
}

// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x95bf8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_BrushCache_1getUseArrowHead
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x95bf8 | Size: 28 bytes | SHA256: 4ac6dff657a573343094ee5c0aabe8d5d405ed787c7e8e6cd83809c20f1bbc51
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar310BrushCache15getUseArrowHeadEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_BrushCache_1getUseArrowHead(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x95bf8 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x95bfc */ mov x29, sp;
    /* 0x95c00 */ mov x0, x2;
    _ZNK8mtlabar310BrushCache15getUseArrowHeadEv();
    /* 0x95c08 */ and w0, w0, #1;
    /* 0x95c0c */ ldp x29, x30, [sp], #0x10;
    return x0;
}

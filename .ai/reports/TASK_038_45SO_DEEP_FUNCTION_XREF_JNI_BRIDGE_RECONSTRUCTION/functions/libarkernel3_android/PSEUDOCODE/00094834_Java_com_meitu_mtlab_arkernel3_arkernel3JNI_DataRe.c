// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x94834
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireBodySlim3DBreastReduction
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x94834 | Size: 28 bytes | SHA256: 56b8ae3bf7b17d0fe9040708f778e1c8663b47c10a9099b084208c7e11ae694a
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire32requireBodySlim3DBreastReductionEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireBodySlim3DBreastReduction(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x94834 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x94838 */ mov x29, sp;
    /* 0x9483c */ mov x0, x2;
    _ZNK8mtlabar311DataRequire32requireBodySlim3DBreastReductionEv();
    /* 0x94844 */ and w0, w0, #1;
    /* 0x94848 */ ldp x29, x30, [sp], #0x10;
    return x0;
}

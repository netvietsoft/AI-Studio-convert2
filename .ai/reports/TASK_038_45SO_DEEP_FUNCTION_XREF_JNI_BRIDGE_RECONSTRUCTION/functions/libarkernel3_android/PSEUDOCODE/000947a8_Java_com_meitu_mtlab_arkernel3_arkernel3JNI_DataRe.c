// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x947a8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireBodySlim3DThinLowerAbdomens
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x947a8 | Size: 28 bytes | SHA256: 8a804dbb38c0850b40e3b3851dd6e1ac6ec040cc35e570c65c3349d7cdc0eca3
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire34requireBodySlim3DThinLowerAbdomensEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireBodySlim3DThinLowerAbdomens(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x947a8 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x947ac */ mov x29, sp;
    /* 0x947b0 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire34requireBodySlim3DThinLowerAbdomensEv();
    /* 0x947b8 */ and w0, w0, #1;
    /* 0x947bc */ ldp x29, x30, [sp], #0x10;
    return x0;
}

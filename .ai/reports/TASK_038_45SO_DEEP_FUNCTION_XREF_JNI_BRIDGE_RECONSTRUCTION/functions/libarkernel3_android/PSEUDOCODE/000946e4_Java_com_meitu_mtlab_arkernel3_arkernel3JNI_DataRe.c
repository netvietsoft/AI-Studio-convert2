// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x946e4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireSpaceDepth
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x946e4 | Size: 28 bytes | SHA256: fd63575e17f6ce9f63f3d24f655d6c01e727ec0511e23feb389e1d685ad90486
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire17requireSpaceDepthEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireSpaceDepth(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x946e4 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x946e8 */ mov x29, sp;
    /* 0x946ec */ mov x0, x2;
    _ZNK8mtlabar311DataRequire17requireSpaceDepthEv();
    /* 0x946f4 */ and w0, w0, #1;
    /* 0x946f8 */ ldp x29, x30, [sp], #0x10;
    return x0;
}

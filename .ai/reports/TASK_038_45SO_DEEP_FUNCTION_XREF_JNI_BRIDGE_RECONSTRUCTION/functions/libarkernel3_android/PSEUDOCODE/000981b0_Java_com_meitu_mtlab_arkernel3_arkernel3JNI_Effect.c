// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x981b0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_EffectData_1isApply
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x981b0 | Size: 28 bytes | SHA256: ad6aa16ab55d8fc68082f13fa3a8ba561ad482170a83745c9e2b170b6e4e1a0f
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar310EffectData7isApplyEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_EffectData_1isApply(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x981b0 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x981b4 */ mov x29, sp;
    /* 0x981b8 */ mov x0, x2;
    _ZNK8mtlabar310EffectData7isApplyEv();
    /* 0x981c0 */ and w0, w0, #1;
    /* 0x981c4 */ ldp x29, x30, [sp], #0x10;
    return x0;
}

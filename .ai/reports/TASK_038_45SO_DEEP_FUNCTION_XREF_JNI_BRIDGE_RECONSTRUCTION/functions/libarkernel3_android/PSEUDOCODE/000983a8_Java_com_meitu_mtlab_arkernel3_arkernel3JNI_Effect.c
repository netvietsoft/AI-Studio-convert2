// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x983a8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_EffectData_1hasBGM
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x983a8 | Size: 28 bytes | SHA256: 54471290926cf82e08b76502eab9d56782a70ad1af93046f2822801ba2ffce34
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar310EffectData6hasBGMEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_EffectData_1hasBGM(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x983a8 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x983ac */ mov x29, sp;
    /* 0x983b0 */ mov x0, x2;
    _ZN8mtlabar310EffectData6hasBGMEv();
    /* 0x983b8 */ and w0, w0, #1;
    /* 0x983bc */ ldp x29, x30, [sp], #0x10;
    return x0;
}

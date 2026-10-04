// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x98184
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_EffectData_1isAlready
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x98184 | Size: 28 bytes | SHA256: da25664b6fefd20918ce5563b18e65738e8c7d51be2e9f73571c0173ae997abe
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar310EffectData9isAlreadyEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_EffectData_1isAlready(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x98184 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x98188 */ mov x29, sp;
    /* 0x9818c */ mov x0, x2;
    _ZNK8mtlabar310EffectData9isAlreadyEv();
    /* 0x98194 */ and w0, w0, #1;
    /* 0x98198 */ ldp x29, x30, [sp], #0x10;
    return x0;
}

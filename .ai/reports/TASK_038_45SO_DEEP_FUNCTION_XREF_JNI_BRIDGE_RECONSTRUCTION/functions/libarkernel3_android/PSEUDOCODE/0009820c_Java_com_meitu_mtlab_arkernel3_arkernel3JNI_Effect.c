// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x9820c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_EffectData_1isSpecialMakeup
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x9820c | Size: 28 bytes | SHA256: 082a70e5631de15e10cc77005415ca3e1eb7915c4c13974c47de92d28bd4aa41
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar310EffectData15isSpecialMakeupEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_EffectData_1isSpecialMakeup(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x9820c */ stp x29, x30, [sp, #-0x10]!;
    /* 0x98210 */ mov x29, sp;
    /* 0x98214 */ mov x0, x2;
    _ZNK8mtlabar310EffectData15isSpecialMakeupEv();
    /* 0x9821c */ and w0, w0, #1;
    /* 0x98220 */ ldp x29, x30, [sp], #0x10;
    return x0;
}

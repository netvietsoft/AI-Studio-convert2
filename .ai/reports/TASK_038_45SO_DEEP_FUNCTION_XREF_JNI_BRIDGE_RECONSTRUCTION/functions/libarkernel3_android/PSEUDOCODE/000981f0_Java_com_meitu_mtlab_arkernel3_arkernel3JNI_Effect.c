// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x981f0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_EffectData_1isSpecialFacelift
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x981f0 | Size: 28 bytes | SHA256: 341ad7a0cf52350c8362bf20ee719d6302d04bac940a96ec66a7eb35db3b409c
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar310EffectData17isSpecialFaceliftEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_EffectData_1isSpecialFacelift(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x981f0 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x981f4 */ mov x29, sp;
    /* 0x981f8 */ mov x0, x2;
    _ZNK8mtlabar310EffectData17isSpecialFaceliftEv();
    /* 0x98200 */ and w0, w0, #1;
    /* 0x98204 */ ldp x29, x30, [sp], #0x10;
    return x0;
}

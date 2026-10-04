// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x9857c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_EffectData_1applyGlobalJson
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x9857c | Size: 148 bytes | SHA256: 9805c500696f1a9b0ef3f8d486bbbba25c632d7700b1e0c9fcf7b76a67988a26
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar310EffectData15applyGlobalJsonEPKc

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_EffectData_1applyGlobalJson(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 37 instructions
    /* 0x9857c */ stp x29, x30, [sp, #-0x30]!;
    /* 0x98580 */ stp x22, x21, [sp, #0x10];
    /* 0x98584 */ stp x20, x19, [sp, #0x20];
    /* 0x98588 */ mov x29, sp;
    /* 0x9858c */ mov x21, x2;
    /* 0x98590 */ cbz x4, #0x985e4;
    /* 0x98594 */ ldr x8, [x0];
    /* 0x98598 */ mov x1, x4;
    /* 0x9859c */ mov x2, xzr;
    /* 0x985a0 */ mov x19, x4;
    /* 0x985a4 */ mov x20, x0;
    _ZN8mtlabar310EffectData15applyGlobalJsonEPKc();
    _ZN8mtlabar310EffectData15applyGlobalJsonEPKc();
    return x0;
}

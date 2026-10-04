// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x98518
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_EffectData_1getAIConfig
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x98518 | Size: 72 bytes | SHA256: 70e31f969b2740cfd157b1b90275b29ea92feb850c63f3f7db05543632db9632
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar310EffectData11getAIConfigEm

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_EffectData_1getAIConfig(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 18 instructions
    /* 0x98518 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x9851c */ str x19, [sp, #0x10];
    /* 0x98520 */ mov x29, sp;
    /* 0x98524 */ mov x1, x4;
    /* 0x98528 */ mov x19, x0;
    /* 0x9852c */ mov x0, x2;
    _ZNK8mtlabar310EffectData11getAIConfigEm();
    /* 0x98534 */ cbz x0, #0x98554;
    /* 0x98538 */ ldr x8, [x19];
    /* 0x9853c */ mov x1, x0;
    /* 0x98540 */ ldr x2, [x8, #0x538];
    return x0;
}

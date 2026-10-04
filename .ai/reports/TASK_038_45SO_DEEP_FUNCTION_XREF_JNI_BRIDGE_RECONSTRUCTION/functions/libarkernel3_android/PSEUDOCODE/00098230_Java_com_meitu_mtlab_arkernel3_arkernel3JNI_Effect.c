// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x98230
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_EffectData_1getCustomParamKey
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x98230 | Size: 72 bytes | SHA256: 3de46b118b6fe8eea7422b31536fc5e9085ca48440c8bd544fa5d2c9654dfa60
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar310EffectData17getCustomParamKeyEm

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_EffectData_1getCustomParamKey(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 18 instructions
    /* 0x98230 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x98234 */ str x19, [sp, #0x10];
    /* 0x98238 */ mov x29, sp;
    /* 0x9823c */ mov x1, x4;
    /* 0x98240 */ mov x19, x0;
    /* 0x98244 */ mov x0, x2;
    _ZNK8mtlabar310EffectData17getCustomParamKeyEm();
    /* 0x9824c */ cbz x0, #0x9826c;
    /* 0x98250 */ ldr x8, [x19];
    /* 0x98254 */ mov x1, x0;
    /* 0x98258 */ ldr x2, [x8, #0x538];
    return x0;
}

// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x982c0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_EffectData_1insertCustomParam
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x982c0 | Size: 232 bytes | SHA256: 9d71ba03a207f64bcd8fabd0b41f231d6dc4c82caf5ed5a8a7c9e3e69d455c4b
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar310EffectData17insertCustomParamEPKcS2_

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_EffectData_1insertCustomParam(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 58 instructions
    /* 0x982c0 */ stp x29, x30, [sp, #-0x40]!;
    /* 0x982c4 */ stp x24, x23, [sp, #0x10];
    /* 0x982c8 */ stp x22, x21, [sp, #0x20];
    /* 0x982cc */ stp x20, x19, [sp, #0x30];
    /* 0x982d0 */ mov x29, sp;
    /* 0x982d4 */ mov x19, x5;
    /* 0x982d8 */ mov x21, x4;
    /* 0x982dc */ mov x22, x2;
    /* 0x982e0 */ mov x20, x0;
    /* 0x982e4 */ cbz x4, #0x98330;
    /* 0x982e8 */ ldr x8, [x20];
    _ZN8mtlabar310EffectData17insertCustomParamEPKcS2_();
    return x0;
}

// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x97f00
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_EffectData_1loadConfiguration
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x97f00 | Size: 148 bytes | SHA256: 2365096b3e9b7c47e57604718a33e0cd252d1724688085dbb2ac8dfc007f5f2e
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar310EffectData17loadConfigurationEPKc

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_EffectData_1loadConfiguration(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 37 instructions
    /* 0x97f00 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x97f04 */ stp x22, x21, [sp, #0x10];
    /* 0x97f08 */ stp x20, x19, [sp, #0x20];
    /* 0x97f0c */ mov x29, sp;
    /* 0x97f10 */ mov x21, x2;
    /* 0x97f14 */ cbz x4, #0x97f6c;
    /* 0x97f18 */ ldr x8, [x0];
    /* 0x97f1c */ mov x1, x4;
    /* 0x97f20 */ mov x2, xzr;
    /* 0x97f24 */ mov x19, x4;
    /* 0x97f28 */ mov x20, x0;
    _ZN8mtlabar310EffectData17loadConfigurationEPKc();
    return x0;
}

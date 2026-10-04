// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x97f94
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_EffectData_1loadConfigurationSync
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x97f94 | Size: 148 bytes | SHA256: ae2fc83283655a9294f025c51ac61d85bdc186aa5ad9d5b51f5957b9b310b2d3
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar310EffectData21loadConfigurationSyncEPKc

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_EffectData_1loadConfigurationSync(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 37 instructions
    /* 0x97f94 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x97f98 */ stp x22, x21, [sp, #0x10];
    /* 0x97f9c */ stp x20, x19, [sp, #0x20];
    /* 0x97fa0 */ mov x29, sp;
    /* 0x97fa4 */ mov x21, x2;
    /* 0x97fa8 */ cbz x4, #0x97ffc;
    /* 0x97fac */ ldr x8, [x0];
    /* 0x97fb0 */ mov x1, x4;
    /* 0x97fb4 */ mov x2, xzr;
    /* 0x97fb8 */ mov x19, x4;
    /* 0x97fbc */ mov x20, x0;
    _ZN8mtlabar310EffectData21loadConfigurationSyncEPKc();
    _ZN8mtlabar310EffectData21loadConfigurationSyncEPKc();
    return x0;
}

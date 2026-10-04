// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x98028
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_EffectData_1parsingConfiguration
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x98028 | Size: 148 bytes | SHA256: 1557869eb0cd2866ee33f79fc02f07baa06e2d4f8a5f552922538409b0e0f479
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar310EffectData20parsingConfigurationEPKc

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_EffectData_1parsingConfiguration(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 37 instructions
    /* 0x98028 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x9802c */ stp x22, x21, [sp, #0x10];
    /* 0x98030 */ stp x20, x19, [sp, #0x20];
    /* 0x98034 */ mov x29, sp;
    /* 0x98038 */ mov x21, x2;
    /* 0x9803c */ cbz x4, #0x98094;
    /* 0x98040 */ ldr x8, [x0];
    /* 0x98044 */ mov x1, x4;
    /* 0x98048 */ mov x2, xzr;
    /* 0x9804c */ mov x19, x4;
    /* 0x98050 */ mov x20, x0;
    _ZN8mtlabar310EffectData20parsingConfigurationEPKc();
    return x0;
}

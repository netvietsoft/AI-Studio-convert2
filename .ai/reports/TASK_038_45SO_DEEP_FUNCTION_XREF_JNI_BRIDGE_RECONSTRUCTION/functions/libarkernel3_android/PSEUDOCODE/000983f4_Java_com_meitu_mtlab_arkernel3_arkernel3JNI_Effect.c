// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x983f4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_EffectData_1setBGMPath
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x983f4 | Size: 148 bytes | SHA256: 13b36ce38f52bc866eefc804a1b77395b7d6d3aad0e9e7ebbd03148af545c0a7
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar310EffectData10setBGMPathEPKc

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_EffectData_1setBGMPath(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 37 instructions
    /* 0x983f4 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x983f8 */ stp x22, x21, [sp, #0x10];
    /* 0x983fc */ stp x20, x19, [sp, #0x20];
    /* 0x98400 */ mov x29, sp;
    /* 0x98404 */ mov x21, x2;
    /* 0x98408 */ cbz x4, #0x98460;
    /* 0x9840c */ ldr x8, [x0];
    /* 0x98410 */ mov x1, x4;
    /* 0x98414 */ mov x2, xzr;
    /* 0x98418 */ mov x19, x4;
    /* 0x9841c */ mov x20, x0;
    _ZN8mtlabar310EffectData10setBGMPathEPKc();
    return x0;
}

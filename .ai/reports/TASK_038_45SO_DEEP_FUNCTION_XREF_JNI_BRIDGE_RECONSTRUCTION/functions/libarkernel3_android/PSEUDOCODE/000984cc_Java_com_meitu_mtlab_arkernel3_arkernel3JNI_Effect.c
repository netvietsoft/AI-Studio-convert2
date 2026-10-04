// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x984cc
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_EffectData_1getConfigBGMPath
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x984cc | Size: 68 bytes | SHA256: 30542758c837c5a22e545b211196d7fc1032e8019cb1ceee15b022f8fc4bf08c
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar310EffectData16getConfigBGMPathEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_EffectData_1getConfigBGMPath(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 17 instructions
    /* 0x984cc */ stp x29, x30, [sp, #-0x20]!;
    /* 0x984d0 */ str x19, [sp, #0x10];
    /* 0x984d4 */ mov x29, sp;
    /* 0x984d8 */ mov x19, x0;
    /* 0x984dc */ mov x0, x2;
    _ZN8mtlabar310EffectData16getConfigBGMPathEv();
    /* 0x984e4 */ cbz x0, #0x98504;
    /* 0x984e8 */ ldr x8, [x19];
    /* 0x984ec */ mov x1, x0;
    /* 0x984f0 */ ldr x2, [x8, #0x538];
    /* 0x984f4 */ mov x0, x19;
    return x0;
}

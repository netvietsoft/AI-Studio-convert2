// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8bdc4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextShadowConfiguration_1getEnable
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8bdc4 | Size: 28 bytes | SHA256: 8480d47655501e24559506be61977800451adb843051b3b6af609eadda56c32c
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar323TextShadowConfiguration9getEnableEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextShadowConfiguration_1getEnable(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x8bdc4 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8bdc8 */ mov x29, sp;
    /* 0x8bdcc */ mov x0, x2;
    _ZNK8mtlabar323TextShadowConfiguration9getEnableEv();
    /* 0x8bdd4 */ and w0, w0, #1;
    /* 0x8bdd8 */ ldp x29, x30, [sp], #0x10;
    return x0;
}

// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x92d24
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerAnimationInteraction_1setJsonPath
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x92d24 | Size: 148 bytes | SHA256: ee441a361d8f764cb90c2aa3f28fb9d322fa248a06a1aec44b0c6263ebd41190
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar325LayerAnimationInteraction11setJsonPathEPKc

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerAnimationInteraction_1setJsonPath(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 37 instructions
    /* 0x92d24 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x92d28 */ stp x22, x21, [sp, #0x10];
    /* 0x92d2c */ stp x20, x19, [sp, #0x20];
    /* 0x92d30 */ mov x29, sp;
    /* 0x92d34 */ mov x21, x2;
    /* 0x92d38 */ cbz x4, #0x92d90;
    /* 0x92d3c */ ldr x8, [x0];
    /* 0x92d40 */ mov x1, x4;
    /* 0x92d44 */ mov x2, xzr;
    /* 0x92d48 */ mov x19, x4;
    /* 0x92d4c */ mov x20, x0;
    _ZN8mtlabar325LayerAnimationInteraction11setJsonPathEPKc();
    return x0;
}

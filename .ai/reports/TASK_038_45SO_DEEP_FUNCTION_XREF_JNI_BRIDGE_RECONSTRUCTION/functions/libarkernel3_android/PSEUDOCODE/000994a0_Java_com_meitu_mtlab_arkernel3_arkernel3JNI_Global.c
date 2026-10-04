// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x994a0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_GlobalSetting_1setAIModelPath
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x994a0 | Size: 148 bytes | SHA256: 2004dd3d8701ca9bb30649bff56c363f4273e0a52ce14ac33a624eef659d713f
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar313GlobalSetting14setAIModelPathENS_11AIModelTypeEPKc

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_GlobalSetting_1setAIModelPath(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 37 instructions
    /* 0x994a0 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x994a4 */ stp x22, x21, [sp, #0x10];
    /* 0x994a8 */ stp x20, x19, [sp, #0x20];
    /* 0x994ac */ mov x29, sp;
    /* 0x994b0 */ mov w21, w2;
    /* 0x994b4 */ cbz x3, #0x9950c;
    /* 0x994b8 */ ldr x8, [x0];
    /* 0x994bc */ mov x1, x3;
    /* 0x994c0 */ mov x2, xzr;
    /* 0x994c4 */ mov x19, x3;
    /* 0x994c8 */ mov x20, x0;
    _ZN8mtlabar313GlobalSetting14setAIModelPathENS_11AIModelTypeEPKc();
    return x0;
}

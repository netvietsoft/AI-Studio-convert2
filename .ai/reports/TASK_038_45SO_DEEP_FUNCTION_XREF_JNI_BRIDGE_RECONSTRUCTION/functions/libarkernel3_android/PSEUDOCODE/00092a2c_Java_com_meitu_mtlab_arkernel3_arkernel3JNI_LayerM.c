// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x92a2c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerMaskInteraction_1setConfigPath
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x92a2c | Size: 148 bytes | SHA256: f38e8e4dfcc19fda0cff25ae5277b9704795fbd15f555f5c62962ebd14d3f723
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar320LayerMaskInteraction13setConfigPathEPKc

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerMaskInteraction_1setConfigPath(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 37 instructions
    /* 0x92a2c */ stp x29, x30, [sp, #-0x30]!;
    /* 0x92a30 */ stp x22, x21, [sp, #0x10];
    /* 0x92a34 */ stp x20, x19, [sp, #0x20];
    /* 0x92a38 */ mov x29, sp;
    /* 0x92a3c */ mov x21, x2;
    /* 0x92a40 */ cbz x4, #0x92a98;
    /* 0x92a44 */ ldr x8, [x0];
    /* 0x92a48 */ mov x1, x4;
    /* 0x92a4c */ mov x2, xzr;
    /* 0x92a50 */ mov x19, x4;
    /* 0x92a54 */ mov x20, x0;
    _ZN8mtlabar320LayerMaskInteraction13setConfigPathEPKc();
    return x0;
}

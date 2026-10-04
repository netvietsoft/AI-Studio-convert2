// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x93cd8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DrawFunctionCallback_1readConfig
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x93cd8 | Size: 164 bytes | SHA256: bee4e70a4fecf40fa28ee88b7dca3f7e1acf1dec127259acda1a3792bc054e48
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DrawFunctionCallback_1readConfig(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 41 instructions
    /* 0x93cd8 */ stp x29, x30, [sp, #-0x40]!;
    /* 0x93cdc */ str x23, [sp, #0x10];
    /* 0x93ce0 */ stp x22, x21, [sp, #0x20];
    /* 0x93ce4 */ stp x20, x19, [sp, #0x30];
    /* 0x93ce8 */ mov x29, sp;
    /* 0x93cec */ mov x19, x5;
    /* 0x93cf0 */ mov x21, x4;
    /* 0x93cf4 */ mov x22, x2;
    /* 0x93cf8 */ mov x20, x0;
    /* 0x93cfc */ cbz x5, #0x93d28;
    /* 0x93d00 */ ldr x8, [x20];
    return x0;
}

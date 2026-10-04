// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x93c30
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DrawFunctionCallback_1createInstance
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x93c30 | Size: 148 bytes | SHA256: f95c896b227802cca8541be760ef7b486a22133dfc1eb6efab07476268b8d0d3
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DrawFunctionCallback_1createInstance(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 37 instructions
    /* 0x93c30 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x93c34 */ stp x22, x21, [sp, #0x10];
    /* 0x93c38 */ stp x20, x19, [sp, #0x20];
    /* 0x93c3c */ mov x29, sp;
    /* 0x93c40 */ mov x19, x4;
    /* 0x93c44 */ mov x21, x2;
    /* 0x93c48 */ mov x20, x0;
    /* 0x93c4c */ cbz x4, #0x93c78;
    /* 0x93c50 */ ldr x8, [x20];
    /* 0x93c54 */ mov x0, x20;
    /* 0x93c58 */ mov x1, x19;
    return x0;
}

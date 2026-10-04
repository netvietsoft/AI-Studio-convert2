// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x93a7c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ExternalFunctionCallback_1createInstance
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x93a7c | Size: 148 bytes | SHA256: f95c896b227802cca8541be760ef7b486a22133dfc1eb6efab07476268b8d0d3
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ExternalFunctionCallback_1createInstance(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 37 instructions
    /* 0x93a7c */ stp x29, x30, [sp, #-0x30]!;
    /* 0x93a80 */ stp x22, x21, [sp, #0x10];
    /* 0x93a84 */ stp x20, x19, [sp, #0x20];
    /* 0x93a88 */ mov x29, sp;
    /* 0x93a8c */ mov x19, x4;
    /* 0x93a90 */ mov x21, x2;
    /* 0x93a94 */ mov x20, x0;
    /* 0x93a98 */ cbz x4, #0x93ac4;
    /* 0x93a9c */ ldr x8, [x20];
    /* 0x93aa0 */ mov x0, x20;
    /* 0x93aa4 */ mov x1, x19;
    return x0;
}

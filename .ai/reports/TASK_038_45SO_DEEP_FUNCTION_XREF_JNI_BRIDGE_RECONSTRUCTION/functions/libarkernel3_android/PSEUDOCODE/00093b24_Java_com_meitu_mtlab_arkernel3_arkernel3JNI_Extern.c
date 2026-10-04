// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x93b24
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ExternalFunctionCallback_1loadConfig
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x93b24 | Size: 164 bytes | SHA256: bee4e70a4fecf40fa28ee88b7dca3f7e1acf1dec127259acda1a3792bc054e48
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ExternalFunctionCallback_1loadConfig(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 41 instructions
    /* 0x93b24 */ stp x29, x30, [sp, #-0x40]!;
    /* 0x93b28 */ str x23, [sp, #0x10];
    /* 0x93b2c */ stp x22, x21, [sp, #0x20];
    /* 0x93b30 */ stp x20, x19, [sp, #0x30];
    /* 0x93b34 */ mov x29, sp;
    /* 0x93b38 */ mov x19, x5;
    /* 0x93b3c */ mov x21, x4;
    /* 0x93b40 */ mov x22, x2;
    /* 0x93b44 */ mov x20, x0;
    /* 0x93b48 */ cbz x5, #0x93b74;
    /* 0x93b4c */ ldr x8, [x20];
    return x0;
}

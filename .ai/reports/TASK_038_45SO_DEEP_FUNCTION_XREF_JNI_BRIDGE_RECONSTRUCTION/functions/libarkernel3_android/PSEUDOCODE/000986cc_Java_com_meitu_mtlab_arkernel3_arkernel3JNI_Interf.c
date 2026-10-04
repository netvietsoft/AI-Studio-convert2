// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x986cc
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_InterfaceListener_1onMessageCallback
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x986cc | Size: 240 bytes | SHA256: e0ad60d83dd3c908df9480156df8ffe27b71b9d6ac0a060e6297de852e6eec82
// Callers: 0 | Callees: 0 | Imports: 0


jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_InterfaceListener_1onMessageCallback(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 60 instructions
    /* 0x986cc */ stp x29, x30, [sp, #-0x40]!;
    /* 0x986d0 */ stp x24, x23, [sp, #0x10];
    /* 0x986d4 */ stp x22, x21, [sp, #0x20];
    /* 0x986d8 */ stp x20, x19, [sp, #0x30];
    /* 0x986dc */ mov x29, sp;
    /* 0x986e0 */ mov x19, x5;
    /* 0x986e4 */ mov x21, x4;
    /* 0x986e8 */ mov x22, x2;
    /* 0x986ec */ mov x20, x0;
    /* 0x986f0 */ cbz x4, #0x9873c;
    /* 0x986f4 */ ldr x8, [x20];
    return x0;
}

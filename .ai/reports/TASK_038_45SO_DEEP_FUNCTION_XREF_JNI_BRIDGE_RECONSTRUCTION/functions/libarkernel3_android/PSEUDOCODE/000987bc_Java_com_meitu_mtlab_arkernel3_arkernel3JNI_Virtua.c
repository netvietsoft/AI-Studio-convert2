// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x987bc
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VirtualFileSystem_1exist
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x987bc | Size: 148 bytes | SHA256: 635d5894c109f59810c17c96ddc7e796a8254b426de06385eb6dda9050f694d6
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VirtualFileSystem_1exist(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 37 instructions
    /* 0x987bc */ stp x29, x30, [sp, #-0x30]!;
    /* 0x987c0 */ stp x22, x21, [sp, #0x10];
    /* 0x987c4 */ stp x20, x19, [sp, #0x20];
    /* 0x987c8 */ mov x29, sp;
    /* 0x987cc */ mov x19, x4;
    /* 0x987d0 */ mov x21, x2;
    /* 0x987d4 */ mov x20, x0;
    /* 0x987d8 */ cbz x4, #0x98804;
    /* 0x987dc */ ldr x8, [x20];
    /* 0x987e0 */ mov x0, x20;
    /* 0x987e4 */ mov x1, x19;
    return x0;
}

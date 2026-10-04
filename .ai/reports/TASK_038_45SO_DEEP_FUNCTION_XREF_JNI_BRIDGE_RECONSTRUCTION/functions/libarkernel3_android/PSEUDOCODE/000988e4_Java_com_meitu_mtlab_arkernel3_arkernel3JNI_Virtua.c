// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x988e4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VirtualFileSystem_1readAll
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x988e4 | Size: 172 bytes | SHA256: be3fddd3e5c4412c1875dc7beb3dfad5d45d7d8de7b8cbb7b4a1cf80ae139d45
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VirtualFileSystem_1readAll(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 43 instructions
    /* 0x988e4 */ stp x29, x30, [sp, #-0x40]!;
    /* 0x988e8 */ stp x24, x23, [sp, #0x10];
    /* 0x988ec */ stp x22, x21, [sp, #0x20];
    /* 0x988f0 */ stp x20, x19, [sp, #0x30];
    /* 0x988f4 */ mov x29, sp;
    /* 0x988f8 */ mov x21, x6;
    /* 0x988fc */ mov x22, x5;
    /* 0x98900 */ mov x19, x4;
    /* 0x98904 */ mov x23, x2;
    /* 0x98908 */ mov x20, x0;
    /* 0x9890c */ cbz x4, #0x98938;
    return x0;
}

// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x94cdc
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_FaceliftControlInstance_1getFaceliftControlKeyName
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x94cdc | Size: 72 bytes | SHA256: cd16f8fa7863a51fb0e089e031a2782304b0db226a520b789f4e02343f7aee77
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar323FaceliftControlInstance25getFaceliftControlKeyNameEm

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_FaceliftControlInstance_1getFaceliftControlKeyName(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 18 instructions
    /* 0x94cdc */ stp x29, x30, [sp, #-0x20]!;
    /* 0x94ce0 */ str x19, [sp, #0x10];
    /* 0x94ce4 */ mov x29, sp;
    /* 0x94ce8 */ mov x1, x4;
    /* 0x94cec */ mov x19, x0;
    /* 0x94cf0 */ mov x0, x2;
    _ZNK8mtlabar323FaceliftControlInstance25getFaceliftControlKeyNameEm();
    /* 0x94cf8 */ cbz x0, #0x94d18;
    /* 0x94cfc */ ldr x8, [x19];
    /* 0x94d00 */ mov x1, x0;
    /* 0x94d04 */ ldr x2, [x8, #0x538];
    return x0;
}

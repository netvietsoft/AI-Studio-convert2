// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x98850
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VirtualFileSystem_1length
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x98850 | Size: 148 bytes | SHA256: 145718504a442201e6c5569089a9e9dc1e1f10e92970cf33efb3bae20c9a6fbd
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VirtualFileSystem_1length(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 37 instructions
    /* 0x98850 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x98854 */ stp x22, x21, [sp, #0x10];
    /* 0x98858 */ stp x20, x19, [sp, #0x20];
    /* 0x9885c */ mov x29, sp;
    /* 0x98860 */ mov x19, x4;
    /* 0x98864 */ mov x21, x2;
    /* 0x98868 */ mov x20, x0;
    /* 0x9886c */ cbz x4, #0x98898;
    /* 0x98870 */ ldr x8, [x20];
    /* 0x98874 */ mov x0, x20;
    /* 0x98878 */ mov x1, x19;
    return x0;
}

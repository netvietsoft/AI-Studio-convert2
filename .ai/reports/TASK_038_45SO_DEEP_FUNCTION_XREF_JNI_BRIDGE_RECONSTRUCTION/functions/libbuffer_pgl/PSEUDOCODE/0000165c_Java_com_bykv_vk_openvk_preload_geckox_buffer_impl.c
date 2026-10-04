// Library: libbuffer_pgl.so
// Function ID: libbuffer_pgl::0x165c
// Recovered Name: Java_com_bykv_vk_openvk_preload_geckox_buffer_impl_MemoryBuffer_nFlush
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x165c | Size: 304 bytes | SHA256: a65b143cd2c947a8ccdca5fb849f56bf623a7e9bc0e30411a1308719a7af5726
// Callers: 0 | Callees: 0 | Imports: 5

// Calls external APIs: __errno, close, open, strerror, write
// Strings referenced:
//   "close file failed"
//   "java/io/IOException"

jlong Java_com_bykv_vk_openvk_preload_geckox_buffer_impl_MemoryBuffer_nFlush(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 76 instructions
    /* 0x165c */ stp x29, x30, [sp, #-0x40]!;
    /* 0x1660 */ stp x24, x23, [sp, #0x10];
    /* 0x1664 */ stp x22, x21, [sp, #0x20];
    /* 0x1668 */ stp x20, x19, [sp, #0x30];
    /* 0x166c */ mov x29, sp;
    /* 0x1670 */ ldr x8, [x0];
    /* 0x1674 */ mov x21, x2;
    /* 0x1678 */ mov x1, x3;
    /* 0x167c */ mov x2, xzr;
    /* 0x1680 */ ldr x8, [x8, #0x548];
    /* 0x1684 */ mov x20, x4;
    open();
    write();
    close();
    return x0;
    __errno();
    strerror();
}

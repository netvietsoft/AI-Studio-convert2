// Library: libbuffer_pgl.so
// Function ID: libbuffer_pgl::0x12b0
// Recovered Name: Java_com_bykv_vk_openvk_preload_geckox_buffer_impl_MemoryBuffer_nCreate
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x12b0 | Size: 736 bytes | SHA256: f896139cccd11b52beaf220ed5e2d994e8e620e84df8420d5ee3e87d36c57d65
// Callers: 0 | Callees: 0 | Imports: 9

// Calls external APIs: __errno, __read_chk, calloc, close, free, ftruncate, lseek, open, strerror
// Strings referenced:
//   "File lengths are inconsistent"
//   "close failed"
//   "java/io/IOException"
//   "length illegal"
//   "native calloc failed"

jlong Java_com_bykv_vk_openvk_preload_geckox_buffer_impl_MemoryBuffer_nCreate(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 184 instructions
    /* 0x12b0 */ stp x29, x30, [sp, #-0x40]!;
    /* 0x12b4 */ str x23, [sp, #0x10];
    /* 0x12b8 */ stp x22, x21, [sp, #0x20];
    /* 0x12bc */ stp x20, x19, [sp, #0x30];
    /* 0x12c0 */ mov x29, sp;
    /* 0x12c4 */ ldr x8, [x0];
    /* 0x12c8 */ mov x19, x0;
    /* 0x12cc */ tbnz x3, #0x3f, #0x1380;
    /* 0x12d0 */ ldr x8, [x8, #0x548];
    /* 0x12d4 */ mov x22, x2;
    /* 0x12d8 */ mov x0, x19;
    open();
    lseek();
    close();
    ftruncate();
    close();
    __errno();
    strerror();
    return x0;
    lseek();
    close();
    calloc();
    __errno();
    __read_chk();
    close();
    free();
    close();
    close();
    free();
}

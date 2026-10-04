// Library: libbuffer_pgl.so
// Function ID: libbuffer_pgl::0x1028
// Recovered Name: Java_com_bykv_vk_openvk_preload_geckox_buffer_impl_MMapBuffer_nCreate
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x1028 | Size: 440 bytes | SHA256: d000e05ae2c807e6b08fcba96a26c53f6ade426884af5cdfd1a251e345e8a77f
// Callers: 0 | Callees: 0 | Imports: 8

// Calls external APIs: __android_log_print, __errno, close, ftruncate, lseek, mmap, open, strerror
// Strings referenced:
//   "Buffer"
//   "inconsistent file length"
//   "java/io/IOException"
//   "map failed"
//   "mmap failed, %s"

jlong Java_com_bykv_vk_openvk_preload_geckox_buffer_impl_MMapBuffer_nCreate(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 110 instructions
    /* 0x1028 */ stp x29, x30, [sp, #-0x40]!;
    /* 0x102c */ str x23, [sp, #0x10];
    /* 0x1030 */ stp x22, x21, [sp, #0x20];
    /* 0x1034 */ stp x20, x19, [sp, #0x30];
    /* 0x1038 */ mov x29, sp;
    /* 0x103c */ ldr x8, [x0];
    /* 0x1040 */ mov x23, x2;
    /* 0x1044 */ mov x1, x2;
    /* 0x1048 */ mov x2, xzr;
    /* 0x104c */ ldr x8, [x8, #0x548];
    /* 0x1050 */ mov x21, x3;
    open();
    lseek();
    close();
    ftruncate();
    close();
    __errno();
    strerror();
    return x0;
    mmap();
    close();
    __android_log_print();
}

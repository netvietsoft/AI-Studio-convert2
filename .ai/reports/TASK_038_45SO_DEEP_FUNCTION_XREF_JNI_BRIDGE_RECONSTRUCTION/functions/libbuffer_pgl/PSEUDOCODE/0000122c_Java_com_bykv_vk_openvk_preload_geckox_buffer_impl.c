// Library: libbuffer_pgl.so
// Function ID: libbuffer_pgl::0x122c
// Recovered Name: Java_com_bykv_vk_openvk_preload_geckox_buffer_impl_MMapBuffer_nFlush
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x122c | Size: 132 bytes | SHA256: 4d8dc7583bfde9fc04e7678550de7836d017e937c557532299ef475a941b8bec
// Callers: 0 | Callees: 0 | Imports: 3

// Calls external APIs: __errno, msync, strerror
// Strings referenced:
//   "java/io/IOException"

jlong Java_com_bykv_vk_openvk_preload_geckox_buffer_impl_MMapBuffer_nFlush(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 33 instructions
    /* 0x122c */ stp x29, x30, [sp, #-0x30]!;
    /* 0x1230 */ str x21, [sp, #0x10];
    /* 0x1234 */ stp x20, x19, [sp, #0x20];
    /* 0x1238 */ mov x29, sp;
    /* 0x123c */ mov x8, x2;
    /* 0x1240 */ mov x1, x3;
    /* 0x1244 */ mov x19, x0;
    /* 0x1248 */ mov w2, #4;
    /* 0x124c */ mov x0, x8;
    msync();
    /* 0x1254 */ mov w20, w0;
    __errno();
    strerror();
    return x0;
}

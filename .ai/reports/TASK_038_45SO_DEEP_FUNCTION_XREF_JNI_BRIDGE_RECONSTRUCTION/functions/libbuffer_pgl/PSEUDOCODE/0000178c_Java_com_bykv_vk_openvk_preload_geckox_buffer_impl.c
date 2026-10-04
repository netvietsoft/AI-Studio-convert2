// Library: libbuffer_pgl.so
// Function ID: libbuffer_pgl::0x178c
// Recovered Name: Java_com_bykv_vk_openvk_preload_geckox_buffer_impl_MReMapBuffer_nMReMap
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x178c | Size: 136 bytes | SHA256: 7a430328361842e691142a0e62bd5d2336150cc0c7c110fbb3c86d0e109abe68
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: __android_log_print, mremap
// Strings referenced:
//   "Buffer"
//   "java/io/IOException"
//   "mremap failed"

jlong Java_com_bykv_vk_openvk_preload_geckox_buffer_impl_MReMapBuffer_nMReMap(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 34 instructions
    /* 0x178c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x1790 */ stp x20, x19, [sp, #0x10];
    /* 0x1794 */ mov x29, sp;
    /* 0x1798 */ mov x1, x3;
    /* 0x179c */ mov x19, x0;
    /* 0x17a0 */ mov w3, #1;
    /* 0x17a4 */ mov x0, x2;
    /* 0x17a8 */ mov x2, x4;
    mremap();
    /* 0x17b0 */ cmn x0, #1;
    /* 0x17b4 */ b.ne #0x1808;
    __android_log_print();
    return x0;
}

// Library: libbuffer_pgl.so
// Function ID: libbuffer_pgl::0x1200
// Recovered Name: Java_com_bykv_vk_openvk_preload_geckox_buffer_impl_MMapBuffer_nRelease
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x1200 | Size: 12 bytes | SHA256: 16538c082942aeb235fe10dddc5795f454c2484ec451c5a6376ccc7be3a7dd59
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: munmap

jlong Java_com_bykv_vk_openvk_preload_geckox_buffer_impl_MMapBuffer_nRelease(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x1200 */ mov x1, x3;
    /* 0x1204 */ mov x0, x2;
    /* 0x1208 */ b #0x18e0;
}

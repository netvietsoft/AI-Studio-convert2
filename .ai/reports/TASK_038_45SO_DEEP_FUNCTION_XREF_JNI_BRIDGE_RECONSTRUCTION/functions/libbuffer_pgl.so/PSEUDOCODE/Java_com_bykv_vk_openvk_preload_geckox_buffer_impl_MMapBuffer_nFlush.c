// Function: Java_com_bykv_vk_openvk_preload_geckox_buffer_impl_MMapBuffer_nFlush
// RVA: 0x122c, Size: 132 bytes
int64_t Java_com_bykv_vk_openvk_preload_geckox_buffer_impl_MMapBuffer_nFlush(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    msync(...); // call PLT API at 0x1250
    const char* str = "java/io/IOException";
    (*x8)(...);
    __errno(...); // call PLT API at 0x1278
    strerror(...); // call PLT API at 0x1280
    (*x8)(...);
    return a0;
}

// Function: Java_com_bykv_vk_openvk_preload_geckox_buffer_impl_MReMapBuffer_nMReMap
// RVA: 0x178c, Size: 136 bytes
int64_t Java_com_bykv_vk_openvk_preload_geckox_buffer_impl_MReMapBuffer_nMReMap(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    mremap(...); // call PLT API at 0x17ac
    const char* str = "mremap failed";
    const char* str = "Buffer";
    __android_log_print(...); // call PLT API at 0x17d0
    const char* str = "java/io/IOException";
    (*x8)(...);
    (*x8)(...);
    return a0;
}

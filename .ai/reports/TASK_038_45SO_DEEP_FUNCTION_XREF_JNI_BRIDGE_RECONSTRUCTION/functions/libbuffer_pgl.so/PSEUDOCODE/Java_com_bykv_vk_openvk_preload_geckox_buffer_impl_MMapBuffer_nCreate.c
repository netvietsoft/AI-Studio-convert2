// Function: Java_com_bykv_vk_openvk_preload_geckox_buffer_impl_MMapBuffer_nCreate
// RVA: 0x1028, Size: 440 bytes
int64_t Java_com_bykv_vk_openvk_preload_geckox_buffer_impl_MMapBuffer_nCreate(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...);
    open(...); // call PLT API at 0x106c
    (*x8)(...);
    lseek(...); // call PLT API at 0x109c
    close(...); // call PLT API at 0x10bc
    const char* str = "java/io/IOException";
    (*x8)(...);
    const char* str = "inconsistent file length";
    ftruncate(...); // call PLT API at 0x10fc
    close(...); // call PLT API at 0x1108
    const char* str = "java/io/IOException";
    (*x8)(...);
    __errno(...); // call PLT API at 0x1128
    strerror(...); // call PLT API at 0x1130
    (*x8)(...);
    return a0;
    mmap(...); // call PLT API at 0x1180
    close(...); // call PLT API at 0x118c
    const char* str = "Buffer";
    const char* str = "mmap failed, %s";
    __android_log_print(...); // call PLT API at 0x11b0
    const char* str = "java/io/IOException";
    (*x8)(...);
    const char* str = "map failed";
}

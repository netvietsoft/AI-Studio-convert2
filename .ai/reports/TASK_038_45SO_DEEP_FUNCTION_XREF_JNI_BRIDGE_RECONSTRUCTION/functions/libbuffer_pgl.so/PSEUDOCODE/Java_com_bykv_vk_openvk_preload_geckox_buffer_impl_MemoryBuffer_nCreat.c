// Function: Java_com_bykv_vk_openvk_preload_geckox_buffer_impl_MemoryBuffer_nCreate
// RVA: 0x12b0, Size: 736 bytes
int64_t Java_com_bykv_vk_openvk_preload_geckox_buffer_impl_MemoryBuffer_nCreate(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...);
    open(...); // call PLT API at 0x12fc
    (*x8)(...);
    lseek(...); // call PLT API at 0x132c
    close(...); // call PLT API at 0x1350
    const char* str = "java/io/IOException";
    (*x8)(...);
    const char* str = "File lengths are inconsistent";
    const char* str = "java/io/IOException";
    (*x8)(...);
    const char* str = "length illegal";
    ftruncate(...); // call PLT API at 0x13b8
    close(...); // call PLT API at 0x13c4
    const char* str = "java/io/IOException";
    (*x8)(...);
    __errno(...); // call PLT API at 0x13e4
    strerror(...); // call PLT API at 0x13ec
    (*x8)(...);
    return a0;
    lseek(...); // call PLT API at 0x1430
    close(...); // call PLT API at 0x143c
    const char* str = "java/io/IOException";
    (*x8)(...);
    const char* str = "seek failed";
    calloc(...); // call PLT API at 0x1474
    __errno(...); // call PLT API at 0x148c
    __read_chk(...); // call PLT API at 0x14b0
    close(...); // call PLT API at 0x14d0
    free(...); // call PLT API at 0x14e0
    const char* str = "java/io/IOException";
    (*x8)(...);
    const char* str = "close failed";
    close(...); // call PLT API at 0x1514
    const char* str = "java/io/IOException";
    (*x8)(...);
    const char* str = "native calloc failed";
    (*x8)(...);
    close(...); // call PLT API at 0x1554
    free(...); // call PLT API at 0x1560
    const char* str = "java/io/IOException";
    (*x8)(...);
    const char* str = "read full failed";
}

// Function: Java_com_bykv_vk_openvk_preload_geckox_buffer_impl_MemoryBuffer_nFlush
// RVA: 0x165c, Size: 304 bytes
int64_t Java_com_bykv_vk_openvk_preload_geckox_buffer_impl_MemoryBuffer_nFlush(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...);
    open(...); // call PLT API at 0x16a4
    (*x8)(...);
    write(...); // call PLT API at 0x16d4
    close(...); // call PLT API at 0x16e0
    return a0;
    const char* str = "java/io/IOException";
    (*x8)(...);
    __errno(...); // call PLT API at 0x1724
    strerror(...); // call PLT API at 0x172c
    const char* str = "java/io/IOException";
    (*x8)(...);
    const char* str = "close file failed";
}

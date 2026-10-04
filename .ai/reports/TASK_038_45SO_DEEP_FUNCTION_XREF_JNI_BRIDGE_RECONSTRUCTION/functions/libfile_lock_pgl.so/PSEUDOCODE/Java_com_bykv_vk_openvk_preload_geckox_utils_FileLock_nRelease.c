// Function: Java_com_bykv_vk_openvk_preload_geckox_utils_FileLock_nRelease
// RVA: 0xdec, Size: 116 bytes
int64_t Java_com_bykv_vk_openvk_preload_geckox_utils_FileLock_nRelease(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    close(...); // call PLT API at 0xe00
    return a0;
    const char* str = "java/lang/RuntimeException";
    (*x8)(...);
    __errno(...); // call PLT API at 0xe34
    strerror(...); // call PLT API at 0xe3c
}

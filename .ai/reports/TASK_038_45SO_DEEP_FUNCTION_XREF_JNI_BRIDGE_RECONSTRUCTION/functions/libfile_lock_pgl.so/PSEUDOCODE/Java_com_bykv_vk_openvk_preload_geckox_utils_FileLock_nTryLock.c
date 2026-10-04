// Function: Java_com_bykv_vk_openvk_preload_geckox_utils_FileLock_nTryLock
// RVA: 0xbf0, Size: 108 bytes
int64_t Java_com_bykv_vk_openvk_preload_geckox_utils_FileLock_nTryLock(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    fcntl(...); // call PLT API at 0xc2c
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xc58
}

// Function: Java_com_bykv_vk_openvk_preload_geckox_utils_FileLock_nLockFile
// RVA: 0xa48, Size: 212 bytes
int64_t Java_com_bykv_vk_openvk_preload_geckox_utils_FileLock_nLockFile(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    fcntl(...); // call PLT API at 0xa90
    const char* str = "FileLock";
    const char* str = "Lock Failed:type = %d
";
    __android_log_print(...); // call PLT API at 0xab0
    const char* str = "java/lang/RuntimeException";
    (*x8)(...);
    __errno(...); // call PLT API at 0xad0
    strerror(...); // call PLT API at 0xad8
    (*x8)(...);
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xb18
}

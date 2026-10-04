// Function: Java_com_bykv_vk_openvk_preload_geckox_utils_FileLock_nLockFileSegment
// RVA: 0xc5c, Size: 216 bytes
int64_t Java_com_bykv_vk_openvk_preload_geckox_utils_FileLock_nLockFileSegment(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    fcntl(...); // call PLT API at 0xca8
    const char* str = "FileLock";
    const char* str = "Lock Failed:type = %d
";
    __android_log_print(...); // call PLT API at 0xcc8
    const char* str = "java/lang/RuntimeException";
    (*x8)(...);
    __errno(...); // call PLT API at 0xce8
    strerror(...); // call PLT API at 0xcf0
    (*x8)(...);
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xd30
}

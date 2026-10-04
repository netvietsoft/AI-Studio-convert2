// Function: Java_com_bykv_vk_openvk_preload_geckox_utils_FileLock_nGetFD
// RVA: 0xd34, Size: 184 bytes
int64_t Java_com_bykv_vk_openvk_preload_geckox_utils_FileLock_nGetFD(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...);
    open(...); // call PLT API at 0xd70
    (*x8)(...);
    const char* str = "java/lang/RuntimeException";
    (*x8)(...);
    __errno(...); // call PLT API at 0xdb0
    strerror(...); // call PLT API at 0xdb8
    (*x8)(...);
    return a0;
}

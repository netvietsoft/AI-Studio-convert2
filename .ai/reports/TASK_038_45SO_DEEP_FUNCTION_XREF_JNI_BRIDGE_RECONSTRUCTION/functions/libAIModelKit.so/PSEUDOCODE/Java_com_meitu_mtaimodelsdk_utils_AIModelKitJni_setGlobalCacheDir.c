// Function: Java_com_meitu_mtaimodelsdk_utils_AIModelKitJni_setGlobalCacheDir
// RVA: 0x1bc14, Size: 212 bytes
int64_t Java_com_meitu_mtaimodelsdk_utils_AIModelKitJni_setGlobalCacheDir(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _Z17loadLibraryHandlev(...); // call PLT API at 0x1bc30
    const char* str = "SetGlobalCacheDir";
    dlsym(...); // call PLT API at 0x1bc40
    (*x8)(...);
    (*x22)(...);
    (*x8)(...);
    dlerror(...); // call PLT API at 0x1bc98
    const char* str = "AIModelKitJni";
    const char* str = "Failed to find SetGlobalCacheDir: %s";
    __android_log_print(...); // call PLT API at 0x1bcb4
    const char* str = "AIModelKitJni";
    const char* str = "Invalid cache path";
    __android_log_print(...); // call PLT API at 0x1bcd0
    return a0;
}

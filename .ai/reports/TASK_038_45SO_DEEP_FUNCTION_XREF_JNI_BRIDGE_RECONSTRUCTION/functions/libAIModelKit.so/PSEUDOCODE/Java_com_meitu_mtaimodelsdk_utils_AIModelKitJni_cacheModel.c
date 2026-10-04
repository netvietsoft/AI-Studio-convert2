// Function: Java_com_meitu_mtaimodelsdk_utils_AIModelKitJni_cacheModel
// RVA: 0x1bdfc, Size: 276 bytes
int64_t Java_com_meitu_mtaimodelsdk_utils_AIModelKitJni_cacheModel(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _Z17loadLibraryHandlev(...); // call PLT API at 0x1be28
    const char* str = "CacheModel";
    dlsym(...); // call PLT API at 0x1be38
    (*x8)(...);
    (*x8)(...);
    (*x24)(...);
    (*x8)(...);
    dlerror(...); // call PLT API at 0x1beb8
    const char* str = "AIModelKitJni";
    const char* str = "Failed to find CacheModel: %s";
    __android_log_print(...); // call PLT API at 0x1bed4
    const char* str = "AIModelKitJni";
    const char* str = "Failed to get model data from jbyteArray";
    __android_log_print(...); // call PLT API at 0x1bef0
    return a0;
}

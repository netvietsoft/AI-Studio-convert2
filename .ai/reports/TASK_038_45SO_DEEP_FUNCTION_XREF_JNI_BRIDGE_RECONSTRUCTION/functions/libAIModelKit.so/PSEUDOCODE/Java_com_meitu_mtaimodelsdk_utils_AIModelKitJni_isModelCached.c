// Function: Java_com_meitu_mtaimodelsdk_utils_AIModelKitJni_isModelCached
// RVA: 0x1bce8, Size: 276 bytes
int64_t Java_com_meitu_mtaimodelsdk_utils_AIModelKitJni_isModelCached(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _Z17loadLibraryHandlev(...); // call PLT API at 0x1bd14
    const char* str = "IsModelCached";
    dlsym(...); // call PLT API at 0x1bd24
    (*x8)(...);
    (*x8)(...);
    (*x24)(...);
    (*x8)(...);
    dlerror(...); // call PLT API at 0x1bda4
    const char* str = "AIModelKitJni";
    const char* str = "Failed to find IsModelCached: %s";
    __android_log_print(...); // call PLT API at 0x1bdc0
    const char* str = "AIModelKitJni";
    const char* str = "Failed to get model data from jbyteArray";
    __android_log_print(...); // call PLT API at 0x1bddc
    return a0;
}

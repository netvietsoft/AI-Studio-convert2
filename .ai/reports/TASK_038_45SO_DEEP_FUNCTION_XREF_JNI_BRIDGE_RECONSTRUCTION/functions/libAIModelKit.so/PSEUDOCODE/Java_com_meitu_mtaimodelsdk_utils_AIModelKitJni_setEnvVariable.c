// Function: Java_com_meitu_mtaimodelsdk_utils_AIModelKitJni_setEnvVariable
// RVA: 0x1bb34, Size: 224 bytes
int64_t Java_com_meitu_mtaimodelsdk_utils_AIModelKitJni_setEnvVariable(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _Z17loadLibraryHandlev(...); // call PLT API at 0x1bb54
    const char* str = "SetEnvVariable";
    dlsym(...); // call PLT API at 0x1bb64
    (*x8)(...);
    (*x22)(...);
    (*x8)(...);
    dlerror(...); // call PLT API at 0x1bbc0
    const char* str = "AIModelKitJni";
    const char* str = "Failed to find SetEnvVariable: %s";
    __android_log_print(...); // call PLT API at 0x1bbdc
    const char* str = "AIModelKitJni";
    const char* str = "Invalid cache path";
    __android_log_print(...); // call PLT API at 0x1bbf8
    return a0;
}

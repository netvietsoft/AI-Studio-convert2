// Function: ensureManisDeviceInfoLoaded()
// RVA: 0x1ba24, Size: 272 bytes
int64_t _Z27ensureManisDeviceInfoLoadedv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    return a0;
    _Z17loadLibraryHandlev(...); // call imported API via PLT at 0x1ba6c
    const char* s_fc5e = "ManisGetDeviceInfo"; // string xref
    dlsym(...); // call imported API via PLT at 0x1ba7c
    (*x8)(...); // indirect call at 0x1ba90
    _Z20parseManisDeviceInfoPKci(...); // call imported API via PLT at 0x1ba9c
    const char* s_10466 = "AIModelKitJni"; // string xref
    const char* s_1172e = "Failed to load libManis.so"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1bad4
    dlerror(...); // call imported API via PLT at 0x1bad8
    const char* s_10466 = "AIModelKitJni"; // string xref
    const char* s_101e4 = "Failed to find ManisGetDeviceInfo: %s"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1bb10
    const char* s_10466 = "AIModelKitJni"; // string xref
    const char* s_fe8a = "ManisGetDeviceInfo returned nullptr"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1bb28
    __stack_chk_fail(...); // call imported API via PLT at 0x1bb30
}

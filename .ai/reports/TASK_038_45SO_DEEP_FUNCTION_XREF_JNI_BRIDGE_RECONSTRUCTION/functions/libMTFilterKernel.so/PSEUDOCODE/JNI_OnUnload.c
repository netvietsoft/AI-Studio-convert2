// Function: JNI_OnUnload
// RVA: 0xc3c24, Size: 176 bytes
int64_t JNI_OnUnload(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0xc3c44
    const char* str = "FilterKernel";
    const char* str = "JNI_OnUnload libmtfilterkernel.so dettach from system!";
    __android_log_print(...); // call PLT API at 0xc3c64
    (*x8)(...);
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0xc3c8c
    const char* str = "FilterKernel";
    const char* str = "JNI_OnUnload error: failed to getEnv!";
    __android_log_print(...); // call PLT API at 0xc3cac
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xc3cd0
}

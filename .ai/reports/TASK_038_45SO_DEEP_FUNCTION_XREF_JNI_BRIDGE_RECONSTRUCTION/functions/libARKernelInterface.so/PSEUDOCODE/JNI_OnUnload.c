// Function: JNI_OnUnload
// RVA: 0x58efa4, Size: 196 bytes
int64_t JNI_OnUnload(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "arkernel";
    const char* str = "JNI_OnUnload libARKernelInterface.so dettach from system!";
    __android_log_print(...); // call PLT API at 0x58eff0
    sub_5A79A8(...); // call internal at 0x58eff8
    (*x8)(...);
    const char* str = "arkernel";
    const char* str = "JNI_OnUnload error: failed to getEnv!";
    __android_log_print(...); // call PLT API at 0x58f03c
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x58f064
}

// Function: JNI_OnUnload
// RVA: 0x9c3f8, Size: 156 bytes
int64_t JNI_OnUnload(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "mtlabar3";
    const char* str = "JNI_OnUnload libarkernel3.so detached from system!";
    __android_log_print(...); // call PLT API at 0x9c42c
    _ZN8mtlabar39JniHelper26releaseCacheGLXBitmapClassEv(...); // call PLT API at 0x9c434
    (*x8)(...);
    const char* str = "mtlabar3";
    const char* str = "JNI_OnUnload error: failed to getEnv!";
    __android_log_print(...); // call PLT API at 0x9c46c
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x9c490
}

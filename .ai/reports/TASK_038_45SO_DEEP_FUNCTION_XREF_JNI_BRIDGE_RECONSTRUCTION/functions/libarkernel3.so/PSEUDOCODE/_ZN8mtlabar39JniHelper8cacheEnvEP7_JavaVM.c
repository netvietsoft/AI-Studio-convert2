// Function: mtlabar3::JniHelper::cacheEnv(_JavaVM*)
// RVA: 0xb6708c, Size: 244 bytes
int64_t _ZN8mtlabar39JniHelper8cacheEnvEP7_JavaVM(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...);
    (*x8)(...);
    pthread_setspecific(...); // call PLT API at 0xb67108
    const char* str = "mtlabar3";
    const char* str = "JNI interface version 1.4 not supported";
    __android_log_print(...); // call PLT API at 0xb67128
    const char* str = "mtlabar3";
    const char* str = "Failed to get the environment using GetEnv()";
    __android_log_print(...); // call PLT API at 0xb67140
    return a0;
    const char* str = "mtlabar3";
    const char* str = "Failed to get the environment using AttachCurrentThread()";
    __stack_chk_fail(...); // call PLT API at 0xb6717c
}

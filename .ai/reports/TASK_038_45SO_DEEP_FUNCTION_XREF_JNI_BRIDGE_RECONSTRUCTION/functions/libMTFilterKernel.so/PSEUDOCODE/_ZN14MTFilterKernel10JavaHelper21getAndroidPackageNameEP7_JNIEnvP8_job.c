// Function: MTFilterKernel::JavaHelper::getAndroidPackageName(_JNIEnv*, _jobject*, _jobject*)
// RVA: 0xc0ffc, Size: 232 bytes
int64_t _ZN14MTFilterKernel10JavaHelper21getAndroidPackageNameEP7_JNIEnvP8_jobjectS4_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "android/content/Context";
    (*x8)(...);
    const char* str = "getPackageName";
    const char* str = "()Ljava/lang/String;";
    (*x8)(...);
    _ZN7_JNIEnv16CallObjectMethodEP8_jobjectP10_jmethodIDz(...); // call internal at 0xc1064
    (*x8)(...);
    strlen(...); // call PLT API at 0xc108c
    _Znam(...); // call PLT API at 0xc1094
    strcpy(...); // call PLT API at 0xc10a0
    strlen(...); // call PLT API at 0xc10a8
    (*x8)(...);
    return a0;
    return a0;
}

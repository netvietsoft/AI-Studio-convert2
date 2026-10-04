// Function: MTFilterKernel::JavaHelper::getAndroidAPKPath(_JNIEnv*, _jobject*, _jobject*)
// RVA: 0xc10e4, Size: 516 bytes
int64_t _ZN14MTFilterKernel10JavaHelper17getAndroidAPKPathEP7_JNIEnvP8_jobjectS4_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "android/content/Context";
    (*x8)(...);
    const char* str = "getPackageName";
    const char* str = "()Ljava/lang/String;";
    (*x8)(...);
    const char* str = "getPackageManager";
    const char* str = "()Landroid/content/pm/PackageManager;";
    (*x8)(...);
    _ZN7_JNIEnv16CallObjectMethodEP8_jobjectP10_jmethodIDz(...); // call internal at 0xc1184
    _ZN7_JNIEnv16CallObjectMethodEP8_jobjectP10_jmethodIDz(...); // call internal at 0xc119c
    const char* str = "android/content/pm/PackageManager";
    (*x8)(...);
    const char* str = "getApplicationInfo";
    const char* str = "(Ljava/lang/String;I)Landroid/content/pm/ApplicationInfo;";
    (*x8)(...);
    _ZN7_JNIEnv16CallObjectMethodEP8_jobjectP10_jmethodIDz(...); // call internal at 0xc1200
    const char* str = "android/content/pm/ApplicationInfo";
    (*x8)(...);
    const char* str = "sourceDir";
    const char* str = "Ljava/lang/String;";
    (*x8)(...);
    (*x8)(...);
    (*x8)(...);
    strlen(...); // call PLT API at 0xc128c
    _Znam(...); // call PLT API at 0xc1294
    strcpy(...); // call PLT API at 0xc12a0
    strlen(...); // call PLT API at 0xc12a8
    (*x8)(...);
    return a0;
    return a0;
}

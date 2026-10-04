// Function: MTFilterKernel::JavaHelper::getAndroidAPKKeyHash(_JNIEnv*, _jobject*, _jobject*)
// RVA: 0xc19b0, Size: 1088 bytes
int64_t _ZN14MTFilterKernel10JavaHelper20getAndroidAPKKeyHashEP7_JNIEnvP8_jobjectS4_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "android/content/Context";
    (*x8)(...);
    const char* str = "getPackageName";
    const char* str = "()Ljava/lang/String;";
    (*x8)(...);
    const char* str = "getPackageManager";
    const char* str = "()Landroid/content/pm/PackageManager;";
    (*x8)(...);
    _ZN7_JNIEnv16CallObjectMethodEP8_jobjectP10_jmethodIDz(...); // call internal at 0xc1a58
    _ZN7_JNIEnv16CallObjectMethodEP8_jobjectP10_jmethodIDz(...); // call internal at 0xc1a70
    const char* str = "android/content/pm/PackageManager";
    (*x8)(...);
    const char* str = "GET_SIGNATURES";
    (*x8)(...);
    (*x8)(...);
    const char* str = "getPackageInfo";
    const char* str = "(Ljava/lang/String;I)Landroid/content/pm/PackageInfo;";
    (*x8)(...);
    _ZN7_JNIEnv16CallObjectMethodEP8_jobjectP10_jmethodIDz(...); // call internal at 0xc1b18
    const char* str = "android/content/pm/PackageInfo";
    (*x8)(...);
    const char* str = "signatures";
    const char* str = "[Landroid/content/pm/Signature;";
    (*x8)(...);
    (*x8)(...);
    const char* str = "java/security/MessageDigest";
    (*x8)(...);
    const char* str = "getInstance";
    const char* str = "(Ljava/lang/String;)Ljava/security/MessageDigest;";
    (*x8)(...);
    const char* str = "update";
    const char* str = "([B)V";
    (*x8)(...);
    const char* str = "digest";
    const char* str = "()[B";
    (*x8)(...);
    const char* str = "android/content/pm/Signature";
    (*x8)(...);
    const char* str = "toByteArray";
    const char* str = "()[B";
    (*x8)(...);
    const char* str = "android/util/Base64";
    (*x8)(...);
    const char* str = "encodeToString";
    const char* str = "([BI)Ljava/lang/String;";
    (*x9)(...);
    (*x8)(...);
    const char* str = "SHA";
    (*x8)(...);
    _ZN7_JNIEnv22CallStaticObjectMethodEP7_jclassP10_jmethodIDz(...); // call internal at 0xc1d0c
    _ZN7_JNIEnv16CallObjectMethodEP8_jobjectP10_jmethodIDz(...); // call internal at 0xc1d20
    _ZN7_JNIEnv14CallVoidMethodEP8_jobjectP10_jmethodIDz(...); // call internal at 0xc1d38
    _ZN7_JNIEnv16CallObjectMethodEP8_jobjectP10_jmethodIDz(...); // call internal at 0xc1d48
    _ZN7_JNIEnv22CallStaticObjectMethodEP7_jclassP10_jmethodIDz(...); // call internal at 0xc1d64
    (*x8)(...);
    strlen(...); // call PLT API at 0xc1d8c
    _Znam(...); // call PLT API at 0xc1d94
    strcpy(...); // call PLT API at 0xc1da0
    strlen(...); // call PLT API at 0xc1da8
    (*x8)(...);
    return a0;
    return a0;
}

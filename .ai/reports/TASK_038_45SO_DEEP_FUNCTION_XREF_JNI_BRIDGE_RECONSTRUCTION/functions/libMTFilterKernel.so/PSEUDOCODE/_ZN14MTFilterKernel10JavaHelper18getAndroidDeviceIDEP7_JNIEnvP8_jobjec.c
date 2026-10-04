// Function: MTFilterKernel::JavaHelper::getAndroidDeviceID(_JNIEnv*, _jobject*, _jobject*, char**)
// RVA: 0xc0dbc, Size: 420 bytes
int64_t _ZN14MTFilterKernel10JavaHelper18getAndroidDeviceIDEP7_JNIEnvP8_jobjectS4_PPc(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "android/content/Context";
    (*x8)(...);
    const char* str = "getSystemService";
    const char* str = "(Ljava/lang/String;)Ljava/lang/Object;";
    (*x8)(...);
    const char* str = "TELEPHONY_SERVICE";
    const char* str = "Ljava/lang/String;";
    (*x8)(...);
    (*x8)(...);
    _ZN7_JNIEnv16CallObjectMethodEP8_jobjectP10_jmethodIDz(...); // call internal at 0xc0e78
    const char* str = "android/telephony/TelephonyManager";
    (*x8)(...);
    const char* str = "getDeviceId";
    const char* str = "()Ljava/lang/String;";
    (*x8)(...);
    _ZN7_JNIEnv16CallObjectMethodEP8_jobjectP10_jmethodIDz(...); // call internal at 0xc0ed4
    (*x8)(...);
    strlen(...); // call PLT API at 0xc0ef8
    _Znam(...); // call PLT API at 0xc0f00
    strcpy(...); // call PLT API at 0xc0f0c
    (*x8)(...);
    return a0;
    return a0;
    return a0;
}

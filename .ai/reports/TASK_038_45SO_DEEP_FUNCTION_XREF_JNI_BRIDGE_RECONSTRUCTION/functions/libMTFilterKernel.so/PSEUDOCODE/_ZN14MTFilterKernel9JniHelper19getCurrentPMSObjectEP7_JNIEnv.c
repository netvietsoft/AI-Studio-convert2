// Function: MTFilterKernel::JniHelper::getCurrentPMSObject(_JNIEnv*)
// RVA: 0xc2da0, Size: 428 bytes
int64_t _ZN14MTFilterKernel9JniHelper19getCurrentPMSObjectEP7_JNIEnv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "android/app/ActivityThread";
    (*x8)(...);
    const char* str = "currentActivityThread";
    const char* str = "()Landroid/app/ActivityThread;";
    (*x8)(...);
    _ZN7_JNIEnv22CallStaticObjectMethodEP7_jclassP10_jmethodIDz(...); // call internal at 0xc2e04
    const char* str = "sPackageManager";
    const char* str = "Landroid/content/pm/IPackageManager;";
    (*x8)(...);
    (*x8)(...);
    (*x8)(...);
    (*x8)(...);
    return a0;
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0xc2e94
    const char* str = "FilterKernel";
    const char* str = "siglib: find class android/app/ActivityThread return null";
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0xc2eb4
    const char* str = "FilterKernel";
    const char* str = "siglib: GetStaticMethodID currentActivityThread return null";
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0xc2ed4
    const char* str = "FilterKernel";
    const char* str = "siglib: CallStaticObjectMethod return null";
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0xc2ef4
    const char* str = "FilterKernel";
    const char* str = "siglib: GetStaticFieldID sPackageManager return null";
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0xc2f14
    const char* str = "FilterKernel";
    const char* str = "siglib: GetStaticObjectField sPackageManager return null";
    __android_log_print(...); // call PLT API at 0xc2f34
    return a0;
}

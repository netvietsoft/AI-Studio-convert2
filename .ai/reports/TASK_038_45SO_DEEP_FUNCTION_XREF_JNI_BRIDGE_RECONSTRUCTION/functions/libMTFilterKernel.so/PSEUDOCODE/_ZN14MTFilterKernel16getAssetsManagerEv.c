// Function: MTFilterKernel::getAssetsManager()
// RVA: 0xc31ac, Size: 268 bytes
int64_t _ZN14MTFilterKernel16getAssetsManagerEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "com/meitu/core/MTFilterKernelConfigJNI";
    const char* str = "getAssetManager";
    const char* str = "()Landroid/content/res/AssetManager;";
    _ZN14MTFilterKernel9JniHelper19getStaticMethodInfoERNS_14JniMethodInfo_EPKcS4_S4_(...); // call internal at 0xc31e8
    _ZN7_JNIEnv22CallStaticObjectMethodEP7_jclassP10_jmethodIDz(...); // call internal at 0xc31f4
    (*x8)(...);
    AAssetManager_fromJava(...); // call PLT API at 0xc3218
    (*x9)(...);
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0xc3240
    const char* str = "FilterKernel";
    const char* str = "AAssetManager: failed to access assetmanager from java";
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0xc3260
    const char* str = "FilterKernel";
    const char* str = "AAssetManager: failed to get assetmanager from context";
    __android_log_print(...); // call PLT API at 0xc3280
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xc32b4
}

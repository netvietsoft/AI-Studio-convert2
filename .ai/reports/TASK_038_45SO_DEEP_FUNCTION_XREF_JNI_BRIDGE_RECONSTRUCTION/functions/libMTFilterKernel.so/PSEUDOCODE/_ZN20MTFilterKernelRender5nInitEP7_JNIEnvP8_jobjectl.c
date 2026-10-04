// Function: MTFilterKernelRender::nInit(_JNIEnv*, _jobject*, long)
// RVA: 0xbfd40, Size: 88 bytes
int64_t _ZN20MTFilterKernelRender5nInitEP7_JNIEnvP8_jobjectl(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "FilterKernel_jni";
    const char* str = "init begin.";
    __android_log_print(...); // call PLT API at 0xbfd6c
    _ZN14MTFilterKernel32MTlabFilterKernelRenderInterface4initEv(...); // call internal at 0xbfd74
    const char* str = "init end.";
    __android_log_print(...); // call PLT API at 0xbfd90
    return a0;
}

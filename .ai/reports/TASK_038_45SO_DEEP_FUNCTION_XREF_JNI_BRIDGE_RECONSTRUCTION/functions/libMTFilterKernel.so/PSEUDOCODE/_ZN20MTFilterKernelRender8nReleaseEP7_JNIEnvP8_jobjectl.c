// Function: MTFilterKernelRender::nRelease(_JNIEnv*, _jobject*, long)
// RVA: 0xbfd98, Size: 88 bytes
int64_t _ZN20MTFilterKernelRender8nReleaseEP7_JNIEnvP8_jobjectl(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "FilterKernel_jni";
    const char* str = "release begin.";
    __android_log_print(...); // call PLT API at 0xbfdc4
    _ZN14MTFilterKernel32MTlabFilterKernelRenderInterface7releaseEv(...); // call internal at 0xbfdcc
    const char* str = "release end.";
    __android_log_print(...); // call PLT API at 0xbfde8
    return a0;
}

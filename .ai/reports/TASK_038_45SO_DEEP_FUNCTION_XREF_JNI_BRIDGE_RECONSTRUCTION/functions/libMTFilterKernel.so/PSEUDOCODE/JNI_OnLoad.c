// Function: JNI_OnLoad
// RVA: 0xc3adc, Size: 328 bytes
int64_t JNI_OnLoad(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0xc3b04
    const char* str = "FilterKernel";
    const char* str = "JNI_OnLoad libmtfilterkernel.so attach to system!";
    __android_log_print(...); // call PLT API at 0xc3b24
    (*x8)(...);
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0xc3b54
    const char* str = "FilterKernel";
    const char* str = "JNI_OnLoad error: failed to getEnv!";
    __android_log_print(...); // call PLT API at 0xc3b74
    return a0;
    _Z35registerMTFilterKernelRenderMethodsP7_JNIEnvPv(...); // call internal at 0xc3bac
    _Z23registerFaceDataMethodsP7_JNIEnvPv(...); // call internal at 0xc3bbc
    _ZN14MTFilterKernel9JniHelper9setJavaVMEP7_JavaVM(...); // call internal at 0xc3bc8
    _ZN14MTFilterKernel9JniHelper6getEnvEv(...); // call internal at 0xc3bcc
    __stack_chk_fail(...); // call PLT API at 0xc3be0
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0xc3be4
    const char* str = "FilterKernel";
    const char* str = "registerMTFilterKernelRenderMethods error";
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0xc3c04
    const char* str = "FilterKernel";
    const char* str = "registerFaceDataMethods error";
}

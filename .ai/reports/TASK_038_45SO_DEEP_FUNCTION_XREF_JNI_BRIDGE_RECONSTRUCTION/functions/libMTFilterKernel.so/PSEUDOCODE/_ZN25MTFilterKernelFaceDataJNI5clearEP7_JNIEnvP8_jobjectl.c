// Function: MTFilterKernelFaceDataJNI::clear(_JNIEnv*, _jobject*, long)
// RVA: 0xbfacc, Size: 76 bytes
int64_t _ZN25MTFilterKernelFaceDataJNI5clearEP7_JNIEnvP8_jobjectl(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    memset(...); // call PLT API at 0xbfae0
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0xbfaec
    const char* str = "FilterKernel";
    const char* str = "ERROR: MTFilterKernel::FilterkernelNativeFace clear,faceData object is NULL";
    __android_log_print(...); // call PLT API at 0xbfb10
    return a0;
}

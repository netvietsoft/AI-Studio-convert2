// Function: MTFilterKernelFaceDataJNI::setHasGlasses(_JNIEnv*, _jobject*, long, int, int)
// RVA: 0xbfa58, Size: 116 bytes
int64_t _ZN25MTFilterKernelFaceDataJNI13setHasGlassesEP7_JNIEnvP8_jobjectlii(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0xbfa90
    const char* str = "FilterKernel";
    const char* str = "ERROR: MTFilterKernel::FilterkernelNativeFace setHasGlasses, faceData object is NULL or face index == %d out range";
    __android_log_print(...); // call PLT API at 0xbfabc
    return a0;
}

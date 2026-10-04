// Function: MTFilterKernelFaceDataJNI::setGender(_JNIEnv*, _jobject*, long, int, int)
// RVA: 0xbf884, Size: 120 bytes
int64_t _ZN25MTFilterKernelFaceDataJNI9setGenderEP7_JNIEnvP8_jobjectlii(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0xbf8c0
    const char* str = "FilterKernel";
    const char* str = "ERROR: MTFilterKernel::FilterkernelNativeFace setGender, faceData object is NULL or face index == %d out range";
    __android_log_print(...); // call PLT API at 0xbf8ec
    return a0;
}

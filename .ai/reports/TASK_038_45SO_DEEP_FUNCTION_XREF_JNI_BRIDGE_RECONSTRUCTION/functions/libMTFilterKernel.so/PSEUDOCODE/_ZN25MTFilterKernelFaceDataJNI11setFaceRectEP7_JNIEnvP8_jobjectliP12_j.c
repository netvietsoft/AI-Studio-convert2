// Function: MTFilterKernelFaceDataJNI::setFaceRect(_JNIEnv*, _jobject*, long, int, _jfloatArray*)
// RVA: 0xbed30, Size: 196 bytes
int64_t _ZN25MTFilterKernelFaceDataJNI11setFaceRectEP7_JNIEnvP8_jobjectliP12_jfloatArray(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...);
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0xbedb0
    const char* str = "FilterKernel";
    const char* str = "ERROR: MTFilterKernel::FilterkernelNativeFace setFaceRect, faceData object is NULL or face index == %d out range";
    __android_log_print(...); // call PLT API at 0xbede0
    return a0;
}

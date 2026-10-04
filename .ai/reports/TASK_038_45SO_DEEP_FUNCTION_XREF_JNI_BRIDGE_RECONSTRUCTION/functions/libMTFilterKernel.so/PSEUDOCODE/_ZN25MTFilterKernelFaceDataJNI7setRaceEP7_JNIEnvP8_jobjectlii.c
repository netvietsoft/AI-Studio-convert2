// Function: MTFilterKernelFaceDataJNI::setRace(_JNIEnv*, _jobject*, long, int, int)
// RVA: 0xbf80c, Size: 120 bytes
int64_t _ZN25MTFilterKernelFaceDataJNI7setRaceEP7_JNIEnvP8_jobjectlii(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0xbf848
    const char* str = "FilterKernel";
    const char* str = "ERROR: MTFilterKernel::FilterkernelNativeFace setRace, faceData object is NULL or face index == %d out range";
    __android_log_print(...); // call PLT API at 0xbf874
    return a0;
}

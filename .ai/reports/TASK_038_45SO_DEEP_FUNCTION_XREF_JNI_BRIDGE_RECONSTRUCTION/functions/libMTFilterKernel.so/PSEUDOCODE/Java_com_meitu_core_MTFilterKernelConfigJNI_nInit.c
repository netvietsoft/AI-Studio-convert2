// Function: Java_com_meitu_core_MTFilterKernelConfigJNI_nInit
// RVA: 0xc3cd4, Size: 100 bytes
int64_t Java_com_meitu_core_MTFilterKernelConfigJNI_nInit(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    AAssetManager_fromJava(...); // call PLT API at 0xc3ce8
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0xc3cf4
    const char* str = "FilterKernel";
    const char* str = "failed to access assetmanager from java";
    __android_log_print(...); // call PLT API at 0xc3d1c
    _ZN14MTFilterKernel16setAssetsManagerEP13AAssetManager(...); // call internal at 0xc3d24
    return a0;
}

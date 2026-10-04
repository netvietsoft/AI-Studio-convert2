// Function: MTFilterKernel::GLUtils::LoadImage_Memory(unsigned char*, long, int*, int*)
// RVA: 0x142844, Size: 1032 bytes
int64_t _ZN14MTFilterKernel7GLUtils16LoadImage_MemoryEPhlPiS2_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_146F64(...); // call internal at 0x1428b8
    malloc(...); // call PLT API at 0x1428e0
    free(...); // call PLT API at 0x14293c
    __emutls_get_address(...); // call PLT API at 0x14294c
    const char* str = "outofmem";
    __emutls_get_address(...); // call PLT API at 0x142970
    __emutls_get_address(...); // call PLT API at 0x142984
    __memcpy_chk(...); // call PLT API at 0x1429f0
    memcpy(...); // call PLT API at 0x142a00
    memcpy(...); // call PLT API at 0x142a10
    const char* str = "com/meitu/core/MTFilterKernelRender";
    const char* str = "createFromByteBuffer";
    const char* str = "([B)Landroid/graphics/Bitmap;";
    _ZN14MTFilterKernel9JniHelper19getStaticMethodInfoERNS_14JniMethodInfo_EPKcS4_S4_(...); // call internal at 0x142a60
    (*x8)(...);
    (*x9)(...);
    _ZN7_JNIEnv22CallStaticObjectMethodEP7_jclassP10_jmethodIDz(...); // call internal at 0x142ab0
    (*x9)(...);
    (*x8)(...);
    AndroidBitmap_getInfo(...); // call PLT API at 0x142af0
    AndroidBitmap_lockPixels(...); // call PLT API at 0x142b18
    _Znam(...); // call PLT API at 0x142b2c
    memcpy(...); // call PLT API at 0x142b3c
    AndroidBitmap_unlockPixels(...); // call PLT API at 0x142b48
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x142b50
    const char* str = "FilterKernel";
    const char* str = "GLUtils::DecodeImageFromMemory failed to get method info";
    __android_log_print(...); // call PLT API at 0x142b70
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x142c48
}

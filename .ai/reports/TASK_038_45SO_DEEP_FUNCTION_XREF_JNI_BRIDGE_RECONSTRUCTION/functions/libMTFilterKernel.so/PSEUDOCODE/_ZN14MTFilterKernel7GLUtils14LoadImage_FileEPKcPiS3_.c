// Function: MTFilterKernel::GLUtils::LoadImage_File(char const*, int*, int*)
// RVA: 0x142cfc, Size: 432 bytes
int64_t _ZN14MTFilterKernel7GLUtils14LoadImage_FileEPKcPiS3_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel32PublicByAndroidTools_file2stringEPKcPl(...); // call internal at 0x142d4c
    _ZN14MTFilterKernel23commonTools_file2stringEPKcPl(...); // call internal at 0x142d6c
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x142dac
    const char* str = "FilterKernel";
    const char* str = "open failed: filePath = %s;";
    __android_log_print(...); // call PLT API at 0x142dd0
    _ZN14MTFilterKernel7GLUtils16LoadImage_MemoryEPhlPiS2_(...); // call internal at 0x142dec
    _ZN14MTFilterKernel9CCryptLib9SelfCryptEPhi(...); // call internal at 0x142dfc
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x142e00
    const char* str = "FilterKernel";
    const char* str = "GLUtils::LoadImage_File : LoadImage_Memory failed: memoryData = %p, try to CCryptLib::SelfCrypt";
    __android_log_print(...); // call PLT API at 0x142e24
    _ZN14MTFilterKernel7GLUtils16LoadImage_MemoryEPhlPiS2_(...); // call internal at 0x142e38
    _ZdaPv(...); // call PLT API at 0x142e44
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x142e50
    const char* str = "FilterKernel";
    const char* str = "file2string failed: filePath = %s";
    __android_log_print(...); // call PLT API at 0x142e74
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x142ea8
}

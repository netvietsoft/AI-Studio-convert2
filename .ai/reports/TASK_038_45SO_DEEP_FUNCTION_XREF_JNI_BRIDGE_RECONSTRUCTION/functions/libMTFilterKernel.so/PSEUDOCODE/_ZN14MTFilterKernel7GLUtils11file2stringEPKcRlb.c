// Function: MTFilterKernel::GLUtils::file2string(char const*, long&, bool)
// RVA: 0x142eac, Size: 208 bytes
int64_t _ZN14MTFilterKernel7GLUtils11file2stringEPKcRlb(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel32PublicByAndroidTools_file2stringEPKcPl(...); // call internal at 0x142eec
    _ZN14MTFilterKernel23commonTools_file2stringEPKcPl(...); // call internal at 0x142f08
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x142f20
    const char* str = "FilterKernel";
    const char* str = "open failed: filePath = %s;";
    __android_log_print(...); // call PLT API at 0x142f4c
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x142f78
}

// Function: MTFilterKernel::MTlabFilterKernelRender::loadFilterConfig(char const*)
// RVA: 0x1a75c8, Size: 892 bytes
int64_t _ZN14MTFilterKernel23MTlabFilterKernelRender16loadFilterConfigEPKc(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel7GLUtils12getIsHookPMSEv(...); // call internal at 0x1a7608
    const char* str = "ARKernel/ar_ishook/filterConfig.plist";
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x1a761c
    const char* str = "FilterKernel";
    const char* str = "MTlabFilterKernelRender: %p, loadFilterConfig configPath: %s;";
    __android_log_print(...); // call PLT API at 0x1a7644
    pthread_mutex_lock(...); // call PLT API at 0x1a764c
    (*x8)(...);
    (*x8)(...);
    _ZN14MTFilterKernel12GlobalConfig15resetParametersEv(...); // call internal at 0x1a76f8
    _ZN14MTFilterKernel23MTlabFilterKernelRender11loadFiltersEPKcRNSt6__ndk16vectorIPNS_12MTFilterBaseENS3_9allocatorIS6_EEEEb(...); // call internal at 0x1a770c
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc(...); // call PLT API at 0x1a772c
    strlen(...); // call PLT API at 0x1a7768
    _ZdlPv(...); // call PLT API at 0x1a779c
    _ZdlPv(...); // call PLT API at 0x1a77bc
    _ZdlPv(...); // call PLT API at 0x1a77cc
    (*x8)(...);
    (*x8)(...);
    _Znwm(...); // call PLT API at 0x1a7870
    memcpy(...); // call PLT API at 0x1a7890
    _ZN14MTFilterKernel23MTlabFilterKernelRender18addPlistFilterInfoERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEERKNS1_6vectorIPNS_12MTFilterBaseENS5_ISC_EEEE(...); // call internal at 0x1a78a4
    _ZdlPv(...); // call PLT API at 0x1a78b4
    glBindTexture(...); // call PLT API at 0x1a78c0
    pthread_mutex_unlock(...); // call PLT API at 0x1a78d8
    return a0;
    sub_C3100(...); // call internal at 0x1a7910
    _ZdlPv(...); // call PLT API at 0x1a7924
    sub_1B0544(...); // call internal at 0x1a793c
    __stack_chk_fail(...); // call PLT API at 0x1a7940
}

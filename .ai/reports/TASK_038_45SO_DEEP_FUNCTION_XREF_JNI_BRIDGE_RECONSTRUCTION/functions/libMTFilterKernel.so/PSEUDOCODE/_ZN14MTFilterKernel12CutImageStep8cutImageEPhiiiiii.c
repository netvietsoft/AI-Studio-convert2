// Function: MTFilterKernel::CutImageStep::cutImage(unsigned char*, int, int, int, int, int, int)
// RVA: 0xcb260, Size: 524 bytes
int64_t _ZN14MTFilterKernel12CutImageStep8cutImageEPhiiiiii(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0xcb2b4
    const char* str = "FilterKernel";
    const char* str = "cut error: left = %d  ||  right = %d  ||  top = %d  ||  bottom = %d";
    __android_log_print(...); // call PLT API at 0xcb2e4
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0xcb308
    const char* str = "FilterKernel";
    const char* str = "left >= right  ||  top >= bottom)";
    __android_log_print(...); // call PLT API at 0xcb328
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0xcb340
    const char* str = "FilterKernel";
    const char* str = "cut w=%d,h=%d,l=%d,t=%d,r=%d,b=%d";
    __android_log_print(...); // call PLT API at 0xcb38c
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0xcb390
    const char* str = "FilterKernel";
    const char* str = "cut dw = %d, dh = %d";
    __android_log_print(...); // call PLT API at 0xcb3b8
    _Znam(...); // call PLT API at 0xcb3d0
    memcpy(...); // call PLT API at 0xcb40c
    const char* str = "FilterKernel";
    const char* str = "cut error: dw < 2  ||  dh < 2";
    __android_log_print(...); // call PLT API at 0xcb444
    return a0;
}

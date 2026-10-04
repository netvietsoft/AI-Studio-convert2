// Function: PVGCOLOR::PVGOpenGL::makeCurrentContext(void*, void*, void*, void*)
// RVA: 0x52824, Size: 572 bytes
int64_t _ZN8PVGCOLOR9PVGOpenGL18makeCurrentContextEPvS1_S1_S1_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    eglMakeCurrent(...); // call PLT API at 0x52860
    const char* str = "PVGColorFunctions";
    const char* str = "[%s(%d)]:> OpenGLUtility makeCurrentContext success context %p
";
    const char* str = "makeCurrentContext";
    __android_log_print(...); // call PLT API at 0x528a8
    return a0;
    eglMakeCurrent(...); // call PLT API at 0x528dc
    const char* str = "PVGColorFunctions";
    const char* str = "[%s(%d)]:> OpenGLUtility makeCurrentContext success
";
    const char* str = "makeCurrentContext";
    __android_log_print(...); // call PLT API at 0x52920
    return a0;
    const char* str = "PVGColorFunctions";
    const char* str = "[%s(%d)]:> OpenGLUtility makeCurrentContext failed, context %p display %p draw %p read %p
";
    const char* str = "makeCurrentContext";
    __android_log_print(...); // call PLT API at 0x52988
    return a0;
    eglGetError(...); // call PLT API at 0x529a0
    const char* str = "PVGColorFunctions";
    const char* str = "[%s(%d)]:> OpenGLUtility makeCurrentContext failed %d context %p display %p
";
    const char* str = "makeCurrentContext";
    __android_log_print(...); // call PLT API at 0x529ec
    return a0;
    eglGetError(...); // call PLT API at 0x52a04
    const char* str = "PVGColorFunctions";
    const char* str = "[%s(%d)]:> OpenGLUtility makeCurrentContext failed %d
";
    const char* str = "makeCurrentContext";
    __android_log_print(...); // call PLT API at 0x52a48
    return a0;
}

// Function: PVGCOLOR::PVGOpenGL::destroyGLContext(void**, void**, void**, void**)
// RVA: 0x526f4, Size: 304 bytes
int64_t _ZN8PVGCOLOR9PVGOpenGL16destroyGLContextEPPvS2_S2_S2_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    eglDestroySurface(...); // call PLT API at 0x5273c
    eglDestroySurface(...); // call PLT API at 0x52748
    eglDestroyContext(...); // call PLT API at 0x52754
    const char* str = "PVGColorFunctions";
    const char* str = "[%s(%d)]:> OpenGLUtility destroyGLContext success
";
    const char* str = "destroyGLContext";
    __android_log_print(...); // call PLT API at 0x527a4
    return a0;
    const char* str = "PVGColorFunctions";
    const char* str = "[%s(%d)]:> OpenGLUtility destroyGLContext failed
";
    const char* str = "destroyGLContext";
    __android_log_print(...); // call PLT API at 0x527f8
    return a0;
    return a0;
}

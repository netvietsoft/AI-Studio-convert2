// Reconstructed Pseudocode for FN_libVERenderer_0004C210 (backend::OpenGLUtility::makeCurrentContext(void*, void*, void*, void*))
// Library: libVERenderer.so | RVA: 0x4C210 | Size: 428B | Visibility: FACT

/* Imported APIs: eglMakeCurrent;__android_log_print */
/* String XREFs: VERenderer;[%s(%d)]:> OpenGLUtility makeCurrentContext success;makeCurrentContext;VERenderer;[%s(%d)]:> OpenGLUtility makeCurrentContext success */

int backend__OpenGLUtility__makeCurrentContext(void*,_void*,_void*,_void*)(void* ctx) {
    // Function prologue: set up stack frame
    eglMakeCurrent(...);
    __android_log_print(...);
    return 0;
}

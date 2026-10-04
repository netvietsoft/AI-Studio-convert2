// Reconstructed Pseudocode for FN_libVERenderer_0004C084 (backend::OpenGLUtility::destroyGLContext(void**, void**, void**, void**))
// Library: libVERenderer.so | RVA: 0x4C084 | Size: 372B | Visibility: FACT

/* Imported APIs: __android_log_print;eglDestroySurface;eglDestroyContext */
/* String XREFs: VERenderer;[%s(%d)]:> OpenGLUtility destroyGLContext %p;destroyGLContext;VERenderer;[%s(%d)]:> OpenGLUtility destroyGLContext failed */

int backend__OpenGLUtility__destroyGLContext(void**,_void**,_void**,_void**)(void* ctx) {
    // Function prologue: set up stack frame
    __android_log_print(...);
    eglDestroySurface(...);
    eglDestroyContext(...);
    return 0;
}

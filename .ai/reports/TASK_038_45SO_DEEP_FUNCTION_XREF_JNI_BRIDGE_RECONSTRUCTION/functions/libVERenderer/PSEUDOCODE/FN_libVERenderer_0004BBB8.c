// Reconstructed Pseudocode for FN_libVERenderer_0004BBB8 (backend::OpenGLUtility::createGLContext(void**, void**, void**, void**, void*))
// Library: libVERenderer.so | RVA: 0x4BBB8 | Size: 1228B | Visibility: FACT

/* Imported APIs: eglGetDisplay;eglInitialize;__android_log_print;eglChooseConfig;eglCreatePbufferSurface;eglGetError;eglCreateContext;eglDestroySurface;eglDestroyContext;__stack_chk_fail */
/* String XREFs: 0;W0;VERenderer;[%s(%d)]:> OpenGLUtility createGLContext EGL init with version %d.%d;createGLContext */

int backend__OpenGLUtility__createGLContext(void**,_void**,_void**,_void**,_void*)(void* ctx) {
    // Function prologue: set up stack frame
    eglGetDisplay(...);
    eglInitialize(...);
    __android_log_print(...);
    eglChooseConfig(...);
    eglCreatePbufferSurface(...);
    return 0;
}

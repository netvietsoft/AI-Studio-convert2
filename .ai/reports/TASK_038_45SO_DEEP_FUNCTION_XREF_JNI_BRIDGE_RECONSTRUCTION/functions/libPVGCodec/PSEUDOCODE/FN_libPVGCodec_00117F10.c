// Reconstructed Pseudocode for FN_libPVGCodec_00117F10 (sub_117F10)
// Library: libPVGCodec.so | RVA: 0x117F10 | Size: 984B | Visibility: HIGH_CONFIDENCE

/* Imported APIs: glBindFramebuffer;glFramebufferTexture2D;glCheckFramebufferStatus;glGenFramebuffers;pthread_self;__android_log_print;_ZN3PVG19logCallbackInternalEiPKcz */
/* String XREFs: PVGCodec;F[%s  L(%d)]  T(%p):> Create FrameBuffer error 2. ID = %d textureWidth=%d textur;BindFBO;%s/%s: F[%s  L(%d)]  T(%p):> Create FrameBuffer error 2. ID = %d textureWidth=%d;PVGCodec */

int sub_117F10(void* ctx) {
    // Function prologue: set up stack frame
    sub_117880(ctx);
    glBindFramebuffer(...);
    glFramebufferTexture2D(...);
    glCheckFramebufferStatus(...);
    glGenFramebuffers(...);
    pthread_self(...);
    return 0;
}

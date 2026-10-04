// Reconstructed Pseudocode for FN_libPVGCodec_001189D0 (sub_1189D0)
// Library: libPVGCodec.so | RVA: 0x1189D0 | Size: 268B | Visibility: HIGH_CONFIDENCE

/* Imported APIs: pthread_self;__android_log_print;_ZN3PVG19logCallbackInternalEiPKcz */
/* String XREFs: (%p):> av_buffer_pool_init is failed;iled;PVGCodec;F[%s  L(%d)]  T(%p):> please SetCropInfo first;CropTextureToFBO */

int sub_1189D0(void* ctx) {
    // Function prologue: set up stack frame
    sub_1182F8(ctx);
    pthread_self(...);
    __android_log_print(...);
    _ZN3PVG19logCallbackInternalEiPKcz(...);
    return 0;
}

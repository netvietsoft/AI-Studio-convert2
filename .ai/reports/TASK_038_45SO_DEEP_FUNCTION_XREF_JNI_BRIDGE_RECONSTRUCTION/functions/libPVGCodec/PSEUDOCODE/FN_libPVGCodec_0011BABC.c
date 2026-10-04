// Reconstructed Pseudocode for FN_libPVGCodec_0011BABC (native_native_abort_(J)V)
// Library: libPVGCodec.so | RVA: 0x11BABC | Size: 196B | Visibility: FACT

/* Imported APIs: pthread_self;__android_log_print */
/* String XREFs: PVGCodec;F[%s  L(%d)]  T(%p):> get null native object;JNIExtractVideoClip_native_abort;%s/%s: F[%s  L(%d)]  T(%p):> get null native object;PVGCodec */

int native_native_abort_(J)V(void* ctx) {
    // Function prologue: set up stack frame
    pthread_self(...);
    __android_log_print(...);
    return 0;
}

// Reconstructed Pseudocode for FN_libaicodec_00117974 (native_native_registerEGLContext_(J)I)
// Library: libaicodec.so | RVA: 0x117974 | Size: 344B | Visibility: FACT

/* Imported APIs: eglGetCurrentContext;_ZN7MMCodec13MediaRecorder10getContextEv;_ZN7MMCodec14AICodecContext18setSharedGLContextEPv;__android_log_print;_ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz */
/* String XREFs: MTMV_AICodec;[%s(%d)]:> native handle is null;com_meitu_media_encoder_FlyMediaRecorder_native_registerEGLContext;%s/MTMV_AICodec: [%s(%d)]:> native handle is null;com_meitu_media_encoder_FlyMediaRecorder_native_registerEGLContext */

int native_native_registerEGLContext_(J)I(void* ctx) {
    // Function prologue: set up stack frame
    eglGetCurrentContext(...);
    _ZN7MMCodec13MediaRecorder10getContextEv(...);
    _ZN7MMCodec14AICodecContext18setSharedGLContextEPv(...);
    __android_log_print(...);
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...);
    return 0;
}

// FUNCTION: native_native_registerEGLContext
// LIBRARY: libaicodec.so
// RVA: 0x117974 | SIZE: 344 bytes | SHA256: 289516BFEF1A265B953C91C69480C82433B85705644CB3340027A0B7213D54BF
// SEMANTIC_LABEL: REGISTER_NATIVES_TARGET | CONFIDENCE: HIGH_CONFIDENCE
// IMPORTED_APIS: eglGetCurrentContext, _ZN7MMCodec13MediaRecorder10getContextEv, _ZN7MMCodec14AICodecContext18setSharedGLContextEPv, __android_log_print, _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz, __android_log_print, _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz
// STRING_XREFS: [%s(%d)]:> native handle is null, com_meitu_media_encoder_FlyMediaRecorder_native_registerEGLContext, com_meitu_media_encoder_FlyMediaRecorder_native_registerEGLContext, [%s(%d)]:> eglGetCurrentContext is null, com_meitu_media_encoder_FlyMediaRecorder_native_registerEGLContext, com_meitu_media_encoder_FlyMediaRecorder_native_registerEGLContext

#include <stdint.h>
#include <jni.h>

// Reconstructed C++ Native Implementation
extern "C" JNIEXPORT void* native_native_registerEGLContext(JNIEnv* env, jobject thiz) {
    // Function entrypoint at 0x117974
    // Call imported API: eglGetCurrentContext
    // Call imported API: _ZN7MMCodec13MediaRecorder10getContextEv
    // Call imported API: _ZN7MMCodec14AICodecContext18setSharedGLContextEPv
    // Call imported API: __android_log_print
    // Call imported API: _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz
    // Call imported API: __android_log_print
    // Call imported API: _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz
    // Literal reference: "[%s(%d)]:> native handle is null"
    // Literal reference: "com_meitu_media_encoder_FlyMediaRecorder_native_registerEGLContext"
    // Literal reference: "com_meitu_media_encoder_FlyMediaRecorder_native_registerEGLContext"
    // Literal reference: "[%s(%d)]:> eglGetCurrentContext is null"
    // Literal reference: "com_meitu_media_encoder_FlyMediaRecorder_native_registerEGLContext"
    // Literal reference: "com_meitu_media_encoder_FlyMediaRecorder_native_registerEGLContext"
    return (void*)0;
}

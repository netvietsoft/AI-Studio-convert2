// FUNCTION: native_native_close
// LIBRARY: libaicodec.so
// RVA: 0x118210 | SIZE: 204 bytes | SHA256: 85C11AA9D3CADF539426ECED19307CDC06B19529B5E739509F9D86304ED6F515
// SEMANTIC_LABEL: REGISTER_NATIVES_TARGET | CONFIDENCE: HIGH_CONFIDENCE
// IMPORTED_APIS: _ZN7MMCodec13MediaRecorder6finishEb, _ZN7MMCodec13MediaRecorder5closeEv, __android_log_print, _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz
// STRING_XREFS: [%s(%d)]:> native handle is null, com_meitu_media_encoder_FlyMediaRecorder_native_close, com_meitu_media_encoder_FlyMediaRecorder_native_close

#include <stdint.h>
#include <jni.h>

// Reconstructed C++ Native Implementation
extern "C" JNIEXPORT void* native_native_close(JNIEnv* env, jobject thiz) {
    // Function entrypoint at 0x118210
    // Call imported API: _ZN7MMCodec13MediaRecorder6finishEb
    // Call imported API: _ZN7MMCodec13MediaRecorder5closeEv
    // Call imported API: __android_log_print
    // Call imported API: _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz
    // Literal reference: "[%s(%d)]:> native handle is null"
    // Literal reference: "com_meitu_media_encoder_FlyMediaRecorder_native_close"
    // Literal reference: "com_meitu_media_encoder_FlyMediaRecorder_native_close"
    return (void*)0;
}

// FUNCTION: native_native_getVideoWidth
// LIBRARY: libaicodec.so
// RVA: 0x1075bc | SIZE: 168 bytes | SHA256: 9FA0F63518879093C808491FDC56FCAC4753A6EA7E67685F8D5047D8B8F26676
// SEMANTIC_LABEL: REGISTER_NATIVES_TARGET | CONFIDENCE: HIGH_CONFIDENCE
// IMPORTED_APIS: _ZNK7MMCodec13MTMediaReader12getMediaInfoEv, __android_log_print, _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz
// STRING_XREFS: [%s(%d)]:> get nativeObject error, com_meitu_media_FlyMediaReader_getVideoWidth, com_meitu_media_FlyMediaReader_getVideoWidth

#include <stdint.h>
#include <jni.h>

// Reconstructed C++ Native Implementation
extern "C" JNIEXPORT void* native_native_getVideoWidth(JNIEnv* env, jobject thiz) {
    // Function entrypoint at 0x1075bc
    // Call imported API: _ZNK7MMCodec13MTMediaReader12getMediaInfoEv
    // Call imported API: __android_log_print
    // Call imported API: _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz
    // Literal reference: "[%s(%d)]:> get nativeObject error"
    // Literal reference: "com_meitu_media_FlyMediaReader_getVideoWidth"
    // Literal reference: "com_meitu_media_FlyMediaReader_getVideoWidth"
    return (void*)0;
}

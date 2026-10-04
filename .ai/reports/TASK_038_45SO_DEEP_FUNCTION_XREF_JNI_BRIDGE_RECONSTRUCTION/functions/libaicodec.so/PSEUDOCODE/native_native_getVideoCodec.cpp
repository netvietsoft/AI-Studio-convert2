// FUNCTION: native_native_getVideoCodec
// LIBRARY: libaicodec.so
// RVA: 0x107878 | SIZE: 232 bytes | SHA256: 8385652962278EE03587B06E05D007E54A8AA32882EF8ACE50D0ECFF8348DB2D
// SEMANTIC_LABEL: REGISTER_NATIVES_TARGET | CONFIDENCE: HIGH_CONFIDENCE
// IMPORTED_APIS: _ZNK7MMCodec13MTMediaReader12getMediaInfoEv, __android_log_print, _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz
// STRING_XREFS: [%s(%d)]:> get nativeObject error, com_meitu_media_FlyMediaReader_getVideoCodec, com_meitu_media_FlyMediaReader_getVideoCodec

#include <stdint.h>
#include <jni.h>

// Reconstructed C++ Native Implementation
extern "C" JNIEXPORT void* native_native_getVideoCodec(JNIEnv* env, jobject thiz) {
    // Function entrypoint at 0x107878
    // Call imported API: _ZNK7MMCodec13MTMediaReader12getMediaInfoEv
    // Call imported API: __android_log_print
    // Call imported API: _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz
    // Literal reference: "[%s(%d)]:> get nativeObject error"
    // Literal reference: "com_meitu_media_FlyMediaReader_getVideoCodec"
    // Literal reference: "com_meitu_media_FlyMediaReader_getVideoCodec"
    return (void*)0;
}

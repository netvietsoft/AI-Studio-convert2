// FUNCTION: native_nativeSetHeadPoints
// LIBRARY: libARKernelInterface.so
// RVA: 0x56af00 | SIZE: 292 bytes | SHA256: 199028ECD52E40767B338867BBE8EDDBF2303D7AF31B492B70B245F41F0FF8D7
// SEMANTIC_LABEL: REGISTER_NATIVES_TARGET | CONFIDENCE: HIGH_CONFIDENCE
// IMPORTED_APIS: memcpy, __android_log_print
// STRING_XREFS: arkernel, ARKernelFaceInterface::SetHeadPoints: data len = %d , head point count = %d, arkernel, ARKernelFaceInterface::SetHeadPoints: data len = %d , head point count = %d

#include <stdint.h>
#include <jni.h>

// Reconstructed C++ Native Implementation
extern "C" JNIEXPORT void* native_nativeSetHeadPoints(JNIEnv* env, jobject thiz) {
    // Function entrypoint at 0x56af00
    // Call imported API: memcpy
    // Call imported API: __android_log_print
    // Literal reference: "arkernel"
    // Literal reference: "ARKernelFaceInterface::SetHeadPoints: data len = %d , head point count = %d"
    // Literal reference: "arkernel"
    // Literal reference: "ARKernelFaceInterface::SetHeadPoints: data len = %d , head point count = %d"
    return (void*)0;
}

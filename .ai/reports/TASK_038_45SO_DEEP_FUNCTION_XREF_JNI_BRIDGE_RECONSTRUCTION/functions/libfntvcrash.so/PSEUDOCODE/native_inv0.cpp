// FUNCTION: native_inv0
// LIBRARY: libfntvcrash.so
// RVA: 0xb260 | SIZE: 876 bytes | SHA256: 78F00BC66291B76A35489061F7468CB0C59CBFA894976DAC4645FD08F0B09A8D
// SEMANTIC_LABEL: REGISTER_NATIVES_TARGET | CONFIDENCE: HIGH_CONFIDENCE
// IMPORTED_APIS: __stack_chk_fail
// STRING_XREFS: illegal name, illegal arg sig, illegal return sig

#include <stdint.h>
#include <jni.h>

// Reconstructed C++ Native Implementation
extern "C" JNIEXPORT void* native_inv0(JNIEnv* env, jobject thiz) {
    // Function entrypoint at 0xb260
    // Call imported API: __stack_chk_fail
    // Literal reference: "illegal name"
    // Literal reference: "illegal arg sig"
    // Literal reference: "illegal return sig"
    return (void*)0;
}

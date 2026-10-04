// FUNCTION: com.kwai.koom.fastdump.ForkJvmHeapDumper::exitProcess
// LIBRARY: libkoom-strip-dump.so
// RVA: 0x38bdc | SIZE: 48 bytes | SHA256: 22C2D62E02FBA2562FEDF40F7E569E2E34249194CF6D161E69AC99A87B767989
// SEMANTIC_LABEL: JNI_DIRECT_EXPORT | CONFIDENCE: FACT
// IMPORTED_APIS: getpid, __android_log_print, _exit
// STRING_XREFS: process %d will exit!

#include <stdint.h>
#include <jni.h>

// Reconstructed C++ Native Implementation
extern "C" JNIEXPORT void* com.kwai.koom.fastdump.ForkJvmHeapDumper_exitProcess(JNIEnv* env, jobject thiz) {
    // Function entrypoint at 0x38bdc
    // Call imported API: getpid
    // Call imported API: __android_log_print
    // Call imported API: _exit
    // Literal reference: "process %d will exit!"
    return (void*)0;
}

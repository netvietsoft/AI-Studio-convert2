// FUNCTION: native_nativeInit
// LIBRARY: libfntvcrash.so
// RVA: 0x936c | SIZE: 2924 bytes | SHA256: E5DFEAD2C99EECDE5B7818ADF3C998E102FAB94DB430098B3BB24A98F369B9BF
// SEMANTIC_LABEL: REGISTER_NATIVES_TARGET | CONFIDENCE: HIGH_CONFIDENCE
// IMPORTED_APIS: gettimeofday, localtime_r, strdup, strdup, strdup, strdup, strdup, strdup, strdup, strdup, strdup, strdup, uname, strdup, getpid, strdup, __errno, __open_2, calloc, strlen, malloc, memcpy, close, strlen, calloc, calloc, sigaltstack, sigfillset, sigaction, strlen, __memcpy_chk, __stack_chk_fail, free, free, free, free, free, free, free, eventfd, pthread_create
// STRING_XREFS: unknown, /proc/%d/cmdline, /dev/null, /dev/null, /libfntvcrash_dumper.so, crashCallback, (Ljava/lang/String;Ljava/lang/String;ZZLjava/lang/String;)V

#include <stdint.h>
#include <jni.h>

// Reconstructed C++ Native Implementation
extern "C" JNIEXPORT void* native_nativeInit(JNIEnv* env, jobject thiz) {
    // Function entrypoint at 0x936c
    // Call imported API: gettimeofday
    // Call imported API: localtime_r
    // Call imported API: strdup
    // Call imported API: strdup
    // Call imported API: strdup
    // Call imported API: strdup
    // Call imported API: strdup
    // Call imported API: strdup
    // Call imported API: strdup
    // Call imported API: strdup
    // Call imported API: strdup
    // Call imported API: strdup
    // Call imported API: uname
    // Call imported API: strdup
    // Call imported API: getpid
    // Call imported API: strdup
    // Call imported API: __errno
    // Call imported API: __open_2
    // Call imported API: calloc
    // Call imported API: strlen
    // Call imported API: malloc
    // Call imported API: memcpy
    // Call imported API: close
    // Call imported API: strlen
    // Call imported API: calloc
    // Call imported API: calloc
    // Call imported API: sigaltstack
    // Call imported API: sigfillset
    // Call imported API: sigaction
    // Call imported API: strlen
    // Call imported API: __memcpy_chk
    // Call imported API: __stack_chk_fail
    // Call imported API: free
    // Call imported API: free
    // Call imported API: free
    // Call imported API: free
    // Call imported API: free
    // Call imported API: free
    // Call imported API: free
    // Call imported API: eventfd
    // Call imported API: pthread_create
    // Literal reference: "unknown"
    // Literal reference: "/proc/%d/cmdline"
    // Literal reference: "/dev/null"
    // Literal reference: "/dev/null"
    // Literal reference: "/libfntvcrash_dumper.so"
    // Literal reference: "crashCallback"
    // Literal reference: "(Ljava/lang/String;Ljava/lang/String;ZZLjava/lang/String;)V"
    return (void*)0;
}

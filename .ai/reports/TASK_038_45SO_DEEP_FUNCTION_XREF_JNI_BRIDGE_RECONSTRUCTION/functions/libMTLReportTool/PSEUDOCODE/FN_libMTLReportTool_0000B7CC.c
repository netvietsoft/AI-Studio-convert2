// Reconstructed Pseudocode for FN_libMTLReportTool_0000B7CC (native_release_()V)
// Library: libMTLReportTool.so | RVA: 0xB7CC | Size: 468B | Visibility: FACT

/* Imported APIs: __android_log_print;_ZNSt6__ndk15mutex4lockEv;_ZNSt6__ndk15mutex6unlockEv;__cxa_begin_catch;__cxa_end_catch */
/* String XREFs: vllogmediatorLog-JNI;vllogRelease called;vllogmediatorLog-JNI;Deleted log callback reference;vllogmediatorLog-JNI */

int native_release_()V(void* ctx) {
    // Function prologue: set up stack frame
    sub_CA4C(ctx);
    sub_80B0(ctx);
    __android_log_print(...);
    _ZNSt6__ndk15mutex4lockEv(...);
    _ZNSt6__ndk15mutex6unlockEv(...);
    __cxa_begin_catch(...);
    __cxa_end_catch(...);
    return 0;
}

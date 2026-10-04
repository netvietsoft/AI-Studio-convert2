// Reconstructed Pseudocode for FN_libMTLReportTool_0000B9A0 (native_getVersion_()Ljava/lang/String;)
// Library: libMTLReportTool.so | RVA: 0xB9A0 | Size: 260B | Visibility: FACT

/* Imported APIs: _ZN13VLLogMediator11getInstanceEv;_ZN13VLLogMediator15getVllogVersionEv;__android_log_print;__cxa_begin_catch;__cxa_end_catch */
/* String XREFs: vllogmediatorLog-JNI;VLLog version: %s;vllogmediatorLog-JNI;vllogGetVersion failed: %s;java/lang/RuntimeException */

int native_getVersion_()Ljava/lang/String;(void* ctx) {
    // Function prologue: set up stack frame
    sub_CA4C(ctx);
    sub_80B0(ctx);
    _ZN13VLLogMediator11getInstanceEv(...);
    _ZN13VLLogMediator15getVllogVersionEv(...);
    __android_log_print(...);
    __cxa_begin_catch(...);
    __cxa_end_catch(...);
    return 0;
}

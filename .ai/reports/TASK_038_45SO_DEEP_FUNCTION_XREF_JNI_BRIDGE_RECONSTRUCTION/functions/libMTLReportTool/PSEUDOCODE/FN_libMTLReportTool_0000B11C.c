// Reconstructed Pseudocode for FN_libMTLReportTool_0000B11C (native_init_(Ljava/lang/String;)V)
// Library: libMTLReportTool.so | RVA: 0xB11C | Size: 396B | Visibility: FACT

/* Imported APIs: __android_log_print;_ZN13VLLogMediator11getInstanceEv;_ZN13VLLogMediator4initERKNSt6__ndk112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEE;_ZdlPv;__cxa_begin_catch;__cxa_end_catch;__stack_chk_fail */
/* String XREFs: vllogmediatorLog-JNI;vllogInit called with cacheDir: %s;vllogmediatorLog-JNI;VLLogMediator initialized successfully;vllogmediatorLog-JNI */

int native_init_(Ljava/lang/String;)V(void* ctx) {
    // Function prologue: set up stack frame
    sub_BC70(ctx);
    sub_CA4C(ctx);
    sub_80B0(ctx);
    __android_log_print(...);
    _ZN13VLLogMediator11getInstanceEv(...);
    _ZN13VLLogMediator4initERKNSt6__ndk112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEE(...);
    _ZdlPv(...);
    __cxa_begin_catch(...);
    return 0;
}

// Reconstructed Pseudocode for FN_libMTLReportTool_0000B2A8 (native_setConfigParams_(Ljava/lang/String;)V)
// Library: libMTLReportTool.so | RVA: 0xB2A8 | Size: 396B | Visibility: FACT

/* Imported APIs: __android_log_print;_ZN13VLLogMediator11getInstanceEv;_ZN13VLLogMediator15setConfigParamsERKNSt6__ndk112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEE;_ZdlPv;__cxa_begin_catch;__cxa_end_catch;__stack_chk_fail */
/* String XREFs: vllogmediatorLog-JNI;vllogSetConfigParams called with json: %s;vllogmediatorLog-JNI;vllogSetConfigParams completed successfully;vllogmediatorLog-JNI */

int native_setConfigParams_(Ljava/lang/String;)V(void* ctx) {
    // Function prologue: set up stack frame
    sub_BC70(ctx);
    sub_CA4C(ctx);
    sub_80B0(ctx);
    __android_log_print(...);
    _ZN13VLLogMediator11getInstanceEv(...);
    _ZN13VLLogMediator15setConfigParamsERKNSt6__ndk112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEE(...);
    _ZdlPv(...);
    __cxa_begin_catch(...);
    return 0;
}

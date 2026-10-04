// Reconstructed Pseudocode for FN_libMTLReportTool_0000BAA4 (native_setTagExclude_(Ljava/lang/String;I)I)
// Library: libMTLReportTool.so | RVA: 0xBAA4 | Size: 440B | Visibility: FACT

/* Imported APIs: __android_log_print;_ZN13VLLogMediator11getInstanceEv;_ZN13VLLogMediator13setTagExcludeEPKci;_ZdlPv;__cxa_begin_catch;__cxa_end_catch;__stack_chk_fail */
/* String XREFs: vllogmediatorLog-JNI;vllogSetTagExclude called with tag: %s  excluded: %d;vllogmediatorLog-JNI;vllogSetTagExclude completed with result: %d;vllogmediatorLog-JNI */

int native_setTagExclude_(Ljava/lang/String;I)I(void* ctx) {
    // Function prologue: set up stack frame
    sub_BC70(ctx);
    sub_CA4C(ctx);
    sub_80B0(ctx);
    __android_log_print(...);
    _ZN13VLLogMediator11getInstanceEv(...);
    _ZN13VLLogMediator13setTagExcludeEPKci(...);
    _ZdlPv(...);
    __cxa_begin_catch(...);
    return 0;
}

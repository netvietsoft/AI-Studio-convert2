// Reconstructed Pseudocode for FN_libMTLReportTool_0000B434 (native_setLogCallback_(Lkotlin/jvm/functions/Function1;)V)
// Library: libMTLReportTool.so | RVA: 0xB434 | Size: 920B | Visibility: FACT

/* Imported APIs: __android_log_print;_ZNSt6__ndk15mutex4lockEv;_ZNSt6__ndk15mutex6unlockEv;_ZN13VLLogMediator11getInstanceEv;_ZN13VLLogMediator14setLogCallbackERKNSt6__ndk18functionIFvRKNS0_6vectorI11vllog_entryNS0_9allocatorIS3_EEEEEEE;__cxa_begin_catch;__cxa_end_catch;__stack_chk_fail */
/* String XREFs: vllogmediatorLog-JNI;vllogSetLogCallback called;com/meitu/mtlab/MTLReportTool/models/LogInfoModel;vllogmediatorLog-JNI;Cached LogInfoModel class reference */

int native_setLogCallback_(Lkotlin/jvm/functions/Function1;)V(void* ctx) {
    // Function prologue: set up stack frame
    sub_CA4C(ctx);
    sub_80B0(ctx);
    __android_log_print(...);
    _ZNSt6__ndk15mutex4lockEv(...);
    _ZNSt6__ndk15mutex6unlockEv(...);
    _ZN13VLLogMediator11getInstanceEv(...);
    _ZN13VLLogMediator14setLogCallbackERKNSt6__ndk18functionIFvRKNS0_6vectorI11vllog_entryNS0_9allocatorIS3_EEEEEEE(...);
    return 0;
}

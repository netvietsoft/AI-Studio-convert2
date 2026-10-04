// Function: MMCodec::InMediaHandle::unprepare()
// RVA: 0x141750, Size: 1024 bytes
int64_t _ZN7MMCodec13InMediaHandle9unprepareEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec18MediaHandleContext9markAbortEv(...); // call imported API via PLT at 0x141794
    _ZN7MMCodec18MediaHandleContext9markAbortEv(...); // call imported API via PLT at 0x1417b4
    _ZN7MMCodec18MediaHandleContext14getPacketQueueEi(...); // call imported API via PLT at 0x1417ec
    _ZN7MMCodec11PacketQueue5abortEv(...); // call imported API via PLT at 0x1417f4
    _ZN7MMCodec13ThreadContext5abortEv(...); // call imported API via PLT at 0x141808
    _ZN7MMCodec13ThreadContext4joinEv(...); // call imported API via PLT at 0x141814
    _ZN7MMCodec13ThreadContextD1Ev(...); // call imported API via PLT at 0x141828
    _ZdlPv(...); // call imported API via PLT at 0x141830
    const char* s_88f22 = "[%s(%d)]:> [InMediaHandle(%p)](%ld):> Stream index=%d needn't deal
"; // string xref
    const char* s_6ead0 = "unprepare"; // string xref
    const char* s_6ea7a = "%s/MTMV_AICodec: [%s(%d)]:> [InMediaHandle(%p)](%ld):> Stream index=%d needn't deal

"; // string xref
    _ZN7MMCodec18MediaHandleContext15freePacketQueueEi(...); // call imported API via PLT at 0x141890
    (*x9)(...); // indirect call at 0x1418e4
    (*x8)(...); // indirect call at 0x1418f8
    pthread_self(...); // call imported API via PLT at 0x14190c
    const char* s_7d752 = "MTMV_AICodec";
    __android_log_print(...); // call imported API via PLT at 0x141934
    pthread_self(...); // call imported API via PLT at 0x141948
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x14196c
    _ZN7MMCodec18MediaHandleContext17releaseEGLContextEv(...); // call imported API via PLT at 0x14197c
    _ZN7MMCodec18MediaHandleContext4stopEv(...); // call imported API via PLT at 0x141990
    _ZN9JniHelper6getEnvEv(...); // call imported API via PLT at 0x141998
    _ZN7MMCodec10JniUtility12getJavaClassEPKc(...); // call imported API via PLT at 0x1419b0
    const char* s_79798 = "getErrorInfoString"; // string xref
    const char* s_69932 = "()Ljava/lang/String;"; // string xref
    (*x8)(...); // indirect call at 0x1419dc
    _ZN7_JNIEnv22CallStaticObjectMethodEP7_jclassP10_jmethodIDz(...); // call imported API via PLT at 0x1419f0
    _ZN9JniHelper14jstring2stringEP8_jstring(...); // call imported API via PLT at 0x141a00
    void* g_202220 = (void*)0x202220; // global ref
    _ZdlPv(...); // call imported API via PLT at 0x141a18
    (*x8)(...); // indirect call at 0x141a3c
    pthread_self(...); // call imported API via PLT at 0x141a64
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_68d0a = "[%s(%d)]:> [InMediaHandle(%p)](%ld):> media handle context stop failed"; // string xref
    const char* s_6ead0 = "unprepare"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x141a90
    pthread_self(...); // call imported API via PLT at 0x141ab4
    const char* s_7ab80 = "%s/MTMV_AICodec: [%s(%d)]:> [InMediaHandle(%p)](%ld):> media handle context stop failed
"; // string xref
    const char* s_6ead0 = "unprepare"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x141adc
    return a0;
    sub_CEBC4(...); // call internal func at 0x141b14
    (*x8)(...); // indirect call at 0x141b2c
    __stack_chk_fail(...); // call imported API via PLT at 0x141b48
    sub_CEBC4(...); // call internal func at 0x141b4c
}

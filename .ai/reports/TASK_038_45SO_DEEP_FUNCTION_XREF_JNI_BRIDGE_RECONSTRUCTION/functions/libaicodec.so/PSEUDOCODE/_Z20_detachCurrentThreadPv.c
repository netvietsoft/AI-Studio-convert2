// Function: _detachCurrentThread(void*)
// RVA: 0x104a60, Size: 184 bytes
int64_t _Z20_detachCurrentThreadPv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_self(...); // call imported API via PLT at 0x104a6c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_83151 = "[%s(%d)]:> JniHelper::getJavaVM(), pthread_self() = %ld"; // string xref
    const char* s_8427f = "getJavaVM"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x104ab4
    const char* s_84289 = "%s/MTMV_AICodec: [%s(%d)]:> JniHelper::getJavaVM(), pthread_self() = %ld
"; // string xref
    const char* s_8427f = "getJavaVM"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x104af4
}

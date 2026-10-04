// Function: JniHelper::setJavaVM(_JavaVM*)
// RVA: 0x104bf4, Size: 204 bytes
int64_t _ZN9JniHelper9setJavaVMEP7_JavaVM(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_self(...); // call imported API via PLT at 0x104c04
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_81ee7 = "[%s(%d)]:> JniHelper::setJavaVM(%p), pthread_self() = %ld"; // string xref
    const char* s_85c0b = "setJavaVM"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x104c50
    const char* s_716d7 = "%s/MTMV_AICodec: [%s(%d)]:> JniHelper::setJavaVM(%p), pthread_self() = %ld
"; // string xref
    const char* s_85c0b = "setJavaVM"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x104c94
    void* g_20a5a8 = (void*)0x20a5a8; // global ref
    pthread_key_create(...); // call imported API via PLT at 0x104cbc
}

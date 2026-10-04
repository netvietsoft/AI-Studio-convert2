// Function: MMDetectionPlugin::_detachCurrentThread(void*)
// RVA: 0x3f970, Size: 112 bytes
int64_t _ZN17MMDetectionPlugin20_detachCurrentThreadEPv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_self(...); // call imported API via PLT at 0x3f98c
    const char* s_30045 = "MTMVCore";
    const char* s_31400 = "[%s(%d)]:> JniHelper::getJavaVM(), pthread_self() = %ld
"; // string xref
    const char* s_3126d = "getJavaVM"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x3f9c0
}

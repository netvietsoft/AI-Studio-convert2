// Function: MMDetectionPlugin::JniHelper::setJavaVM(_JavaVM*)
// RVA: 0x3fa48, Size: 136 bytes
int64_t _ZN17MMDetectionPlugin9JniHelper9setJavaVMEP7_JavaVM(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_self(...); // call imported API via PLT at 0x3fa6c
    const char* s_30045 = "MTMVCore";
    const char* s_31a0d = "[%s(%d)]:> JniHelper::setJavaVM(%p), pthread_self() = %ld
"; // string xref
    const char* s_31324 = "setJavaVM"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x3faa4
    pthread_key_create(...); // call imported API via PLT at 0x3facc
}

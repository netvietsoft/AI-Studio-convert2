// Function: mtlabar3::JniHelper::setJavaVM(_JavaVM*)
// RVA: 0xb66e54, Size: 96 bytes
int64_t _ZN8mtlabar39JniHelper9setJavaVMEP7_JavaVM(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_self(...); // call PLT API at 0xb66e64
    const char* str = "mtlabar3";
    const char* str = "JniHelper::setJavaVM(%p), pthread_self() = %lu";
    __android_log_print(...); // call PLT API at 0xb66e84
    pthread_key_create(...); // call PLT API at 0xb66ea4
    _ZN8mtlabar39JniHelper19cacheGLXBitmapClassEv(...); // call PLT API at 0xb66eb0
}

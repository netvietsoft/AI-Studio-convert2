// Function: mtlabar3::JniHelper::getJavaVM()
// RVA: 0xb66e18, Size: 60 bytes
int64_t _ZN8mtlabar39JniHelper9getJavaVMEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_self(...); // call PLT API at 0xb66e20
    const char* str = "mtlabar3";
    const char* str = "JniHelper::getJavaVM(), pthread_self() = %lu";
    __android_log_print(...); // call PLT API at 0xb66e3c
    return a0;
}

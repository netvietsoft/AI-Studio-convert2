// Function: MTFilterKernel::JniHelper::getEnv()
// RVA: 0xc2678, Size: 52 bytes
int64_t _ZN14MTFilterKernel9JniHelper6getEnvEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_getspecific(...); // call PLT API at 0xc2688
    return a0;
    _ZN14MTFilterKernel9JniHelper8cacheEnvEP7_JavaVM(...); // call internal at 0xc26a8
}

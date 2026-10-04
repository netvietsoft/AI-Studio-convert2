// Function: mtlabar3::JniHelper::getEnv()
// RVA: 0xb66c24, Size: 56 bytes
int64_t _ZN8mtlabar39JniHelper6getEnvEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_getspecific(...); // call PLT API at 0xb66c34
    return a0;
    _ZN8mtlabar39JniHelper8cacheEnvEP7_JavaVM(...); // call PLT API at 0xb66c58
}

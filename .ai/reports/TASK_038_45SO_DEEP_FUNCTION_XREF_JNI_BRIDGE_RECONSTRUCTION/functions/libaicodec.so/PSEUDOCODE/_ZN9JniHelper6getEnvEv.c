// Function: JniHelper::getEnv()
// RVA: 0x104a2c, Size: 52 bytes
int64_t _ZN9JniHelper6getEnvEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_getspecific(...); // call imported API via PLT at 0x104a3c
    return a0;
    _ZN9JniHelper8cacheEnvEP7_JavaVM(...); // call imported API via PLT at 0x104a5c
}

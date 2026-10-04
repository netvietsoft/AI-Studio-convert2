// Function: MMDetectionPlugin::JniHelper::getEnv()
// RVA: 0x3f8a0, Size: 52 bytes
int64_t _ZN17MMDetectionPlugin9JniHelper6getEnvEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_getspecific(...); // call imported API via PLT at 0x3f8b0
    return a0;
    _ZN17MMDetectionPlugin9JniHelper8cacheEnvEP7_JavaVM(...); // call imported API via PLT at 0x3f8d0
}

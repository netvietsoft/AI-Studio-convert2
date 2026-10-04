// Function: MMCodec::ThreadContext::MTRunThread(void*)
// RVA: 0x127240, Size: 60 bytes
int64_t _ZN7MMCodec13ThreadContext11MTRunThreadEPv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_self(...); // call imported API via PLT at 0x127250
    pthread_setname_np(...); // call imported API via PLT at 0x127268
}

// Function: std::__ndk1::chrono::system_clock::now()
// RVA: 0x811d4, Size: 120 bytes
int64_t _ZNSt6__ndk16chrono12system_clock3nowEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    clock_gettime(...); // call imported API via PLT at 0x811ec
    return a0;
    __errno(...); // call imported API via PLT at 0x81234
    const char* s_4a5cd = "clock_gettime(CLOCK_REALTIME) failed";
    _ZNSt6__ndk120__throw_system_errorEiPKc(...); // call imported API via PLT at 0x81244
    sub_754CC(...); // call internal func at 0x81248
}

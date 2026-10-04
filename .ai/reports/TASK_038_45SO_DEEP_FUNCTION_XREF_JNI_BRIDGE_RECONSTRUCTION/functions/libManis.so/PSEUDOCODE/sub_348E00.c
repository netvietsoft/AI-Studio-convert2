// Function: sub_348E00
// RVA: 0x348e00, Size: 760 bytes
int64_t sub_348E00(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_338E1C(...); // call internal at 0x348e54
    _ZNSt6__ndk15mutex4lockEv(...); // call PLT API at 0x348e6c
    _ZdlPv(...); // call PLT API at 0x348ec8
    sub_348AFC(...); // call internal at 0x348ee8
    fcntl(...); // call PLT API at 0x348f3c
    _Znwm(...); // call PLT API at 0x348f48
    memmove(...); // call PLT API at 0x348f70
    const char* str = "mutex is empty, lock file failed";
    perror(...); // call PLT API at 0x348fb8
    sub_334CC0(...); // call internal at 0x348fc0
    __stack_chk_fail(...); // call PLT API at 0x348fc4
    open(...); // call PLT API at 0x349000
    close(...); // call PLT API at 0x349004
    fcntl(...); // call PLT API at 0x349020
    free(...); // call PLT API at 0x349034
    close(...); // call PLT API at 0x349040
    free(...); // call PLT API at 0x34904c
    _ZNSt6__ndk15mutex6unlockEv(...); // call PLT API at 0x349058
    _ZdlPv(...); // call PLT API at 0x349068
    return a0;
    _ZdlPv(...); // call PLT API at 0x349094
    const char* str = "mutex is empty, unlock file failed";
    perror(...); // call PLT API at 0x3490a0
    const char* str = "lock file of mutex close failed";
    perror(...); // call PLT API at 0x3490c0
    _ZNSt6__ndk15mutex6unlockEv(...); // call PLT API at 0x3490cc
    __cxa_atexit(...); // call PLT API at 0x3490f4
}

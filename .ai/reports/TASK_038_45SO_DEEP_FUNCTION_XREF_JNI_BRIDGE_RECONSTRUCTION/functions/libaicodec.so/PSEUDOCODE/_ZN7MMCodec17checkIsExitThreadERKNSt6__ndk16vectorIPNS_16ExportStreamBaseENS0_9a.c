// Function: MMCodec::checkIsExitThread(std::__ndk1::vector<MMCodec::ExportStreamBase*, std::__ndk1::allocator<MMCodec::ExportStreamBase*>> const&)
// RVA: 0xda898, Size: 476 bytes
int64_t _ZN7MMCodec17checkIsExitThreadERKNSt6__ndk16vectorIPNS_16ExportStreamBaseENS0_9allocatorIS3_EEEE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_806b9 = "checkIsExitThread"; // string xref
    const char* s_818cd = "[%s(%d)]:> (%ld):> [%p]Encode thread dead"; // string xref
    const char* s_7497d = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> [%p]Encode thread dead
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xda8fc
    _ZN7MMCodec13ThreadContext14getThreadStateEv(...); // call imported API via PLT at 0xda91c
    pthread_self(...); // call imported API via PLT at 0xda93c
    __android_log_print(...); // call imported API via PLT at 0xda95c
    pthread_self(...); // call imported API via PLT at 0xda970
    pthread_self(...); // call imported API via PLT at 0xda9cc
    const char* s_806b9 = "checkIsExitThread"; // string xref
    const char* s_86ce5 = "[%s(%d)]:> (%ld):> [%p]Encode stream stop"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdaa10
    pthread_self(...); // call imported API via PLT at 0xdaa24
    const char* s_7c556 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> [%p]Encode stream stop
"; // string xref
    return a0;
}

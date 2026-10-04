// Function: MMCodec::GLFramebufferObject::ImageReaderOnImageAvailable(void*)
// RVA: 0x176bbc, Size: 696 bytes
int64_t _ZN7MMCodec19GLFramebufferObject27ImageReaderOnImageAvailableEPv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec13MTImageReader16acquireNextImageERPhRiS3_(...); // call imported API via PLT at 0x176bfc
    _Znwm(...); // call imported API via PLT at 0x176c34
    void* g_200b78 = (void*)0x200b78; // global ref
    (*x8)(...); // indirect call at 0x176c74
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv(...); // call imported API via PLT at 0x176c7c
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x176c84
    _ZNSt6__ndk118condition_variable10notify_oneEv(...); // call imported API via PLT at 0x176c8c
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x176cb8
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7aff3 = "[%s(%d)]:> ImageReader_acquireNextImage failed"; // string xref
    const char* s_6b64a = "ImageReaderOnImageAvailable"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x176cf8
    const char* s_6b666 = "%s/MTMV_AICodec: [%s(%d)]:> ImageReader_acquireNextImage failed
"; // string xref
    const char* s_6b64a = "ImageReaderOnImageAvailable"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x176d58
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_91a49 = "[%s(%d)]:> ImageReaderOnImageAvailable callback can't get context"; // string xref
    const char* s_6b64a = "ImageReaderOnImageAvailable"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x176d98
    const char* s_8699d = "%s/MTMV_AICodec: [%s(%d)]:> ImageReaderOnImageAvailable callback can't get context
"; // string xref
    const char* s_6b64a = "ImageReaderOnImageAvailable"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x176df8
    return a0;
    __cxa_begin_catch(...); // call imported API via PLT at 0x176e24
    _ZN7MMCodec13MTImageReader11jImageCloseERPv(...); // call imported API via PLT at 0x176e34
    __cxa_rethrow(...); // call imported API via PLT at 0x176e48
    __cxa_end_catch(...); // call imported API via PLT at 0x176e50
    __stack_chk_fail(...); // call imported API via PLT at 0x176e6c
    sub_CEBC4(...); // call internal func at 0x176e70
}

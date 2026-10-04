// Function: MMCodec::AudioStream::flush()
// RVA: 0xd0b04, Size: 244 bytes
int64_t _ZN7MMCodec11AudioStream5flushEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec11AudioStream26_writeFIFODataToFrameQueueEb(...); // call imported API via PLT at 0xd0b20
    pthread_self(...); // call imported API via PLT at 0xd0b4c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6b8f7 = "[%s(%d)]:> [AudioStream(%p)](%ld):> flush fifo data failed %d"; // string xref
    const char* s_881e0 = "flush"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xd0b7c
    pthread_self(...); // call imported API via PLT at 0xd0ba0
    const char* s_8e18c = "%s/MTMV_AICodec: [%s(%d)]:> [AudioStream(%p)](%ld):> flush fifo data failed %d
"; // string xref
    const char* s_881e0 = "flush"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xd0bcc
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0xd0bd4
    _ZNSt6__ndk118condition_variable10notify_allEv(...); // call imported API via PLT at 0xd0be0
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0xd0bf4
}

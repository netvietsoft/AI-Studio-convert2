// Function: MMCodec::MediaHandleContext::freePacketQueue(int)
// RVA: 0x147670, Size: 260 bytes
int64_t _ZN7MMCodec18MediaHandleContext15freePacketQueueEi(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_self(...); // call imported API via PLT at 0x1476b0
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_90358 = "[%s(%d)]:> [MediaHandleContext(%p)](%ld):> free packet queue error![index=%d] out of range
"; // string xref
    const char* s_86619 = "freePacketQueue"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1476e0
    pthread_self(...); // call imported API via PLT at 0x147704
    const char* s_68e1f = "%s/MTMV_AICodec: [%s(%d)]:> [MediaHandleContext(%p)](%ld):> free packet queue error![index=%d] out of range

"; // string xref
    const char* s_86619 = "freePacketQueue"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x14773c
    void* g_201548 = (void*)0x201548; // global ref
    _ZN7MMCodec11PacketQueueD1Ev(...); // call imported API via PLT at 0x147754
    _ZdlPv(...); // call imported API via PLT at 0x14775c
    return a0;
}

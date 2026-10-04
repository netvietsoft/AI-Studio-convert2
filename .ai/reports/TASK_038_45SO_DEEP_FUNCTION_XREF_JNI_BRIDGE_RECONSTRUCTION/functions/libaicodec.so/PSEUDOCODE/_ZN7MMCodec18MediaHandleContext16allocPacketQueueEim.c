// Function: MMCodec::MediaHandleContext::allocPacketQueue(int, unsigned long)
// RVA: 0x14752c, Size: 316 bytes
int64_t _ZN7MMCodec18MediaHandleContext16allocPacketQueueEim(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec11PacketQueueD1Ev(...); // call imported API via PLT at 0x147564
    _ZdlPv(...); // call imported API via PLT at 0x14756c
    _Znwm(...); // call imported API via PLT at 0x147574
    _ZN7MMCodec11PacketQueueC1EPNS_14AICodecContextEm(...); // call imported API via PLT at 0x147584
    pthread_self(...); // call imported API via PLT at 0x1475b4
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_68dc1 = "[%s(%d)]:> [MediaHandleContext(%p)](%ld):> Create packet queue error![index=%d] out of range
"; // string xref
    const char* s_8a6fb = "allocPacketQueue"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1475e4
    pthread_self(...); // call imported API via PLT at 0x147608
    const char* s_71d5f = "%s/MTMV_AICodec: [%s(%d)]:> [MediaHandleContext(%p)](%ld):> Create packet queue error![index=%d] out of range

"; // string xref
    const char* s_8a6fb = "allocPacketQueue"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x147634
    return a0;
    _ZdlPv(...); // call imported API via PLT at 0x14765c
}

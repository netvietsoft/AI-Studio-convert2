// Function: MMCodec::FFmpegMediaStream::streamClose()
// RVA: 0x139d30, Size: 656 bytes
int64_t _ZN7MMCodec17FFmpegMediaStream11streamCloseEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec18MediaHandleContext9isPictureEi(...); // call imported API via PLT at 0x139d54
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x139d7c
    (*x8)(...); // indirect call at 0x139d90
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x139d9c
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x139da4
    _ZdlPv(...); // call imported API via PLT at 0x139dbc
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x139df4
    (*x8)(...); // indirect call at 0x139e08
    (*x8)(...); // indirect call at 0x139e1c
    _ZN7MMCodec10FrameQueue5abortEv(...); // call imported API via PLT at 0x139e28
    _ZN7MMCodec10FrameQueue11queueSignalEv(...); // call imported API via PLT at 0x139e30
    _ZN7MMCodec18MediaHandleContext14getPacketQueueEi(...); // call imported API via PLT at 0x139e3c
    _ZN7MMCodec11PacketQueue5abortEv(...); // call imported API via PLT at 0x139e44
    _ZN7MMCodec13ThreadContext4stopEv(...); // call imported API via PLT at 0x139e50
    _ZN7MMCodec13ThreadContext4joinEv(...); // call imported API via PLT at 0x139e58
    _ZN7MMCodec13ThreadContextD1Ev(...); // call imported API via PLT at 0x139e68
    _ZdlPv(...); // call imported API via PLT at 0x139e70
    (*x8)(...); // indirect call at 0x139e88
    _ZN7MMCodec10FrameQueue7releaseEv(...); // call imported API via PLT at 0x139e98
    _ZN7MMCodec10FrameQueueD1Ev(...); // call imported API via PLT at 0x139ea8
    _ZdlPv(...); // call imported API via PLT at 0x139eb0
    _ZN7MMCodec12MMCodecFrame5resetEv(...); // call imported API via PLT at 0x139ec4
    av_audio_fifo_free(...); // call imported API via PLT at 0x139ed0
    _ZN7MMCodec18MediaHandleContext17getAICodecContextEv(...); // call imported API via PLT at 0x139ee4
    _ZN7MMCodec14AICodecContext15releaseAVPacketEP8AVPacket(...); // call imported API via PLT at 0x139eec
    return a0;
    pthread_self(...); // call imported API via PLT at 0x139f34
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7e160 = "[%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> Find handle is null in ffmpeg streams"; // string xref
    const char* s_8baa8 = "streamClose"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x139f60
    pthread_self(...); // call imported API via PLT at 0x139f84
    const char* s_781cc = "%s/MTMV_AICodec: [%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> Find handle is null in ffmpeg streams
"; // string xref
    const char* s_8baa8 = "streamClose"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x139fac
    return a0;
}

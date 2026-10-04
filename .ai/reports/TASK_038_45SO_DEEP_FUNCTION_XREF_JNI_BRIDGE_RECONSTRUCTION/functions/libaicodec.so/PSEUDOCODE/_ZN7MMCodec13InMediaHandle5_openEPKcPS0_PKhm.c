// Function: MMCodec::InMediaHandle::_open(char const*, MMCodec::InMediaHandle*, unsigned char const*, unsigned long)
// RVA: 0x13f8c0, Size: 2744 bytes
int64_t _ZN7MMCodec13InMediaHandle5_openEPKcPS0_PKhm(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    avformat_alloc_context(...); // call imported API via PLT at 0x13f8fc
    av_malloc(...); // call imported API via PLT at 0x13f924
    (*x8)(...); // indirect call at 0x13f93c
    _Znwm(...); // call imported API via PLT at 0x13f948
    void* g_202010 = (void*)0x202010; // global ref
    av_malloc(...); // call imported API via PLT at 0x13f96c
    avio_alloc_context(...); // call imported API via PLT at 0x13f998
    pthread_self(...); // call imported API via PLT at 0x13f9d0
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_71c2f = "[%s(%d)]:> [InMediaHandle(%p)](%ld):> Could not allocate context.
"; // string xref
    const char* s_9018e = "_open"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x13f9fc
    pthread_self(...); // call imported API via PLT at 0x13fa20
    const char* s_8656a = "%s/MTMV_AICodec: [%s(%d)]:> [InMediaHandle(%p)](%ld):> Could not allocate context.

"; // string xref
    const char* s_9018e = "_open"; // string xref
    strlen(...); // call imported API via PLT at 0x13fa4c
    _Znwm(...); // call imported API via PLT at 0x13fa84
    memcpy(...); // call imported API via PLT at 0x13faa4
    memcpy(...); // call imported API via PLT at 0x13faf4
    (*x8)(...); // indirect call at 0x13fb50
    strlen(...); // call imported API via PLT at 0x13fb5c
    (*x8)(...); // indirect call at 0x13fb98
    pthread_self(...); // call imported API via PLT at 0x13fbc0
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_9164c = "[%s(%d)]:> [InMediaHandle(%p)](%ld):> Could not allocate BufferURIProtocol.
"; // string xref
    const char* s_9018e = "_open"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x13fbec
    pthread_self(...); // call imported API via PLT at 0x13fc10
    const char* s_876c5 = "%s/MTMV_AICodec: [%s(%d)]:> [InMediaHandle(%p)](%ld):> Could not allocate BufferURIProtocol.

"; // string xref
    const char* s_9018e = "_open"; // string xref
    pthread_self(...); // call imported API via PLT at 0x13fc58
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_753a8 = "[%s(%d)]:> [InMediaHandle(%p)](%ld):> Could not allocate ioBuffer.
"; // string xref
    const char* s_9018e = "_open"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x13fc84
    pthread_self(...); // call imported API via PLT at 0x13fca8
    const char* s_8d6a5 = "%s/MTMV_AICodec: [%s(%d)]:> [InMediaHandle(%p)](%ld):> Could not allocate ioBuffer.

"; // string xref
    const char* s_9018e = "_open"; // string xref
    _ZdlPv(...); // call imported API via PLT at 0x13fcdc
    const char* s_67ebc = "rtmp"; // string xref
    av_stristart(...); // call imported API via PLT at 0x13fcf4
    _Znwm(...); // call imported API via PLT at 0x13fd08
    memcpy(...); // call imported API via PLT at 0x13fd28
    _Znwm(...); // call imported API via PLT at 0x13fd34
    void* g_202010 = (void*)0x202010; // global ref
    sub_D2278(...); // call internal func at 0x13fd78
    (*x8)(...); // indirect call at 0x13fd8c
    const char* s_67ebc = "rtmp"; // string xref
    av_stristart(...); // call imported API via PLT at 0x13fdbc
    const char* s_6c335 = "rtsp"; // string xref
    av_stristart(...); // call imported API via PLT at 0x13fdd4
    pthread_self(...); // call imported API via PLT at 0x13fdfc
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8eea6 = "[%s(%d)]:> [InMediaHandle(%p)](%ld):> remove 'timeout' option for rtmp.
"; // string xref
    const char* s_9018e = "_open"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x13fe28
    pthread_self(...); // call imported API via PLT at 0x13fe4c
    const char* s_6a109 = "%s/MTMV_AICodec: [%s(%d)]:> [InMediaHandle(%p)](%ld):> remove 'timeout' option for rtmp.

"; // string xref
    const char* s_9018e = "_open"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x13fe74
    const char* s_7aaf2 = "scan_all_pmts"; // string xref
    av_dict_get(...); // call imported API via PLT at 0x13fe8c
    avformat_open_input(...); // call imported API via PLT at 0x13fea4
    const char* s_7aaf2 = "scan_all_pmts"; // string xref
    void* g_7e345 = (void*)0x7e345; // global ref
    av_dict_set(...); // call imported API via PLT at 0x13fec8
    avformat_open_input(...); // call imported API via PLT at 0x13fedc
    const char* s_7aaf2 = "scan_all_pmts"; // string xref
    av_dict_set(...); // call imported API via PLT at 0x13fef8
    void* g_6fc01 = (void*)0x6fc01; // global ref
    av_dict_get(...); // call imported API via PLT at 0x13ff10
    const char* s_6a164 = "Option %s not found.
"; // string xref
    av_log(...); // call imported API via PLT at 0x13ff2c
    pthread_self(...); // call imported API via PLT at 0x13ff60
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x13ff6c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8bbf0 = "[%s(%d)]:> [InMediaHandle(%p)](%ld):> Open media %s error! error reason %d %s
"; // string xref
    const char* s_9018e = "_open"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x13ffa4
    pthread_self(...); // call imported API via PLT at 0x13ffc8
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x13ffd4
    const char* s_6d8aa = "%s/MTMV_AICodec: [%s(%d)]:> [InMediaHandle(%p)](%ld):> Open media %s error! error reason %d %s

"; // string xref
    const char* s_9018e = "_open"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x140008
    (*x8)(...); // indirect call at 0x14001c
    _ZdlPv(...); // call imported API via PLT at 0x140030
    pthread_self(...); // call imported API via PLT at 0x14005c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_9164c = "[%s(%d)]:> [InMediaHandle(%p)](%ld):> Could not allocate BufferURIProtocol.
"; // string xref
    const char* s_9018e = "_open"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x140088
    pthread_self(...); // call imported API via PLT at 0x1400ac
    const char* s_876c5 = "%s/MTMV_AICodec: [%s(%d)]:> [InMediaHandle(%p)](%ld):> Could not allocate BufferURIProtocol.

"; // string xref
    const char* s_9018e = "_open"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1400d4
    avformat_close_input(...); // call imported API via PLT at 0x1400e8
    (*x8)(...); // indirect call at 0x1400fc
    return a0;
    av_format_inject_global_side_data(...); // call imported API via PLT at 0x14013c
    avformat_find_stream_info(...); // call imported API via PLT at 0x140148
    strlen(...); // call imported API via PLT at 0x14016c
    av_strlcpy(...); // call imported API via PLT at 0x14017c
    pthread_self(...); // call imported API via PLT at 0x1401bc
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_826b1 = "[%s(%d)]:> [InMediaHandle(%p)](%ld):> Cannot find media stream info"; // string xref
    const char* s_9018e = "_open"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1401e8
    pthread_self(...); // call imported API via PLT at 0x14020c
    const char* s_8d6fb = "%s/MTMV_AICodec: [%s(%d)]:> [InMediaHandle(%p)](%ld):> Cannot find media stream info
"; // string xref
    const char* s_9018e = "_open"; // string xref
    _ZN7MMCodec18MediaHandleContext4openEP15AVFormatContext(...); // call imported API via PLT at 0x140238
    __stack_chk_fail(...); // call imported API via PLT at 0x140260
    pthread_self(...); // call imported API via PLT at 0x140284
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7ab00 = "[%s(%d)]:> [InMediaHandle(%p)](%ld):> _mediaHandle->open failed"; // string xref
    const char* s_9018e = "_open"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1402b0
    pthread_self(...); // call imported API via PLT at 0x1402d4
    const char* s_7e347 = "%s/MTMV_AICodec: [%s(%d)]:> [InMediaHandle(%p)](%ld):> _mediaHandle->open failed
"; // string xref
    const char* s_9018e = "_open"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1402fc
    sub_D22F8(...); // call internal func at 0x140318
    sub_D22F8(...); // call internal func at 0x140330
    _ZN7MMCodec8Protocol11URIProtocolD2Ev(...); // call imported API via PLT at 0x14033c
    _ZdlPv(...); // call imported API via PLT at 0x140344
    _ZdlPv(...); // call imported API via PLT at 0x14035c
}

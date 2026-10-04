// Function: MMCodec::MediaHandleContext::open(AVFormatContext*)
// RVA: 0x145748, Size: 1248 bytes
int64_t _ZN7MMCodec18MediaHandleContext4openEP15AVFormatContext(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec18MediaHandleContext17loadKeyFrameEntryEv(...); // call imported API via PLT at 0x145790
    av_find_best_stream(...); // call imported API via PLT at 0x1457bc
    av_find_best_stream(...); // call imported API via PLT at 0x145818
    _ZN7MMCodec18MediaHandleContext17isAnimatedPictureEPKc9AVCodecID(...); // call imported API via PLT at 0x14583c
    av_init_packet(...); // call imported API via PLT at 0x145850
    avformat_seek_file(...); // call imported API via PLT at 0x145874
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x1458a0
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_6eaf2 = "[%s(%d)]:> avformat_seek_file %s"; // string xref
    const char* s_9174c = "getAnimatedPictureInfo"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1458c8
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x1458f0
    const char* s_6eb13 = "%s/MTMV_AICodec: [%s(%d)]:> avformat_seek_file %s
"; // string xref
    const char* s_9174c = "getAnimatedPictureInfo"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x145914
    av_packet_unref(...); // call imported API via PLT at 0x14591c
    av_read_frame(...); // call imported API via PLT at 0x145928
    av_packet_unref(...); // call imported API via PLT at 0x14594c
    av_read_frame(...); // call imported API via PLT at 0x145958
    av_get_time_base_q(...); // call imported API via PLT at 0x1459a0
    av_rescale_q(...); // call imported API via PLT at 0x1459b0
    av_get_time_base_q(...); // call imported API via PLT at 0x1459cc
    av_rescale_q(...); // call imported API via PLT at 0x1459dc
    av_packet_unref(...); // call imported API via PLT at 0x1459fc
    av_packet_unref(...); // call imported API via PLT at 0x145a24
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x145a60
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_838f6 = "[%s(%d)]:> error: %s"; // string xref
    const char* s_9174c = "getAnimatedPictureInfo"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x145a88
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x145ab0
    const char* s_902d1 = "%s/MTMV_AICodec: [%s(%d)]:> error: %s
"; // string xref
    const char* s_9174c = "getAnimatedPictureInfo"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x145ad4
    avformat_seek_file(...); // call imported API via PLT at 0x145af0
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x145b1c
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_6eaf2 = "[%s(%d)]:> avformat_seek_file %s"; // string xref
    const char* s_9174c = "getAnimatedPictureInfo"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x145b44
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x145b6c
    const char* s_6eb13 = "%s/MTMV_AICodec: [%s(%d)]:> avformat_seek_file %s
"; // string xref
    const char* s_9174c = "getAnimatedPictureInfo"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x145b90
    av_get_time_base_q(...); // call imported API via PLT at 0x145bd8
    av_rescale_q(...); // call imported API via PLT at 0x145be8
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x145c24
}

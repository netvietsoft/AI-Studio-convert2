// Function: MMCodec::SWDecoder::receiveFrame(AVFrame*)
// RVA: 0x14922c, Size: 904 bytes
int64_t _ZN7MMCodec9SWDecoder12receiveFrameEP7AVFrame(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    av_frame_unref(...); // call imported API via PLT at 0x149270
    avcodec_receive_frame(...); // call imported API via PLT at 0x149280
    const char* s_85538 = "h264_qsv"; // string xref
    strcmp(...); // call imported API via PLT at 0x1492a4
    const char* s_74948 = "hevc_qsv"; // string xref
    strcmp(...); // call imported API via PLT at 0x1492b8
    _ZN7MMCodec23getErrorCodeWithAVErrorEi(...); // call imported API via PLT at 0x1492e8
    av_frame_alloc(...); // call imported API via PLT at 0x1492ec
    avcodec_receive_frame(...); // call imported API via PLT at 0x149300
    av_hwframe_transfer_data(...); // call imported API via PLT at 0x149328
    pthread_self(...); // call imported API via PLT at 0x149354
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8f01d = "[%s(%d)]:> [SWDecoder(%p)](%ld):> Error transferring the data to system memory."; // string xref
    const char* s_89055 = "receiveFrame"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x149380
    pthread_self(...); // call imported API via PLT at 0x1493ac
    const char* s_73286 = "%s/MTMV_AICodec: [%s(%d)]:> [SWDecoder(%p)](%ld):> Error transferring the data to system memory.
"; // string xref
    const char* s_89055 = "receiveFrame"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1493d4
    av_sample_fmt_is_planar(...); // call imported API via PLT at 0x149414
    pthread_self(...); // call imported API via PLT at 0x149448
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_797fa = "[%s(%d)]:> [SWDecoder(%p)](%ld):> dxva2 format is error!!!"; // string xref
    const char* s_89055 = "receiveFrame"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x149474
    pthread_self(...); // call imported API via PLT at 0x149498
    const char* s_79835 = "%s/MTMV_AICodec: [%s(%d)]:> [SWDecoder(%p)](%ld):> dxva2 format is error!!!
"; // string xref
    const char* s_89055 = "receiveFrame"; // string xref
    pthread_self(...); // call imported API via PLT at 0x1494e0
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6b37a = "[%s(%d)]:> [SWDecoder(%p)](%ld):> dxva2 av_frame_alloc fail."; // string xref
    const char* s_89055 = "receiveFrame"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x14950c
    pthread_self(...); // call imported API via PLT at 0x149530
    const char* s_8a765 = "%s/MTMV_AICodec: [%s(%d)]:> [SWDecoder(%p)](%ld):> dxva2 av_frame_alloc fail.
"; // string xref
    const char* s_89055 = "receiveFrame"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x149558
    return a0;
    av_samples_get_buffer_size(...); // call imported API via PLT at 0x149588
    _ZN7MMCodec23getErrorCodeWithAVErrorEi(...); // call imported API via PLT at 0x1495b0
}

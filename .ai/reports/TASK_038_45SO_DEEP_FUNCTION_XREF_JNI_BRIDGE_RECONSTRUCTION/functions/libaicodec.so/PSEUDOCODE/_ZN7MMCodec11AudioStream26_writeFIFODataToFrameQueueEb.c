// Function: MMCodec::AudioStream::_writeFIFODataToFrameQueue(bool)
// RVA: 0xd0254, Size: 1736 bytes
int64_t _ZN7MMCodec11AudioStream26_writeFIFODataToFrameQueueEb(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    void* g_1fd6a0 = (void*)0x1fd6a0; // global ref
    av_audio_fifo_size(...); // call imported API via PLT at 0xd02c4
    (*x10)(...); // indirect call at 0xd02fc
    _ZN7MMCodec14AICodecContext14acquireAVFrameEv(...); // call imported API via PLT at 0xd0300
    _Znwm(...); // call imported API via PLT at 0xd0314
    _ZN7MMCodec19getAudioInnerFormatENS_19AUDIO_SAMPLE_FORMATE(...); // call imported API via PLT at 0xd0338
    av_get_bytes_per_sample(...); // call imported API via PLT at 0xd033c
    av_buffer_pool_init(...); // call imported API via PLT at 0xd0358
    av_buffer_pool_get(...); // call imported API via PLT at 0xd0364
    _ZN7MMCodec19getAudioInnerFormatENS_19AUDIO_SAMPLE_FORMATE(...); // call imported API via PLT at 0xd037c
    av_samples_fill_arrays(...); // call imported API via PLT at 0xd039c
    av_audio_fifo_read(...); // call imported API via PLT at 0xd03b8
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0xd03e0
    pthread_self(...); // call imported API via PLT at 0xd03e8
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6e0d5 = "[%s(%d)]:> [AudioStream(%p)](%ld):> Read audio fifo error![%s]"; // string xref
    const char* s_881c5 = "_writeFIFODataToFrameQueue"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xd0418
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0xd0438
    pthread_self(...); // call imported API via PLT at 0xd0440
    const char* s_6e114 = "%s/MTMV_AICodec: [%s(%d)]:> [AudioStream(%p)](%ld):> Read audio fifo error![%s]
"; // string xref
    const char* s_881c5 = "_writeFIFODataToFrameQueue"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xd046c
    pthread_self(...); // call imported API via PLT at 0xd049c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6e097 = "[%s(%d)]:> [AudioStream(%p)](%ld):> av_buffer_pool_get failed"; // string xref
    const char* s_881c5 = "_writeFIFODataToFrameQueue"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xd04c8
    pthread_self(...); // call imported API via PLT at 0xd04e4
    const char* s_89caf = "%s/MTMV_AICodec: [%s(%d)]:> [AudioStream(%p)](%ld):> av_buffer_pool_get failed
"; // string xref
    const char* s_881c5 = "_writeFIFODataToFrameQueue"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xd050c
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0xd0530
    pthread_self(...); // call imported API via PLT at 0xd0538
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8c798 = "[%s(%d)]:> [AudioStream(%p)](%ld):> Fill sample array error![%s]"; // string xref
    const char* s_881c5 = "_writeFIFODataToFrameQueue"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xd0568
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0xd0588
    pthread_self(...); // call imported API via PLT at 0xd0590
    const char* s_6f268 = "%s/MTMV_AICodec: [%s(%d)]:> [AudioStream(%p)](%ld):> Fill sample array error![%s]
"; // string xref
    const char* s_881c5 = "_writeFIFODataToFrameQueue"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xd05bc
    void* g_2010d6 = (void*)0x2010d6; // global ref
    _ZN7MMCodec20BoundedBlockingQueueINSt6__ndk110shared_ptrI7AVFrameEEE3putERKS4_(...); // call imported API via PLT at 0xd05e8
    pthread_self(...); // call imported API via PLT at 0xd0618
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8c759 = "[%s(%d)]:> [AudioStream(%p)](%ld):> av_buffer_pool_init failed"; // string xref
    const char* s_881c5 = "_writeFIFODataToFrameQueue"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xd0644
    pthread_self(...); // call imported API via PLT at 0xd0660
    const char* s_78b66 = "%s/MTMV_AICodec: [%s(%d)]:> [AudioStream(%p)](%ld):> av_buffer_pool_init failed
"; // string xref
    const char* s_881c5 = "_writeFIFODataToFrameQueue"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xd0688
    (*x8)(...); // indirect call at 0xd06b8
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv(...); // call imported API via PLT at 0xd06c0
    pthread_self(...); // call imported API via PLT at 0xd06e0
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_74881 = "[%s(%d)]:> [AudioStream(%p)](%ld):> no init"; // string xref
    const char* s_881c5 = "_writeFIFODataToFrameQueue"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xd070c
    pthread_self(...); // call imported API via PLT at 0xd0728
    const char* s_7b273 = "%s/MTMV_AICodec: [%s(%d)]:> [AudioStream(%p)](%ld):> no init
"; // string xref
    const char* s_881c5 = "_writeFIFODataToFrameQueue"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xd0750
    return a0;
    pthread_self(...); // call imported API via PLT at 0xd07a4
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_67293 = "[%s(%d)]:> [AudioStream(%p)](%ld):> flushed"; // string xref
    const char* s_881c5 = "_writeFIFODataToFrameQueue"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xd07d0
    pthread_self(...); // call imported API via PLT at 0xd07ec
    const char* s_82c7c = "%s/MTMV_AICodec: [%s(%d)]:> [AudioStream(%p)](%ld):> flushed
"; // string xref
    const char* s_881c5 = "_writeFIFODataToFrameQueue"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xd0814
    pthread_self(...); // call imported API via PLT at 0xd0834
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_75bca = "[%s(%d)]:> [AudioStream(%p)](%ld):> acquireAVFrame error!"; // string xref
    const char* s_881c5 = "_writeFIFODataToFrameQueue"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xd0860
    pthread_self(...); // call imported API via PLT at 0xd087c
    const char* s_78b1a = "%s/MTMV_AICodec: [%s(%d)]:> [AudioStream(%p)](%ld):> acquireAVFrame error!
"; // string xref
    const char* s_881c5 = "_writeFIFODataToFrameQueue"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xd08a4
    __cxa_begin_catch(...); // call imported API via PLT at 0xd08b0
    (*x8)(...); // indirect call at 0xd08c0
    _ZN7MMCodec14AICodecContext14releaseAVFrameEP7AVFrame(...); // call imported API via PLT at 0xd08c8
    __cxa_rethrow(...); // call imported API via PLT at 0xd08dc
    __cxa_end_catch(...); // call imported API via PLT at 0xd08e4
    sub_CEBC4(...); // call internal func at 0xd08ec
    sub_D0AB4(...); // call internal func at 0xd08fc
    __stack_chk_fail(...); // call imported API via PLT at 0xd0918
}

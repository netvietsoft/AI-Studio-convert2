// Function: MMCodec::MTMediaReader::getAudioSampleBuffer(MMCodec::AICodecSampleBuffer*&, long, MMCodec::ReadOption const&)
// RVA: 0x132bdc, Size: 1856 bytes
int64_t _ZN7MMCodec13MTMediaReader20getAudioSampleBufferERPNS_19AICodecSampleBufferElRKNS_10ReadOptionE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec23AICodecSampleBufferPool6createENS_22AICodecSampleMediaTypeE(...); // call imported API via PLT at 0x132c44
    _ZN7MMCodec13MTMediaReader21releasingSampleBufferERPNS_19AICodecSampleBufferE(...); // call imported API via PLT at 0x132c5c
    _ZN7MMCodec23AICodecSampleBufferPool25createAICodecSampleBufferEv(...); // call imported API via PLT at 0x132c64
    pthread_self(...); // call imported API via PLT at 0x132cb0
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8639a = "[%s(%d)]:> [MTMediaReader(%p)](%ld):> audio track index out of array! use default audio track"; // string xref
    const char* s_6fc3e = "getAudioSampleBuffer"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x132cdc
    pthread_self(...); // call imported API via PLT at 0x132d00
    const char* s_7946d = "%s/MTMV_AICodec: [%s(%d)]:> [MTMediaReader(%p)](%ld):> audio track index out of array! use default audio track
"; // string xref
    const char* s_6fc3e = "getAudioSampleBuffer"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x132d28
    pthread_self(...); // call imported API via PLT at 0x132d58
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_88cc7 = "[%s(%d)]:> [MTMediaReader(%p)](%ld):> kReaderFlagDemuxErr"; // string xref
    const char* s_6fc3e = "getAudioSampleBuffer"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x132d84
    pthread_self(...); // call imported API via PLT at 0x132da8
    const char* s_7aa21 = "%s/MTMV_AICodec: [%s(%d)]:> [MTMediaReader(%p)](%ld):> kReaderFlagDemuxErr
"; // string xref
    const char* s_6fc3e = "getAudioSampleBuffer"; // string xref
    pthread_self(...); // call imported API via PLT at 0x132df0
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6c2d9 = "[%s(%d)]:> [MTMediaReader(%p)](%ld):> kReaderFlagDecodeErr"; // string xref
    const char* s_6fc3e = "getAudioSampleBuffer"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x132e1c
    pthread_self(...); // call imported API via PLT at 0x132e40
    const char* s_7817f = "%s/MTMV_AICodec: [%s(%d)]:> [MTMediaReader(%p)](%ld):> kReaderFlagDecodeErr
"; // string xref
    const char* s_6fc3e = "getAudioSampleBuffer"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x132e68
    return a0;
    pthread_self(...); // call imported API via PLT at 0x132ec0
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_88d01 = "[%s(%d)]:> [MTMediaReader(%p)](%ld):>  didn't start decoder"; // string xref
    const char* s_6fc3e = "getAudioSampleBuffer"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x132eec
    pthread_self(...); // call imported API via PLT at 0x132f10
    const char* s_6b059 = "%s/MTMV_AICodec: [%s(%d)]:> [MTMediaReader(%p)](%ld):>  didn't start decoder
"; // string xref
    const char* s_6fc3e = "getAudioSampleBuffer"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x132f38
    pthread_self(...); // call imported API via PLT at 0x132f64
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6e9ab = "[%s(%d)]:> [MTMediaReader(%p)](%ld):> no audio stream index !"; // string xref
    const char* s_6fc3e = "getAudioSampleBuffer"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x132f90
    pthread_self(...); // call imported API via PLT at 0x132fb4
    const char* s_8634a = "%s/MTMV_AICodec: [%s(%d)]:> [MTMediaReader(%p)](%ld):> no audio stream index !
"; // string xref
    const char* s_6fc3e = "getAudioSampleBuffer"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x132fdc
    _ZN7MMCodec23AICodecSampleBufferPool25createAICodecSampleBufferEv(...); // call imported API via PLT at 0x132ff0
    void* g_2010e3 = (void*)0x2010e3; // global ref
    _ZNK7MMCodec19AICodecSampleBuffer12getFrameDataEv(...); // call imported API via PLT at 0x13300c
    _ZN7MMCodec9FrameData21setOutAudioDataFormatERKNS_12AudioParam_tE(...); // call imported API via PLT at 0x133018
    (*x8)(...); // indirect call at 0x133064
    (*x8)(...); // indirect call at 0x13308c
    _ZN7MMCodec9FrameData24getPresentationTimestampEv(...); // call imported API via PLT at 0x13309c
    _ZN7MMCodec19AICodecSampleBuffer24setPresentationTimestampEl(...); // call imported API via PLT at 0x1330a8
    _ZN7MMCodec9FrameData30getPrimalPresentationTimestampEv(...); // call imported API via PLT at 0x1330b4
    _ZN7MMCodec19AICodecSampleBuffer30setPrimalPresentationTimestampEl(...); // call imported API via PLT at 0x1330c0
    _ZNK7MMCodec19AICodecSampleBuffer13getDataBufferEv(...); // call imported API via PLT at 0x1330c8
    _ZNK7MMCodec28AICodecFFmpegAudioDataBuffer11getDataSizeEv(...); // call imported API via PLT at 0x1330d4
    _ZN7MMCodec9FrameData24getPresentationTimestampEv(...); // call imported API via PLT at 0x1330e0
    (*x9)(...); // indirect call at 0x1330fc
    pthread_self(...); // call imported API via PLT at 0x133148
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7e10b = "[%s(%d)]:> [MTMediaReader(%p)](%ld):> error! audio data is null"; // string xref
    const char* s_6fc3e = "getAudioSampleBuffer"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x133174
    pthread_self(...); // call imported API via PLT at 0x133198
    const char* s_8d4fe = "%s/MTMV_AICodec: [%s(%d)]:> [MTMediaReader(%p)](%ld):> error! audio data is null
"; // string xref
    const char* s_6fc3e = "getAudioSampleBuffer"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1331c0
    (*x8)(...); // indirect call at 0x133200
    _ZN7MMCodec28AICodecFFmpegAudioDataBuffer16resampleByEffectERlPNS_18SpeedEffectManagerEPNS_19MotionEffectManagerE(...); // call imported API via PLT at 0x133228
    _ZN7MMCodec19AICodecSampleBuffer24setPresentationTimestampEl(...); // call imported API via PLT at 0x133238
    _ZN7MMCodec19AICodecSampleBuffer29setReusingOnceGetSampleBufferEb(...); // call imported API via PLT at 0x133248
    pthread_self(...); // call imported API via PLT at 0x133274
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8d550 = "[%s(%d)]:> [MTMediaReader(%p)](%ld):> EffectManager->getAudio failed"; // string xref
    const char* s_6fc3e = "getAudioSampleBuffer"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1332a0
    pthread_self(...); // call imported API via PLT at 0x1332c4
    const char* s_8249e = "%s/MTMV_AICodec: [%s(%d)]:> [MTMediaReader(%p)](%ld):> EffectManager->getAudio failed
"; // string xref
    const char* s_6fc3e = "getAudioSampleBuffer"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1332ec
    _ZN7MMCodec13MTMediaReader21releasingSampleBufferERPNS_19AICodecSampleBufferE(...); // call imported API via PLT at 0x1332fc
    _ZNSt6__ndk118condition_variable10notify_allEv(...); // call imported API via PLT at 0x13330c
    __stack_chk_fail(...); // call imported API via PLT at 0x133318
}

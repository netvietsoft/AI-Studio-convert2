// Function: MMCodec::MTMediaReader::getVideoSampleBuffer(MMCodec::AICodecSampleBuffer*&, long, MMCodec::ReadOption const&)
// RVA: 0x132444, Size: 1944 bytes
int64_t _ZN7MMCodec13MTMediaReader20getVideoSampleBufferERPNS_19AICodecSampleBufferElRKNS_10ReadOptionE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_self(...); // call imported API via PLT at 0x1324a0
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_794dd = "[%s(%d)]:> [MTMediaReader(%p)](%ld):> try restart"; // string xref
    const char* s_7e14b = "getVideoSampleBuffer"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1324cc
    _ZN7MMCodec6AVIRef6retainEv(...); // call imported API via PLT at 0x1324f0
    _ZN7MMCodec13MTMediaReader11stopDecoderEv(...); // call imported API via PLT at 0x1324f8
    _ZN7MMCodec13MTMediaReader12startDecoderEPNS_14AICodecContextEll(...); // call imported API via PLT at 0x132528
    _ZN7MMCodec6AVIRef7releaseEv(...); // call imported API via PLT at 0x132538
    pthread_self(...); // call imported API via PLT at 0x132558
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8b91a = "[%s(%d)]:> [MTMediaReader(%p)](%ld):> restart end"; // string xref
    const char* s_7e14b = "getVideoSampleBuffer"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x132584
    pthread_self(...); // call imported API via PLT at 0x1325a0
    const char* s_8b94c = "%s/MTMV_AICodec: [%s(%d)]:> [MTMediaReader(%p)](%ld):> restart end
"; // string xref
    const char* s_7e14b = "getVideoSampleBuffer"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1325c8
    (*x8)(...); // indirect call at 0x1325fc
    (*x8)(...); // indirect call at 0x13261c
    (*x8)(...); // indirect call at 0x132634
    pthread_self(...); // call imported API via PLT at 0x132660
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_88cc7 = "[%s(%d)]:> [MTMediaReader(%p)](%ld):> kReaderFlagDemuxErr"; // string xref
    const char* s_7e14b = "getVideoSampleBuffer"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x13268c
    pthread_self(...); // call imported API via PLT at 0x1326b0
    const char* s_7aa21 = "%s/MTMV_AICodec: [%s(%d)]:> [MTMediaReader(%p)](%ld):> kReaderFlagDemuxErr
"; // string xref
    const char* s_7e14b = "getVideoSampleBuffer"; // string xref
    pthread_self(...); // call imported API via PLT at 0x1326f8
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6c2d9 = "[%s(%d)]:> [MTMediaReader(%p)](%ld):> kReaderFlagDecodeErr"; // string xref
    const char* s_7e14b = "getVideoSampleBuffer"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x132724
    pthread_self(...); // call imported API via PLT at 0x132748
    const char* s_7817f = "%s/MTMV_AICodec: [%s(%d)]:> [MTMediaReader(%p)](%ld):> kReaderFlagDecodeErr
"; // string xref
    const char* s_7e14b = "getVideoSampleBuffer"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x132770
    return a0;
    pthread_self(...); // call imported API via PLT at 0x1327b4
    const char* s_7950f = "%s/MTMV_AICodec: [%s(%d)]:> [MTMediaReader(%p)](%ld):> try restart
"; // string xref
    const char* s_7e14b = "getVideoSampleBuffer"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1327dc
    pthread_self(...); // call imported API via PLT at 0x13280c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_88d01 = "[%s(%d)]:> [MTMediaReader(%p)](%ld):>  didn't start decoder"; // string xref
    const char* s_7e14b = "getVideoSampleBuffer"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x132838
    pthread_self(...); // call imported API via PLT at 0x13285c
    const char* s_6b059 = "%s/MTMV_AICodec: [%s(%d)]:> [MTMediaReader(%p)](%ld):>  didn't start decoder
"; // string xref
    const char* s_7e14b = "getVideoSampleBuffer"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x132884
    (*x8)(...); // indirect call at 0x1328a0
    (*x8)(...); // indirect call at 0x1328b8
    _ZN7MMCodec23AICodecSampleBufferPool6createENS_22AICodecSampleMediaTypeE(...); // call imported API via PLT at 0x132908
    _ZN7MMCodec13MTMediaReader21releasingSampleBufferERPNS_19AICodecSampleBufferE(...); // call imported API via PLT at 0x132920
    _ZN7MMCodec23AICodecSampleBufferPool25createAICodecSampleBufferEv(...); // call imported API via PLT at 0x132928
    _ZNK7MMCodec19AICodecSampleBuffer12getFrameDataEv(...); // call imported API via PLT at 0x132938
    _ZN7MMCodec9FrameData21setOutVideoDataFormatERKNS_12VideoParam_tE(...); // call imported API via PLT at 0x132944
    (*x8)(...); // indirect call at 0x132964
    _ZN7MMCodec9FrameData24getPresentationTimestampEv(...); // call imported API via PLT at 0x132978
    _ZN7MMCodec19AICodecSampleBuffer24setPresentationTimestampEl(...); // call imported API via PLT at 0x132984
    _ZN7MMCodec9FrameData30getPrimalPresentationTimestampEv(...); // call imported API via PLT at 0x132990
    _ZN7MMCodec19AICodecSampleBuffer30setPrimalPresentationTimestampEl(...); // call imported API via PLT at 0x13299c
    _ZN7MMCodec9FrameData10getFrameIdEv(...); // call imported API via PLT at 0x1329a8
    _ZN7MMCodec19AICodecSampleBuffer6setKeyEPv(...); // call imported API via PLT at 0x1329b4
    _ZNK7MMCodec19AICodecSampleBuffer13getDataBufferEv(...); // call imported API via PLT at 0x1329bc
    _ZN7MMCodec23AICodecSampleBufferPool25createAICodecSampleBufferEv(...); // call imported API via PLT at 0x1329fc
    (*x8)(...); // indirect call at 0x132a40
    (*x8)(...); // indirect call at 0x132a58
    pthread_self(...); // call imported API via PLT at 0x132a78
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6fc53 = "[%s(%d)]:> [MTMediaReader(%p)](%ld):> restart failed"; // string xref
    const char* s_7e14b = "getVideoSampleBuffer"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x132aa4
    pthread_self(...); // call imported API via PLT at 0x132ac0
    const char* s_67cfd = "%s/MTMV_AICodec: [%s(%d)]:> [MTMediaReader(%p)](%ld):> restart failed
"; // string xref
    const char* s_7e14b = "getVideoSampleBuffer"; // string xref
    (*x8)(...); // indirect call at 0x132b18
    (*x8)(...); // indirect call at 0x132b30
    (*x8)(...); // indirect call at 0x132b8c
    _ZN7MMCodec19AICodecSampleBuffer29setReusingOnceGetSampleBufferEb(...); // call imported API via PLT at 0x132bb0
    _ZN7MMCodec13MTMediaReader21releasingSampleBufferERPNS_19AICodecSampleBufferE(...); // call imported API via PLT at 0x132bc0
    _ZNSt6__ndk118condition_variable10notify_allEv(...); // call imported API via PLT at 0x132bd0
}

// Function: MMCodec::MTMediaReader::getSampleBuffer(MMCodec::AICodecSampleBuffer*&, long, MMCodec::ReadOption const&)
// RVA: 0x132348, Size: 252 bytes
int64_t _ZN7MMCodec13MTMediaReader15getSampleBufferERPNS_19AICodecSampleBufferElRKNS_10ReadOptionE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec13MTMediaReader20getVideoSampleBufferERPNS_19AICodecSampleBufferElRKNS_10ReadOptionE(...); // call imported API via PLT at 0x132374
    pthread_self(...); // call imported API via PLT at 0x13239c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7a995 = "[%s(%d)]:> [MTMediaReader(%p)](%ld):>  didn't open media file"; // string xref
    const char* s_862f5 = "getSampleBuffer"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1323c8
    pthread_self(...); // call imported API via PLT at 0x1323ec
    const char* s_7941d = "%s/MTMV_AICodec: [%s(%d)]:> [MTMediaReader(%p)](%ld):>  didn't open media file
"; // string xref
    const char* s_862f5 = "getSampleBuffer"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x132414
    return a0;
    _ZN7MMCodec13MTMediaReader20getAudioSampleBufferERPNS_19AICodecSampleBufferElRKNS_10ReadOptionE(...); // call imported API via PLT at 0x132430
    return a0;
}

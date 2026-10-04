// Function: MMCodec::MTMediaReader::getAudioFrame(MMCodec::ReadOption, unsigned char*&, MMCodec::FrameInfo&)
// RVA: 0x13379c, Size: 208 bytes
int64_t _ZN7MMCodec13MTMediaReader13getAudioFrameENS_10ReadOptionERPhRNS_9FrameInfoE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec13MTMediaReader15getSampleBufferERPNS_19AICodecSampleBufferElRKNS_10ReadOptionE(...); // call imported API via PLT at 0x1337d8
    _ZNK7MMCodec19AICodecSampleBuffer13getDataBufferEv(...); // call imported API via PLT at 0x1337ec
    _ZNK7MMCodec19AICodecSampleBuffer24getPresentationTimestampEv(...); // call imported API via PLT at 0x1337fc
    _ZNK7MMCodec19AICodecSampleBuffer30getPrimalPresentationTimestampEv(...); // call imported API via PLT at 0x13380c
    _ZNK7MMCodec28AICodecFFmpegAudioDataBuffer18getAudioBufferSizeEv(...); // call imported API via PLT at 0x133818
    _ZNK7MMCodec28AICodecFFmpegAudioDataBuffer14getAudioBufferEv(...); // call imported API via PLT at 0x133824
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x133868
}

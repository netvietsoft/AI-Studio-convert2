// Function: MMCodec::SectionFormatContext::_readPacket(AVPacket*, int)
// RVA: 0x14b35c, Size: 520 bytes
int64_t _ZN7MMCodec20SectionFormatContext11_readPacketEP8AVPacketi(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    return a0;
    _ZN7MMCodec13FormatContext10readPacketEP8AVPacketi(...); // call imported API via PLT at 0x14b3c0
    av_packet_unref(...); // call imported API via PLT at 0x14b40c
    av_packet_unref(...); // call imported API via PLT at 0x14b450
    _ZN7MMCodec8protocol14parseFrameTypeEPhiiRiS2_(...); // call imported API via PLT at 0x14b4c0
    __stack_chk_fail(...); // call imported API via PLT at 0x14b560
}

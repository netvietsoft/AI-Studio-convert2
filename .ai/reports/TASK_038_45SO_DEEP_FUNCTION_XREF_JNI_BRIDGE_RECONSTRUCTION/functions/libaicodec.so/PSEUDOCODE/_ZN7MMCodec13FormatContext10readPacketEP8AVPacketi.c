// Function: MMCodec::FormatContext::readPacket(AVPacket*, int)
// RVA: 0x149a40, Size: 196 bytes
int64_t _ZN7MMCodec13FormatContext10readPacketEP8AVPacketi(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    av_read_frame(...); // call imported API via PLT at 0x149a64
    av_packet_unref(...); // call imported API via PLT at 0x149a7c
    av_read_frame(...); // call imported API via PLT at 0x149a88
    _ZN7MMCodec23getErrorCodeWithAVErrorEi(...); // call imported API via PLT at 0x149a90
    return a0;
    av_get_time_base_q(...); // call imported API via PLT at 0x149ac0
    av_rescale_q(...); // call imported API via PLT at 0x149adc
    return a0;
}

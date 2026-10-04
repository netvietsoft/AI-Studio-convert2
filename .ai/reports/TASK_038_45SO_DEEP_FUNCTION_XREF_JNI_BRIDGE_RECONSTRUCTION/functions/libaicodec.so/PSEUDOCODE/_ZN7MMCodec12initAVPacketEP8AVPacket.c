// Function: MMCodec::initAVPacket(AVPacket*)
// RVA: 0x163014, Size: 44 bytes
int64_t _ZN7MMCodec12initAVPacketEP8AVPacket(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    av_init_packet(...); // call imported API via PLT at 0x163028
    return a0;
}

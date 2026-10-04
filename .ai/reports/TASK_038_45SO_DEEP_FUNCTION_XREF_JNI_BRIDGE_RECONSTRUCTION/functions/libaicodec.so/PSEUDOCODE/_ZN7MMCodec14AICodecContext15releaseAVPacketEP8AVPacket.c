// Function: MMCodec::AICodecContext::releaseAVPacket(AVPacket*)
// RVA: 0x123820, Size: 56 bytes
int64_t _ZN7MMCodec14AICodecContext15releaseAVPacketEP8AVPacket(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    av_packet_unref(...); // call imported API via PLT at 0x12383c
    _ZN7MMCodec10ObjectPoolI8AVPacketE14release_objectERS1_(...); // call imported API via PLT at 0x123850
    return a0;
}

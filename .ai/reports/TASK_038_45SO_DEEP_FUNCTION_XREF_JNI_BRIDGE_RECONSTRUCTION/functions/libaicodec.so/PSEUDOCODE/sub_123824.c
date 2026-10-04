// Function: sub_123824
// RVA: 0x123824, Size: 52 bytes
int64_t sub_123824(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    av_packet_unref(...); // call imported API via PLT at 0x12383c
    _ZN7MMCodec10ObjectPoolI8AVPacketE14release_objectERS1_(...); // call imported API via PLT at 0x123850
    return a0;
}

// Function: MMCodec::StreamBase::seek_V1(long, MMCodec::SeekMode_t)
// RVA: 0x1513d4, Size: 108 bytes
int64_t _ZN7MMCodec10StreamBase7seek_V1ElNS_10SeekMode_tE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...); // indirect call at 0x151404
    _ZN7MMCodec10FrameQueue10setEofFlagEb(...); // call imported API via PLT at 0x151424
    _ZNSt6__ndk118condition_variable10notify_allEv(...); // call imported API via PLT at 0x15142c
    return a0;
}

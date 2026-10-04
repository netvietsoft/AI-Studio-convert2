// Function: MMCodec::AICodecContext::releaseResource()
// RVA: 0x123068, Size: 48 bytes
int64_t _ZN7MMCodec14AICodecContext15releaseResourceEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec10ObjectPoolINS_12MMCodecFrameEE5clearEv(...); // call imported API via PLT at 0x12307c
    _ZN7MMCodec10ObjectPoolI7AVFrameE5clearEv(...); // call imported API via PLT at 0x123084
    _ZN7MMCodec10ObjectPoolI8AVPacketE5clearEv(...); // call imported API via PLT at 0x123094
}

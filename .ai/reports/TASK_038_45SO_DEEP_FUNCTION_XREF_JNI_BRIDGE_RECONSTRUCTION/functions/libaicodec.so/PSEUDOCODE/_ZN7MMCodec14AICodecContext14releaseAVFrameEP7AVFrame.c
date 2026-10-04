// Function: MMCodec::AICodecContext::releaseAVFrame(AVFrame*)
// RVA: 0x1234e0, Size: 56 bytes
int64_t _ZN7MMCodec14AICodecContext14releaseAVFrameEP7AVFrame(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    av_frame_unref(...); // call imported API via PLT at 0x1234fc
    _ZN7MMCodec10ObjectPoolI7AVFrameE14release_objectERS1_(...); // call imported API via PLT at 0x123510
    return a0;
}

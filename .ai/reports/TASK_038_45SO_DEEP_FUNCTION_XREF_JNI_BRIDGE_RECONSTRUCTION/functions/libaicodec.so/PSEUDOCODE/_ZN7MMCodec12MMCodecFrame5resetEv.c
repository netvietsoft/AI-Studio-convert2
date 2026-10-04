// Function: MMCodec::MMCodecFrame::reset()
// RVA: 0x1260c4, Size: 128 bytes
int64_t _ZN7MMCodec12MMCodecFrame5resetEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x1260d8
    av_frame_unref(...); // call imported API via PLT at 0x1260ec
    _ZN7MMCodec14AICodecContext14releaseAVFrameEP7AVFrame(...); // call imported API via PLT at 0x126100
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x12612c
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x126138
}

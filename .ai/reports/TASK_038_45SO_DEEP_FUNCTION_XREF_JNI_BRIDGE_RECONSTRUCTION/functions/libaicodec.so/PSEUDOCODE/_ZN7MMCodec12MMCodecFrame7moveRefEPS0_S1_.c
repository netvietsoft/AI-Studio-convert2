// Function: MMCodec::MMCodecFrame::moveRef(MMCodec::MMCodecFrame*, MMCodec::MMCodecFrame*)
// RVA: 0x125fdc, Size: 232 bytes
int64_t _ZN7MMCodec12MMCodecFrame7moveRefEPS0_S1_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    av_frame_move_ref(...); // call imported API via PLT at 0x126020
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x126038
    av_frame_unref(...); // call imported API via PLT at 0x12604c
    _ZN7MMCodec14AICodecContext14releaseAVFrameEP7AVFrame(...); // call imported API via PLT at 0x126060
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x126084
    return a0;
    return a0;
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x1260b8
}

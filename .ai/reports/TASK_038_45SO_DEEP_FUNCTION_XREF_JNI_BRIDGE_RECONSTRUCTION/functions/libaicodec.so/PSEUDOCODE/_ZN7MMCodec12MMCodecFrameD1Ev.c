// Function: MMCodec::MMCodecFrame::~MMCodecFrame()
// RVA: 0x126184, Size: 160 bytes
int64_t _ZN7MMCodec12MMCodecFrameD1Ev(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    void* g_202010 = (void*)0x202010; // global ref
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x1261ac
    av_frame_unref(...); // call imported API via PLT at 0x1261c0
    _ZN7MMCodec14AICodecContext14releaseAVFrameEP7AVFrame(...); // call imported API via PLT at 0x1261d4
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x1261f8
    _ZNSt6__ndk15mutexD1Ev(...); // call imported API via PLT at 0x126208
    sub_CEBC4(...); // call internal func at 0x12620c
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x126218
    sub_CEBC4(...); // call internal func at 0x126220
}

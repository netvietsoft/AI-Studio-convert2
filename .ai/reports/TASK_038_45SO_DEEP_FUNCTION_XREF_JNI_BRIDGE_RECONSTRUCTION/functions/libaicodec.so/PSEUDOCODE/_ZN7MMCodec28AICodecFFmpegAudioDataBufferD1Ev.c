// Function: MMCodec::AICodecFFmpegAudioDataBuffer::~AICodecFFmpegAudioDataBuffer()
// RVA: 0x128974, Size: 148 bytes
int64_t _ZN7MMCodec28AICodecFFmpegAudioDataBufferD1Ev(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    void* g_202010 = (void*)0x202010; // global ref
    av_frame_unref(...); // call imported API via PLT at 0x1289a0
    av_frame_free(...); // call imported API via PLT at 0x1289a8
    av_free(...); // call imported API via PLT at 0x1289bc
    (*x8)(...); // indirect call at 0x1289d0
    _ZdlPv(...); // call imported API via PLT at 0x1289e0
    _ZdlPv(...); // call imported API via PLT at 0x1289f0
    return a0;
    sub_CEBC4(...); // call internal func at 0x128a04
}

// Function: MMCodec::AICodecFFmpegPixelDataBuffer::~AICodecFFmpegPixelDataBuffer()
// RVA: 0x1295a0, Size: 220 bytes
int64_t _ZN7MMCodec28AICodecFFmpegPixelDataBufferD1Ev(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    void* g_202010 = (void*)0x202010; // global ref
    sws_freeContext(...); // call imported API via PLT at 0x1295c8
    av_frame_unref(...); // call imported API via PLT at 0x1295dc
    av_frame_free(...); // call imported API via PLT at 0x1295e4
    av_free(...); // call imported API via PLT at 0x1295f0
    void* g_202010 = (void*)0x202010; // global ref
    (*x8)(...); // indirect call at 0x129618
    (*x8)(...); // indirect call at 0x129630
    (*x8)(...); // indirect call at 0x129648
    return a0;
    sub_CEBC4(...); // call internal func at 0x129678
}

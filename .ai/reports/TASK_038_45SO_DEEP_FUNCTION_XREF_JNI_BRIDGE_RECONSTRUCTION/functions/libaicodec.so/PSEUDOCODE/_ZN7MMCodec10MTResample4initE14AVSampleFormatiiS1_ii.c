// Function: MMCodec::MTResample::init(AVSampleFormat, int, int, AVSampleFormat, int, int)
// RVA: 0x168648, Size: 204 bytes
int64_t _ZN7MMCodec10MTResample4initE14AVSampleFormatiiS1_ii(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _Znwm(...); // call imported API via PLT at 0x16867c
    av_channel_layout_uninit(...); // call imported API via PLT at 0x16868c
    av_channel_layout_default(...); // call imported API via PLT at 0x168698
    av_channel_layout_uninit(...); // call imported API via PLT at 0x1686ac
    av_channel_layout_copy(...); // call imported API via PLT at 0x1686b8
    const char* s_6fd58 = "Failed to copy channel layout.
";
    void* g_202130 = (void*)0x202130; // global ref
    fwrite(...); // call imported API via PLT at 0x1686dc
    _ZN7MMCodec14FFmpegResample20setTargetAudioParamsE14AVSampleFormatii(...); // call imported API via PLT at 0x168710
}

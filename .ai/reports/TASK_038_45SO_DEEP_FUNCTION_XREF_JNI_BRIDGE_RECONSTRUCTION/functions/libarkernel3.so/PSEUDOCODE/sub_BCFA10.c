// Function: sub_BCFA10
// RVA: 0xbcfa10, Size: 1288 bytes
int64_t sub_BCFA10(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    wgpuTextureGetUsage(...); // call imported API via PLT at 0xbcfa54
    av_frame_unref(...); // call imported API via PLT at 0xbcfa80
    av_hwframe_map(...); // call imported API via PLT at 0xbcfaa0
    av_strerror(...); // call imported API via PLT at 0xbcfac4
    sub_5604D4(...); // call internal func at 0xbcfad4
    const char* s_2173cc = "av_hwframe_map Error({}): {}"; // string xref
    sub_BBF2EC(...); // call internal func at 0xbcfb38
    sub_B29828(...); // call internal func at 0xbcfb44
    free(...); // call imported API via PLT at 0xbcfb54
    _ZdlPv(...); // call imported API via PLT at 0xbcfb64
    const char* s_228cfc = "WGPUHwAccel"; // string xref
    const char* s_1eaa4e = "%s"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xbcfb94
    _ZdlPv(...); // call imported API via PLT at 0xbcfba4
    av_hwframe_transfer_data(...); // call imported API via PLT at 0xbcfbb8
    av_get_pix_fmt_name(...); // call imported API via PLT at 0xbcfbc8
    av_get_pix_fmt_name(...); // call imported API via PLT at 0xbcfbd8
    av_strerror(...); // call imported API via PLT at 0xbcfbfc
    sub_5604D4(...); // call internal func at 0xbcfc0c
    const char* s_1c46a5 = "null"; // string xref
    const char* s_1b9a7f = "Error: {}, transferring the data to system memory, sw format: {}, frame format: {}"; // string xref
    sub_BBF2EC(...); // call internal func at 0xbcfc8c
    sub_B29828(...); // call internal func at 0xbcfc98
    free(...); // call imported API via PLT at 0xbcfca8
    _ZdlPv(...); // call imported API via PLT at 0xbcfcb8
    const char* s_228cfc = "WGPUHwAccel"; // string xref
    const char* s_1eaa4e = "%s"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xbcfce8
    void* g_28c020 = (void*)0x28c020; // global ref
    const char* s_23b799 = "Texture usage is not WGPUTextureUsage_CopyDst & WGPUTextureUsage_RenderAttachment"; // string xref
    sub_BBF2EC(...); // call internal func at 0xbcfd3c
    sub_B29828(...); // call internal func at 0xbcfd48
    free(...); // call imported API via PLT at 0xbcfd58
    const char* s_228cfc = "WGPUHwAccel"; // string xref
    const char* s_1eaa4e = "%s"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xbcfd88
    _ZdlPv(...); // call imported API via PLT at 0xbcfd98
    sub_BCF944(...); // call internal func at 0xbcfdb8
    sub_BCF304(...); // call internal func at 0xbcfdc8
    sub_BCFF18(...); // call internal func at 0xbcfdd0
    sub_BCFFC4(...); // call internal func at 0xbcfe08
    wgpuBufferUnmap(...); // call imported API via PLT at 0xbcfe30
    sub_BD00E8(...); // call internal func at 0xbcfe40
    return a0;
    free(...); // call imported API via PLT at 0xbcfeb8
    _ZdlPv(...); // call imported API via PLT at 0xbcfedc
    free(...); // call imported API via PLT at 0xbcfef8
    __stack_chk_fail(...); // call imported API via PLT at 0xbcff14
}

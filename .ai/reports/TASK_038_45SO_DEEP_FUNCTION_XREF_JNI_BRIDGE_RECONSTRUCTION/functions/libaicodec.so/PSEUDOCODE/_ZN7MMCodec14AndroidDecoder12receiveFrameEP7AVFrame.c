// Function: MMCodec::AndroidDecoder::receiveFrame(AVFrame*)
// RVA: 0xfb004, Size: 812 bytes
int64_t _ZN7MMCodec14AndroidDecoder12receiveFrameEP7AVFrame(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN9JniHelper6getEnvEv(...); // call imported API via PLT at 0xfb034
    _ZN7_JNIEnv13CallIntMethodEP8_jobjectP10_jmethodIDz(...); // call imported API via PLT at 0xfb074
    (*x8)(...); // indirect call at 0xfb09c
    _ZN7_JNIEnv13CallIntMethodEP8_jobjectP10_jmethodIDz(...); // call imported API via PLT at 0xfb0e4
    av_gettime_relative(...); // call imported API via PLT at 0xfb0fc
    void* g_201001 = (void*)0x201001; // global ref
    (*x9)(...); // indirect call at 0xfb148
    (*x8)(...); // indirect call at 0xfb16c
    _ZN7MMCodec10FrameQueue15leftBufferFrameEv(...); // call imported API via PLT at 0xfb1a0
    _ZN7_JNIEnv13CallIntMethodEP8_jobjectP10_jmethodIDz(...); // call imported API via PLT at 0xfb1c8
    (*x8)(...); // indirect call at 0xfb1f0
    (*x8)(...); // indirect call at 0xfb228
    _ZN7MMCodec13AICodecGlobal11getInstanceEv(...); // call imported API via PLT at 0xfb234
    _ZN7MMCodec13AICodecGlobal11getHardwareEv(...); // call imported API via PLT at 0xfb238
    const char* s_7c9c5 = "mt6895"; // string xref
    sub_FB330(...); // call internal func at 0xfb244
    _ZN7MMCodec10FrameQueue12peekWritableERPNS_12MMCodecFrameE(...); // call imported API via PLT at 0xfb26c
    (*x8)(...); // indirect call at 0xfb298
    _ZN7_JNIEnv13CallIntMethodEP8_jobjectP10_jmethodIDz(...); // call imported API via PLT at 0xfb2c0
    av_get_time_base_q(...); // call imported API via PLT at 0xfb2e0
    av_rescale_q(...); // call imported API via PLT at 0xfb2f0
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0xfb32c
}

// Function: MMCodec::AndroidDecoder::sendPacket(AVPacket*)
// RVA: 0xfa464, Size: 1928 bytes
int64_t _ZN7MMCodec14AndroidDecoder10sendPacketEP8AVPacket(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN9JniHelper6getEnvEv(...); // call imported API via PLT at 0xfa498
    _ZN7MMCodec8protocol14parseFrameTypeEPhiiRiS2_(...); // call imported API via PLT at 0xfa4d4
    av_get_time_base_q(...); // call imported API via PLT at 0xfa4e8
    av_rescale_q(...); // call imported API via PLT at 0xfa4f8
    (*x8)(...); // indirect call at 0xfa6bc
    (*x8)(...); // indirect call at 0xfa6e4
    (*x8)(...); // indirect call at 0xfa6fc
    return a0;
    (*x8)(...); // indirect call at 0xfa7d0
    (*x8)(...); // indirect call at 0xfa85c
    (*x8)(...); // indirect call at 0xfa874
    (*x8)(...); // indirect call at 0xfa894
    _ZN7_JNIEnv13CallIntMethodEP8_jobjectP10_jmethodIDz(...); // call imported API via PLT at 0xfa8ac
    (*x8)(...); // indirect call at 0xfa8d4
    (*x8)(...); // indirect call at 0xfa8f0
    (*x8)(...); // indirect call at 0xfa914
    memcpy(...); // call imported API via PLT at 0xfa92c
    (*x8)(...); // indirect call at 0xfa95c
    (*x8)(...); // indirect call at 0xfa988
    (*x8)(...); // indirect call at 0xfa9ac
    (*x8)(...); // indirect call at 0xfa9d0
    (*x8)(...); // indirect call at 0xfa9f4
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_71494 = "[%s(%d)]:> send csd buffer failed %d"; // string xref
    const char* s_67628 = "sendPacket"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xfaa40
    const char* s_7c98e = "%s/MTMV_AICodec: [%s(%d)]:> send csd buffer failed %d
"; // string xref
    const char* s_67628 = "sendPacket"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xfaa80
    (*x8)(...); // indirect call at 0xfaa9c
    _ZN7_JNIEnv13CallIntMethodEP8_jobjectP10_jmethodIDz(...); // call imported API via PLT at 0xfaab8
    _ZN7_JNIEnv13CallIntMethodEP8_jobjectP10_jmethodIDz(...); // call imported API via PLT at 0xfaad4
    av_gettime_relative(...); // call imported API via PLT at 0xfaaf0
    (*x8)(...); // indirect call at 0xfaba0
    (*x8)(...); // indirect call at 0xfabc0
    __stack_chk_fail(...); // call imported API via PLT at 0xfabe8
}

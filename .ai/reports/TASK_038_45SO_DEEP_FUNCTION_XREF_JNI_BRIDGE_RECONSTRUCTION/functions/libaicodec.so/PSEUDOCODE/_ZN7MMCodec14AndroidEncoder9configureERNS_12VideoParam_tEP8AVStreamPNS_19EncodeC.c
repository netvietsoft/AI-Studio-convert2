// Function: MMCodec::AndroidEncoder::configure(MMCodec::VideoParam_t&, AVStream*, MMCodec::EncodeConfigureInfo*)
// RVA: 0xeef80, Size: 3472 bytes
int64_t _ZN7MMCodec14AndroidEncoder9configureERNS_12VideoParam_tEP8AVStreamPNS_19EncodeConfigureInfoE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN9JniHelper6getEnvEv(...); // call imported API via PLT at 0xeefc0
    (*x8)(...); // indirect call at 0xeefd8
    memcpy(...); // call imported API via PLT at 0xeefec
    const char* s_7a326 = "video/hevc"; // string xref
    (*x8)(...); // indirect call at 0xef018
    _ZN7_JNIEnv22CallStaticObjectMethodEP7_jclassP10_jmethodIDz(...); // call imported API via PLT at 0xef044
    const char* s_90bfa = "mtk"; // string xref
    (*x8)(...); // indirect call at 0xef064
    _ZN7_JNIEnv17CallBooleanMethodEP8_jobjectP10_jmethodIDz(...); // call imported API via PLT at 0xef084
    (*x8)(...); // indirect call at 0xef0ec
    (*x8)(...); // indirect call at 0xef100
    (*x8)(...); // indirect call at 0xef118
    (*x8)(...); // indirect call at 0xef170
    (*x8)(...); // indirect call at 0xef188
    const char* s_840a6 = "configure"; // string xref
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_69947 = "[%s(%d)]:> %s::initMediaFormat error!"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xef1d0
    const char* s_840a6 = "configure"; // string xref
    const char* s_6a9db = "%s/MTMV_AICodec: [%s(%d)]:> %s::initMediaFormat error!
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xef210
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_81b83 = "[%s(%d)]:> in parameter is invalid"; // string xref
    const char* s_840a6 = "configure"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xef258
    const char* s_82ede = "%s/MTMV_AICodec: [%s(%d)]:> in parameter is invalid
"; // string xref
    const char* s_840a6 = "configure"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xef294
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_8f8e3 = "[%s(%d)]:> getEnv error!"; // string xref
    const char* s_840a6 = "configure"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xef2dc
    const char* s_78dea = "%s/MTMV_AICodec: [%s(%d)]:> getEnv error!
"; // string xref
    const char* s_840a6 = "configure"; // string xref
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_8f8fc = "[%s(%d)]:> _initKeyValue error!"; // string xref
    const char* s_840a6 = "configure"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xef354
    const char* s_88465 = "%s/MTMV_AICodec: [%s(%d)]:> _initKeyValue error!
"; // string xref
    const char* s_840a6 = "configure"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xef390
    return a0;
    (*x8)(...); // indirect call at 0xef3d4
    _ZN7_JNIEnv13CallIntMethodEP8_jobjectP10_jmethodIDz(...); // call imported API via PLT at 0xef3f8
    (*x8)(...); // indirect call at 0xef418
    const char* s_6bb8b = "mime"; // string xref
    (*x8)(...); // indirect call at 0xef434
    _ZN7_JNIEnv16CallObjectMethodEP8_jobjectP10_jmethodIDz(...); // call imported API via PLT at 0xef454
    const char* s_8c800 = "profile"; // string xref
    (*x8)(...); // indirect call at 0xef480
    (*x8)(...); // indirect call at 0xef494
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_6996d = "[%s(%d)]:> check exception before get profile"; // string xref
    const char* s_840a6 = "configure"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xef4dc
    const char* s_75ee4 = "%s/MTMV_AICodec: [%s(%d)]:> check exception before get profile
"; // string xref
    const char* s_840a6 = "configure"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xef518
    (*x8)(...); // indirect call at 0xef528
    _ZN7_JNIEnv13CallIntMethodEP8_jobjectP10_jmethodIDz(...); // call imported API via PLT at 0xef53c
    (*x8)(...); // indirect call at 0xef550
    (*x8)(...); // indirect call at 0xef568
    const char* s_7a326 = "video/hevc"; // string xref
    (*x8)(...); // indirect call at 0xef594
    _ZN7_JNIEnv17CallBooleanMethodEP8_jobjectP10_jmethodIDz(...); // call imported API via PLT at 0xef5b4
    avcodec_get_name(...); // call imported API via PLT at 0xef5c4
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc(...); // call imported API via PLT at 0xef5d0
    sub_EFEE4(...); // call internal func at 0xef5dc
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_(...); // call imported API via PLT at 0xef5e8
    const char* s_840a6 = "configure"; // string xref
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_75ec2 = "[%s(%d)]:> %s::new encoder error!"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xef630
    const char* s_840a6 = "configure"; // string xref
    const char* s_7a2f2 = "%s/MTMV_AICodec: [%s(%d)]:> %s::new encoder error!
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xef670
    avcodec_get_name(...); // call imported API via PLT at 0xef680
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc(...); // call imported API via PLT at 0xef68c
    sub_EFFE0(...); // call internal func at 0xef698
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_(...); // call imported API via PLT at 0xef6a4
    _ZdlPv(...); // call imported API via PLT at 0xef6b4
    void* g_201001 = (void*)0x201001; // global ref
    av_strlcpy(...); // call imported API via PLT at 0xef6ec
    void* g_201001 = (void*)0x201001; // global ref
    av_strlcpy(...); // call imported API via PLT at 0xef724
    (*x8)(...); // indirect call at 0xef73c
    _ZdlPv(...); // call imported API via PLT at 0xef75c
    _ZdlPv(...); // call imported API via PLT at 0xef76c
    (*x8)(...); // indirect call at 0xef784
    const char* s_6e3a5 = "frame-rate"; // string xref
    (*x8)(...); // indirect call at 0xef79c
    const char* s_88497 = "i-frame-interval"; // string xref
    (*x8)(...); // indirect call at 0xef7bc
    const char* s_68627 = "bitrate"; // string xref
    (*x8)(...); // indirect call at 0xef7d8
    _ZN7_JNIEnv13CallIntMethodEP8_jobjectP10_jmethodIDz(...); // call imported API via PLT at 0xef7f0
    _ZN7_JNIEnv13CallIntMethodEP8_jobjectP10_jmethodIDz(...); // call imported API via PLT at 0xef808
    _ZN7_JNIEnv13CallIntMethodEP8_jobjectP10_jmethodIDz(...); // call imported API via PLT at 0xef824
    (*x8)(...); // indirect call at 0xef850
    (*x8)(...); // indirect call at 0xef870
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2B8ne180000ILi0EEEPKc(...); // call imported API via PLT at 0xef880
    void* g_201001 = (void*)0x201001; // global ref
    av_strlcpy(...); // call imported API via PLT at 0xef8b4
    _ZdlPv(...); // call imported API via PLT at 0xef8c4
    _ZN7_JNIEnv16CallObjectMethodEP8_jobjectP10_jmethodIDz(...); // call imported API via PLT at 0xef8dc
    (*x8)(...); // indirect call at 0xef8fc
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2B8ne180000ILi0EEEPKc(...); // call imported API via PLT at 0xef90c
    void* g_201001 = (void*)0x201001; // global ref
    av_strlcpy(...); // call imported API via PLT at 0xef940
    _ZdlPv(...); // call imported API via PLT at 0xef950
    (*x8)(...); // indirect call at 0xef964
    (*x8)(...); // indirect call at 0xef97c
    (*x8)(...); // indirect call at 0xef994
    (*x8)(...); // indirect call at 0xef9b4
    (*x8)(...); // indirect call at 0xef9cc
    (*x8)(...); // indirect call at 0xef9e4
    (*x8)(...); // indirect call at 0xef9fc
    (*x8)(...); // indirect call at 0xefa20
    sub_CEBC4(...); // call internal func at 0xefa34
    sub_CEBC4(...); // call internal func at 0xefa38
    _ZdlPv(...); // call imported API via PLT at 0xefa4c
    sub_CEBC4(...); // call internal func at 0xefa58
    sub_CEBC4(...); // call internal func at 0xefa5c
    sub_CEBC4(...); // call internal func at 0xefa60
    sub_CEBC4(...); // call internal func at 0xefa64
    sub_CEBC4(...); // call internal func at 0xefa68
    sub_CEBC4(...); // call internal func at 0xefa6c
    sub_CEBC4(...); // call internal func at 0xefa70
    _ZdlPv(...); // call imported API via PLT at 0xefa84
    _ZdlPv(...); // call imported API via PLT at 0xefa9c
    (*x8)(...); // indirect call at 0xefb10
    sub_CEBC4(...); // call internal func at 0xefb1c
    (*x8)(...); // indirect call at 0xefb34
    (*x8)(...); // indirect call at 0xefb4c
    (*x8)(...); // indirect call at 0xefb64
    (*x8)(...); // indirect call at 0xefb80
    sub_CEBC4(...); // call internal func at 0xefb90
    sub_CEBC4(...); // call internal func at 0xefb94
    sub_CEBC4(...); // call internal func at 0xefba4
    sub_CEBC4(...); // call internal func at 0xefba8
    sub_CEBC4(...); // call internal func at 0xefbac
    sub_CEBC4(...); // call internal func at 0xefbb0
    (*x8)(...); // indirect call at 0xefbd8
    _ZdlPv(...); // call imported API via PLT at 0xefbf8
    _ZdlPv(...); // call imported API via PLT at 0xefc08
    (*x8)(...); // indirect call at 0xefc20
    (*x8)(...); // indirect call at 0xefc34
    (*x8)(...); // indirect call at 0xefc50
    sub_CEBC4(...); // call internal func at 0xefc58
    sub_CEBC4(...); // call internal func at 0xefc5c
    sub_CEBC4(...); // call internal func at 0xefc60
    sub_CEBC4(...); // call internal func at 0xefc64
    sub_CEBC4(...); // call internal func at 0xefc68
    (*x8)(...); // indirect call at 0xefc84
    sub_CEBC4(...); // call internal func at 0xefc8c
    (*x8)(...); // indirect call at 0xefca4
    sub_CEBC4(...); // call internal func at 0xefcac
    (*x8)(...); // indirect call at 0xefcc4
    (*x8)(...); // indirect call at 0xefce4
    __stack_chk_fail(...); // call imported API via PLT at 0xefd00
    sub_CEBC4(...); // call internal func at 0xefd04
    sub_CEBC4(...); // call internal func at 0xefd08
    sub_CEBC4(...); // call internal func at 0xefd0c
}

// Function: sub_BBDAE8
// RVA: 0xbbdae8, Size: 444 bytes
int64_t sub_BBDAE8(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    avcodec_get_hw_config(...); // call PLT API at 0xbbdb20
    avcodec_get_hw_config(...); // call PLT API at 0xbbdb48
    av_hwdevice_get_type_name(...); // call PLT API at 0xbbdb58
    const char* str = "unknown";
    const char* str = "Decoder {} does not support device type {}.";
    sub_BBF2EC(...); // call internal at 0xbbdbb8
    sub_B29828(...); // call internal at 0xbbdbc4
    free(...); // call PLT API at 0xbbdbd4
    const char* str = "WGPUHwAccel";
    const char* str = "%s";
    __android_log_print(...); // call PLT API at 0xbbdc04
    _ZdlPv(...); // call PLT API at 0xbbdc14
    return a0;
    _ZdlPv(...); // call PLT API at 0xbbdc68
    free(...); // call PLT API at 0xbbdc84
    sub_106B814(...); // call internal at 0xbbdc9c
    __stack_chk_fail(...); // call PLT API at 0xbbdca0
}

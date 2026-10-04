// Function: MMCodec::AICodecOpenGLTextureDataBuffer::transferAndWrite(AVFrame*, MMCodec::VIDEO_PIX_FORMAT)
// RVA: 0x12acf8, Size: 688 bytes
int64_t _ZN7MMCodec30AICodecOpenGLTextureDataBuffer16transferAndWriteEP7AVFrameNS_16VIDEO_PIX_FORMATE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec16OpenGLHWSContext6createEiiNS_16VIDEO_PIX_FORMATEiiS1_(...); // call imported API via PLT at 0x12ad68
    _ZN7MMCodec16OpenGLHWSContext12setHWUtilityEPNS_9HWUtilityE(...); // call imported API via PLT at 0x12ad7c
    _ZN7MMCodec16OpenGLHWSContext20setColorspaceDetailsEiiii(...); // call imported API via PLT at 0x12ad94
    glGenTextures(...); // call imported API via PLT at 0x12adb0
    _ZN7MMCodec2GL13bindTexture2DEj(...); // call imported API via PLT at 0x12adb8
    glTexParameteri(...); // call imported API via PLT at 0x12adc8
    glTexParameteri(...); // call imported API via PLT at 0x12add8
    glTexParameteri(...); // call imported API via PLT at 0x12ade8
    glTexParameteri(...); // call imported API via PLT at 0x12adf8
    glTexImage2D(...); // call imported API via PLT at 0x12ae20
    _ZN7MMCodec16OpenGLHWSContext8transferEPKPKhPiPKPhS5_(...); // call imported API via PLT at 0x12ae50
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6c19e = "[%s(%d)]:> HWUtility is missing for AV_PIX_FMT_CUDA"; // string xref
    const char* s_6fb97 = "transferAndWrite"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x12aeac
    const char* s_7bc28 = "%s/MTMV_AICodec: [%s(%d)]:> HWUtility is missing for AV_PIX_FMT_CUDA
"; // string xref
    const char* s_6fb97 = "transferAndWrite"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7f31c = "[%s(%d)]:> OpenGLHWSContext create failed"; // string xref
    const char* s_6fb97 = "transferAndWrite"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x12af24
    const char* s_8746d = "%s/MTMV_AICodec: [%s(%d)]:> OpenGLHWSContext create failed
"; // string xref
    const char* s_6fb97 = "transferAndWrite"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x12af60
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x12afa4
}

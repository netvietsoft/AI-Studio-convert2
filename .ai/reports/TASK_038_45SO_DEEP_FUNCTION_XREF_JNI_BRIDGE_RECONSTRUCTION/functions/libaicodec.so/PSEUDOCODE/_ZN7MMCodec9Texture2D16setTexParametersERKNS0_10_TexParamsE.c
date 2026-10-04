// Function: MMCodec::Texture2D::setTexParameters(MMCodec::Texture2D::_TexParams const&)
// RVA: 0x17db80, Size: 340 bytes
int64_t _ZN7MMCodec9Texture2D16setTexParametersERKNS0_10_TexParamsE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec2GL13bindTexture2DEj(...); // call imported API via PLT at 0x17dbf8
    glTexParameteri(...); // call imported API via PLT at 0x17dc08
    glTexParameteri(...); // call imported API via PLT at 0x17dc18
    glTexParameteri(...); // call imported API via PLT at 0x17dc28
    glTexParameteri(...); // call imported API via PLT at 0x17dc40
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_91a94 = "[%s(%d)]:> GL_CLAMP_TO_EDGE should be used in NPOT dimensions"; // string xref
    const char* s_6f04b = "setTexParameters"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x17dc80
    const char* s_8804c = "%s/MTMV_AICodec: [%s(%d)]:> GL_CLAMP_TO_EDGE should be used in NPOT dimensions
"; // string xref
    const char* s_6f04b = "setTexParameters"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x17dcc4
    return a0;
}

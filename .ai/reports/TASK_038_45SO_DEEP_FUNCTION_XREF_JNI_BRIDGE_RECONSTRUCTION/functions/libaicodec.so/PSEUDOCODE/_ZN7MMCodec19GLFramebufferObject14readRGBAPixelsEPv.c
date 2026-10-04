// Function: MMCodec::GLFramebufferObject::readRGBAPixels(void*)
// RVA: 0x17596c, Size: 496 bytes
int64_t _ZN7MMCodec19GLFramebufferObject14readRGBAPixelsEPv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glGetIntegerv(...); // call imported API via PLT at 0x1759ac
    glBindFramebuffer(...); // call imported API via PLT at 0x1759bc
    glViewport(...); // call imported API via PLT at 0x1759cc
    glReadPixels(...); // call imported API via PLT at 0x1759e8
    glBindFramebuffer(...); // call imported API via PLT at 0x1759f4
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_722ac = "[%s(%d)]:> GLFramebufferObject not setup"; // string xref
    const char* s_8698e = "readRGBAPixels"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x175a38
    const char* s_815b2 = "%s/MTMV_AICodec: [%s(%d)]:> GLFramebufferObject not setup
"; // string xref
    const char* s_8698e = "readRGBAPixels"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x175a94
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8952d = "[%s(%d)]:> pixels is null"; // string xref
    const char* s_8698e = "readRGBAPixels"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x175ad4
    const char* s_815ed = "%s/MTMV_AICodec: [%s(%d)]:> pixels is null
"; // string xref
    const char* s_8698e = "readRGBAPixels"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x175b30
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x175b58
}

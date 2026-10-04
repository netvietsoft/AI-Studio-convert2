// Function: MMCodec::GLProgram::link()
// RVA: 0x17901c, Size: 448 bytes
int64_t _ZN7MMCodec9GLProgram4linkEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec9GLProgram27bindPredefinedVertexAttribsEv(...); // call imported API via PLT at 0x17904c
    glLinkProgram(...); // call imported API via PLT at 0x179054
    glGetProgramiv(...); // call imported API via PLT at 0x179064
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_82af9 = "[%s(%d)]:> Failed to link program: %i"; // string xref
    const char* s_700c9 = "link"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1790b0
    const char* s_84e17 = "%s/MTMV_AICodec: [%s(%d)]:> Failed to link program: %i
"; // string xref
    const char* s_700c9 = "link"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1790f0
    _ZN7MMCodec2GL13deleteProgramEj(...); // call imported API via PLT at 0x1790f8
    glDeleteShader(...); // call imported API via PLT at 0x179108
    glDeleteShader(...); // call imported API via PLT at 0x179114
    return a0;
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_79c87 = "[%s(%d)]:> Cannot link invalid program"; // string xref
    const char* s_700c9 = "link"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x179184
    const char* s_7d5d8 = "%s/MTMV_AICodec: [%s(%d)]:> Cannot link invalid program
"; // string xref
    const char* s_700c9 = "link"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1791c0
    __stack_chk_fail(...); // call imported API via PLT at 0x1791d8
}

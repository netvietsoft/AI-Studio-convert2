// Function: MMCodec::GLUtil::loadShadersAndCreateProgram(std::__ndk1::basic_string<char, std::__ndk1::char_traits<char>, std::__ndk1::allocator<char>> const&, std::__ndk1::basic_string<char, std::__ndk1::char_traits<char>, std::__ndk1::allocator<char>> const&)
// RVA: 0x10d840, Size: 1256 bytes
int64_t _ZN7MMCodec6GLUtil27loadShadersAndCreateProgramERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glCreateShader(...); // call imported API via PLT at 0x10d878
    glCreateShader(...); // call imported API via PLT at 0x10d884
    glShaderSource(...); // call imported API via PLT at 0x10d8b4
    glCompileShader(...); // call imported API via PLT at 0x10d8bc
    glGetShaderiv(...); // call imported API via PLT at 0x10d8cc
    glGetShaderiv(...); // call imported API via PLT at 0x10d8dc
    glShaderSource(...); // call imported API via PLT at 0x10d910
    glCompileShader(...); // call imported API via PLT at 0x10d918
    glGetShaderiv(...); // call imported API via PLT at 0x10d928
    glGetShaderiv(...); // call imported API via PLT at 0x10d938
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8212b = "[%s(%d)]:> Linking program
"; // string xref
    const char* s_7f03f = "loadShadersAndCreateProgram"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x10d984
    const char* s_7cc77 = "%s/MTMV_AICodec: [%s(%d)]:> Linking program

"; // string xref
    const char* s_7f03f = "loadShadersAndCreateProgram"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x10d9c0
    glCreateProgram(...); // call imported API via PLT at 0x10d9c4
    glAttachShader(...); // call imported API via PLT at 0x10d9d0
    glAttachShader(...); // call imported API via PLT at 0x10d9dc
    glLinkProgram(...); // call imported API via PLT at 0x10d9e4
    glGetProgramiv(...); // call imported API via PLT at 0x10d9f4
    glGetProgramiv(...); // call imported API via PLT at 0x10da04
    glDetachShader(...); // call imported API via PLT at 0x10da1c
    glDetachShader(...); // call imported API via PLT at 0x10da28
    glDeleteShader(...); // call imported API via PLT at 0x10da30
    glDeleteShader(...); // call imported API via PLT at 0x10da38
    _Znwm(...); // call imported API via PLT at 0x10da6c
    memset(...); // call imported API via PLT at 0x10da7c
    glGetShaderInfoLog(...); // call imported API via PLT at 0x10da90
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7dece = "[%s(%d)]:> %s
"; // string xref
    const char* s_7f03f = "loadShadersAndCreateProgram"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x10dad4
    const char* s_83359 = "%s/MTMV_AICodec: [%s(%d)]:> %s

"; // string xref
    const char* s_7f03f = "loadShadersAndCreateProgram"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x10db14
    _Znwm(...); // call imported API via PLT at 0x10db3c
    memset(...); // call imported API via PLT at 0x10db4c
    glGetShaderInfoLog(...); // call imported API via PLT at 0x10db60
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7dece = "[%s(%d)]:> %s
"; // string xref
    const char* s_7f03f = "loadShadersAndCreateProgram"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x10dba4
    const char* s_83359 = "%s/MTMV_AICodec: [%s(%d)]:> %s

"; // string xref
    const char* s_7f03f = "loadShadersAndCreateProgram"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x10dbe4
    _Znwm(...); // call imported API via PLT at 0x10dbf0
    memset(...); // call imported API via PLT at 0x10dc00
    glGetProgramInfoLog(...); // call imported API via PLT at 0x10dc14
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7dece = "[%s(%d)]:> %s
"; // string xref
    const char* s_7f03f = "loadShadersAndCreateProgram"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x10dc50
    const char* s_83359 = "%s/MTMV_AICodec: [%s(%d)]:> %s

"; // string xref
    const char* s_7f03f = "loadShadersAndCreateProgram"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x10dc88
    glDeleteShader(...); // call imported API via PLT at 0x10dc90
    glDeleteShader(...); // call imported API via PLT at 0x10dc98
    glDeleteProgram(...); // call imported API via PLT at 0x10dca0
    _ZdlPv(...); // call imported API via PLT at 0x10dcac
    return a0;
    _ZdlPv(...); // call imported API via PLT at 0x10dd08
    __stack_chk_fail(...); // call imported API via PLT at 0x10dd24
}

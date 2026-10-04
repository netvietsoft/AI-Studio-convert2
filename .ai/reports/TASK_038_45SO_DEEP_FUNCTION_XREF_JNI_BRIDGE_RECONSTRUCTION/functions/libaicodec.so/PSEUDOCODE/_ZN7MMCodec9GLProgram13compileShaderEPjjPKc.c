// Function: MMCodec::GLProgram::compileShader(unsigned int*, unsigned int, char const*)
// RVA: 0x1791dc, Size: 528 bytes
int64_t _ZN7MMCodec9GLProgram13compileShaderEPjjPKc(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glCreateShader(...); // call imported API via PLT at 0x179218
    glShaderSource(...); // call imported API via PLT at 0x179230
    glCompileShader(...); // call imported API via PLT at 0x179238
    glGetShaderiv(...); // call imported API via PLT at 0x179248
    glGetShaderInfoLog(...); // call imported API via PLT at 0x1792ac
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_7365d = "[%s(%d)]:> Could not compile shader %d"; // string xref
    const char* s_89553 = "compileShader"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1792f0
    const char* s_8110e = "%s/MTMV_AICodec: [%s(%d)]:> %s
"; // string xref
    const char* s_89553 = "compileShader"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x179348
    return a0;
    const char* s_6dea2 = "%s/MTMV_AICodec: [%s(%d)]:> Could not compile shader %d
"; // string xref
    const char* s_89553 = "compileShader"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1793a0
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_8ed6c = "[%s(%d)]:> %s"; // string xref
    const char* s_89553 = "compileShader"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1793d4
    __stack_chk_fail(...); // call imported API via PLT at 0x1793e8
}

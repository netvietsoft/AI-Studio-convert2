// Function: PVGCOLOR::PVGOpenGL::createComputeShader(char const*, int*)
// RVA: 0x52a78, Size: 352 bytes
int64_t _ZN8PVGCOLOR9PVGOpenGL19createComputeShaderEPKcPi(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glCreateShader(...); // call PLT API at 0x52aa8
    glShaderSource(...); // call PLT API at 0x52ac0
    glCompileShader(...); // call PLT API at 0x52ac8
    glGetShaderiv(...); // call PLT API at 0x52ad8
    return a0;
    glGetShaderiv(...); // call PLT API at 0x52b44
    _Znam(...); // call PLT API at 0x52b50
    glGetShaderInfoLog(...); // call PLT API at 0x52b68
    const char* str = "PVGColorFunctions";
    const char* str = "[%s(%d)]:> PVGOpenGL createComputeShader failed %s
";
    const char* str = "createComputeShader";
    __android_log_print(...); // call PLT API at 0x52bac
    _ZdaPv(...); // call PLT API at 0x52bb4
    glDeleteShader(...); // call PLT API at 0x52bbc
    __stack_chk_fail(...); // call PLT API at 0x52bd4
}

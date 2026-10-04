// Function: PVGCOLOR::PVGOpenGL::createComputeProgram(int, int*)
// RVA: 0x51158, Size: 556 bytes
int64_t _ZN8PVGCOLOR9PVGOpenGL20createComputeProgramEiPi(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glCreateProgram(...); // call PLT API at 0x51188
    glAttachShader(...); // call PLT API at 0x51194
    glLinkProgram(...); // call PLT API at 0x5119c
    glGetProgramiv(...); // call PLT API at 0x511ac
    const char* str = "PVGColorFunctions";
    const char* str = "[%s(%d)]:> PVGOpenGL createComputeProgram failed: invalid shader %d
";
    const char* str = "createComputeProgram";
    __android_log_print(...); // call PLT API at 0x51208
    glGetProgramiv(...); // call PLT API at 0x51228
    _ZnamRKSt9nothrow_t(...); // call PLT API at 0x5124c
    glGetProgramInfoLog(...); // call PLT API at 0x51268
    const char* str = "PVGColorFunctions";
    const char* str = "[%s(%d)]:> PVGOpenGL createComputeProgram failed %s
";
    const char* str = "createComputeProgram";
    __android_log_print(...); // call PLT API at 0x512ac
    _ZdaPv(...); // call PLT API at 0x512b4
    const char* str = "PVGColorFunctions";
    const char* str = "[%s(%d)]:> PVGOpenGL createComputeProgram failed: invalid log length %d
";
    const char* str = "createComputeProgram";
    __android_log_print(...); // call PLT API at 0x51304
    const char* str = "PVGColorFunctions";
    const char* str = "[%s(%d)]:> PVGOpenGL createComputeProgram failed: memory allocation failed for log
";
    const char* str = "createComputeProgram";
    __android_log_print(...); // call PLT API at 0x51348
    glDeleteProgram(...); // call PLT API at 0x51350
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x51380
}

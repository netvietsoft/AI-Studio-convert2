// Function: PVGCOLOR::PVGOpenGL::createRenderProgram(char const*, char const*, int*)
// RVA: 0x51384, Size: 1640 bytes
int64_t _ZN8PVGCOLOR9PVGOpenGL19createRenderProgramEPKcS2_Pi(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glCreateShader(...); // call PLT API at 0x513cc
    glShaderSource(...); // call PLT API at 0x513e4
    glCompileShader(...); // call PLT API at 0x513ec
    glGetShaderiv(...); // call PLT API at 0x513fc
    glCreateShader(...); // call PLT API at 0x5140c
    glShaderSource(...); // call PLT API at 0x51424
    glCompileShader(...); // call PLT API at 0x5142c
    glGetShaderiv(...); // call PLT API at 0x5143c
    glCreateProgram(...); // call PLT API at 0x51448
    glAttachShader(...); // call PLT API at 0x51458
    glAttachShader(...); // call PLT API at 0x51464
    glLinkProgram(...); // call PLT API at 0x5146c
    glGetProgramiv(...); // call PLT API at 0x5147c
    glGetProgramiv(...); // call PLT API at 0x51498
    _ZnamRKSt9nothrow_t(...); // call PLT API at 0x514bc
    glGetProgramInfoLog(...); // call PLT API at 0x514d8
    const char* str = "PVGColorFunctions";
    const char* str = "[%s(%d)]:> PVGOpenGL createRenderProgram failed (link) %s
";
    const char* str = "createRenderProgram";
    __android_log_print(...); // call PLT API at 0x5151c
    _ZdaPv(...); // call PLT API at 0x51524
    const char* str = "PVGColorFunctions";
    const char* str = "[%s(%d)]:> PVGOpenGL createRenderProgram invalid input vertex %p frag %p program %p
";
    const char* str = "createRenderProgram";
    __android_log_print(...); // call PLT API at 0x5156c
    glGetError(...); // call PLT API at 0x515a8
    const char* str = "PVGColorFunctions";
    const char* str = "[%s(%d)]:> PVGOpenGL createRenderProgram failed: glCreateShader(GL_VERTEX_SHADER) returned 0, err %x
";
    const char* str = "createRenderProgram";
    __android_log_print(...); // call PLT API at 0x515d0
    glGetShaderiv(...); // call PLT API at 0x515fc
    _ZnamRKSt9nothrow_t(...); // call PLT API at 0x51620
    glGetShaderInfoLog(...); // call PLT API at 0x5163c
    const char* str = "PVGColorFunctions";
    const char* str = "[%s(%d)]:> PVGOpenGL createRenderProgram failed (vertex shader) %s
";
    const char* str = "createRenderProgram";
    __android_log_print(...); // call PLT API at 0x51680
    _ZdaPv(...); // call PLT API at 0x51688
    glGetError(...); // call PLT API at 0x516b0
    const char* str = "PVGColorFunctions";
    const char* str = "[%s(%d)]:> PVGOpenGL createRenderProgram failed: glCreateShader(GL_FRAGMENT_SHADER) returned 0, err %x
";
    const char* str = "createRenderProgram";
    __android_log_print(...); // call PLT API at 0x516d8
    const char* str = "PVGColorFunctions";
    const char* str = "[%s(%d)]:> PVGOpenGL createRenderProgram failed (vertex shader): invalid log length %d
";
    const char* str = "createRenderProgram";
    __android_log_print(...); // call PLT API at 0x51720
    glGetShaderiv(...); // call PLT API at 0x51738
    _ZnamRKSt9nothrow_t(...); // call PLT API at 0x5175c
    glGetShaderInfoLog(...); // call PLT API at 0x51778
    const char* str = "PVGColorFunctions";
    const char* str = "[%s(%d)]:> PVGOpenGL createRenderProgram failed (fragment shader) %s
";
    const char* str = "createRenderProgram";
    __android_log_print(...); // call PLT API at 0x517bc
    _ZdaPv(...); // call PLT API at 0x517c4
    glGetError(...); // call PLT API at 0x517ec
    const char* str = "PVGColorFunctions";
    const char* str = "[%s(%d)]:> PVGOpenGL createRenderProgram failed: glCreateProgram returned 0, err %x
";
    const char* str = "createRenderProgram";
    __android_log_print(...); // call PLT API at 0x51814
    const char* str = "PVGColorFunctions";
    const char* str = "[%s(%d)]:> PVGOpenGL createRenderProgram failed (fragment shader): invalid log length %d
";
    const char* str = "createRenderProgram";
    __android_log_print(...); // call PLT API at 0x5185c
    const char* str = "PVGColorFunctions";
    const char* str = "[%s(%d)]:> PVGOpenGL createRenderProgram failed (vertex shader): memory allocation failed for log
";
    const char* str = "createRenderProgram";
    __android_log_print(...); // call PLT API at 0x518a0
    const char* str = "PVGColorFunctions";
    const char* str = "[%s(%d)]:> PVGOpenGL createRenderProgram failed (link): invalid log length %d
";
    const char* str = "createRenderProgram";
    __android_log_print(...); // call PLT API at 0x518e8
    const char* str = "PVGColorFunctions";
    const char* str = "[%s(%d)]:> PVGOpenGL createRenderProgram failed (fragment shader): memory allocation failed for log
";
    const char* str = "createRenderProgram";
    __android_log_print(...); // call PLT API at 0x5192c
    glDeleteShader(...); // call PLT API at 0x51934
    glDeleteShader(...); // call PLT API at 0x5193c
    return a0;
    const char* str = "PVGColorFunctions";
    const char* str = "[%s(%d)]:> PVGOpenGL createRenderProgram failed (link): memory allocation failed for log
";
    const char* str = "createRenderProgram";
    __android_log_print(...); // call PLT API at 0x519ac
    glDeleteProgram(...); // call PLT API at 0x519b4
    glDeleteShader(...); // call PLT API at 0x519c0
    glDeleteShader(...); // call PLT API at 0x519c8
    __stack_chk_fail(...); // call PLT API at 0x519e8
}

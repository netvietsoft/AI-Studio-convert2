// Function: sub_AD32EC
// RVA: 0xad32ec, Size: 416 bytes
int64_t sub_AD32EC(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glGenFramebuffers(...); // call PLT API at 0xad331c
    glBindFramebuffer(...); // call PLT API at 0xad3328
    sub_698574(...); // call internal at 0xad3330
    sub_69B7C4(...); // call internal at 0xad3334
    glFramebufferTexture2D(...); // call PLT API at 0xad334c
    glGenRenderbuffers(...); // call PLT API at 0xad3364
    glBindRenderbuffer(...); // call PLT API at 0xad3370
    glGetString(...); // call PLT API at 0xad3378
    glGetString(...); // call PLT API at 0xad3384
    const char* str = "OpenGL ES 2.";
    strstr(...); // call PLT API at 0xad3390
    const char* str = "GL_OES_depth24";
    strstr(...); // call PLT API at 0xad33a4
    sub_698564(...); // call internal at 0xad33c0
    sub_69856C(...); // call internal at 0xad33cc
    glRenderbufferStorage(...); // call PLT API at 0xad33e0
    glFramebufferRenderbuffer(...); // call PLT API at 0xad33f4
    glCheckFramebufferStatus(...); // call PLT API at 0xad33fc
    const char* str = "arkernel";
    const char* str = "Create FrameBuffer error. ID = %d";
    sub_5A6B20(...); // call internal at 0xad3454
    return a0;
    const char* str = "arkernel";
    const char* str = "Create FrameBuffer error. ID = %d";
    __android_log_print(...); // call PLT API at 0xad3488
}

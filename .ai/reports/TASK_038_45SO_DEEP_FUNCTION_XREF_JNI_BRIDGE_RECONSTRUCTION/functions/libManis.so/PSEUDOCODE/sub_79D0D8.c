// Function: sub_79D0D8
// RVA: 0x79d0d8, Size: 1284 bytes
int64_t sub_79D0D8(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    eglGetCurrentDisplay(...); // call PLT API at 0x79d110
    eglGetCurrentContext(...); // call PLT API at 0x79d118
    sub_33ACE0(...); // call internal at 0x79d15c
    const char* str = "OpenGLContext";
    const char* str = "%s: OpenGL context mismatch, init_display=%p, init_context=%p, current_display=%p, current_context=%p";
    sub_3585C4(...); // call internal at 0x79d180
    const char* str = " is null";
    const char* str = "Mizar";
    __android_log_print(...); // call PLT API at 0x79d39c
    const char* str = " is null";
    fprintf(...); // call PLT API at 0x79d58c
    sub_33ACFC(...); // call internal at 0x79d59c
    _ZdlPv(...); // call PLT API at 0x79d5ac
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x79d5d8
}

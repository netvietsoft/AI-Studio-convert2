// Function: sub_AA7318
// RVA: 0xaa7318, Size: 384 bytes
int64_t sub_AA7318(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glBindFramebuffer(...); // call PLT API at 0xaa7360
    sub_698574(...); // call internal at 0xaa7368
    sub_69B7C4(...); // call internal at 0xaa736c
    glFramebufferTexture2D(...); // call PLT API at 0xaa7384
    sub_69871C(...); // call internal at 0xaa738c
    sub_69B7C4(...); // call internal at 0xaa7390
    glFramebufferTexture2D(...); // call PLT API at 0xaa73a8
    glBindFramebuffer(...); // call PLT API at 0xaa73b4
    glEnable(...); // call PLT API at 0xaa73bc
    glBlendFunc(...); // call PLT API at 0xaa73c8
    glDrawBuffers(...); // call PLT API at 0xaa73e0
    glClearBufferfv(...); // call PLT API at 0xaa7400
    sub_744B04(...); // call internal at 0xaa7438
    sub_744B04(...); // call internal at 0xaa7448
    sub_AA9C98(...); // call internal at 0xaa745c
    glDrawBuffers(...); // call PLT API at 0xaa7468
    glDisable(...); // call PLT API at 0xaa7470
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xaa7494
}

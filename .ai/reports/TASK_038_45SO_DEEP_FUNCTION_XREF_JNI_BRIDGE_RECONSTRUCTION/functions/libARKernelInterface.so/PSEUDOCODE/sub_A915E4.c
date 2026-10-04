// Function: sub_A915E4
// RVA: 0xa915e4, Size: 432 bytes
int64_t sub_A915E4(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "
attribute vec3 a_Position;
uniform mat4 u_mvpMatrix;

void main()
{
    gl_Position = u_mvpMatrix * vec4(a_Position, 1.0);
}
";
    const char* str = "
#ifdef GL_ES
precision mediump float;
#endif

void main()
{
    gl_FragColor = vec4(1.0, 1.0, 1.0, 1.0);
}
";
    (*x8)(...);
    (*x8)(...);
    glViewport(...); // call PLT API at 0xa91680
    glDisable(...); // call PLT API at 0xa91688
    (*x8)(...);
    const char* str = "u_mvpMatrix";
    (*x8)(...);
    const char* str = "a_Position";
    (*x8)(...);
    glDrawElements(...); // call PLT API at 0xa91704
    (*x8)(...);
    const char* str = "arkernel";
    const char* str = "FilterPhotoshopBlender::DrawWhiteMeshDepthToFBO: white mesh program unavailable";
    sub_5A6B20(...); // call internal at 0xa91758
    const char* str = "arkernel";
    const char* str = "FilterPhotoshopBlender::DrawWhiteMeshDepthToFBO: white mesh program unavailable";
    __android_log_print(...); // call PLT API at 0xa91774
    return a0;
}

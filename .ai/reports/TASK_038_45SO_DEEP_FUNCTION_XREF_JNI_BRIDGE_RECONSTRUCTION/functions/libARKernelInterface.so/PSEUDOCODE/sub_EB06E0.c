// Function: sub_EB06E0
// RVA: 0xeb06e0, Size: 324 bytes
int64_t sub_EB06E0(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "uniform mat4 u_viewProjectionMatrix;
attribute vec4 a_position;
attribute vec4 a_color;
varying vec4 v_color;
void main(void) {
";
    const char* str = "precision highp float;
varying vec4 v_color;
void main(void) {
   gl_FragColor = v_color;
}";
    sub_D38264(...); // call internal at 0xeb0718
    sub_DAF19C(...); // call internal at 0xeb0730
    sub_DAF19C(...); // call internal at 0xeb0740
    sub_DAF008(...); // call internal at 0xeb0750
    sub_D5AE3C(...); // call internal at 0xeb0758
    sub_D610FC(...); // call internal at 0xeb0778
    sub_D7FFBC(...); // call internal at 0xeb0788
    sub_D5AE3C(...); // call internal at 0xeb0790
    sub_D610FC(...); // call internal at 0xeb07b0
    sub_D7FFBC(...); // call internal at 0xeb07c0
    sub_D7FFBC(...); // call internal at 0xeb07cc
    sub_DAF150(...); // call internal at 0xeb07d4
    return a0;
    sub_DAF150(...); // call internal at 0xeb0804
    sub_1042BE4(...); // call internal at 0xeb081c
    __stack_chk_fail(...); // call PLT API at 0xeb0820
}

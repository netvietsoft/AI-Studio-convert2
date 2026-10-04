// Function: MTFilterKernel::CMTDynamicFilter::CopyTextureContents(unsigned int, unsigned int, unsigned int)
// RVA: 0x11ec64, Size: 548 bytes
int64_t _ZN14MTFilterKernel16CMTDynamicFilter19CopyTextureContentsEjjj(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glBindFramebuffer(...); // call PLT API at 0x11ec9c
    glFramebufferTexture2D(...); // call PLT API at 0x11ecb4
    glCheckFramebufferStatus(...); // call PLT API at 0x11ecbc
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x11ecd0
    const char* str = "FilterKernel";
    const char* str = "CMTDynamicFilter::BindFBO(%u)::Create FrameBuffer error. ID = %d";
    __android_log_print(...); // call PLT API at 0x11ecf8
    const char* str = "#ifdef GL_ES
#ifdef GL_FRAGMENT_PRECISION_HIGH
precision highp float;
#else
precision mediump float;
#endif
#else
#define highp
";
    memcpy(...); // call PLT API at 0x11ed14
    const char* str = "attribute vec4 position;
attribute vec2 texcoord;
varying vec2 texcoordOut;
void main()
{
    texcoordOut = texcoord;
    gl_Pos";
    _ZN14MTFilterKernel7GLUtils20CreateProgram_SourceEPKcS2_(...); // call internal at 0x11ed58
    glUseProgram(...); // call PLT API at 0x11ed60
    glViewport(...); // call PLT API at 0x11ed70
    glActiveTexture(...); // call PLT API at 0x11ed98
    glBindTexture(...); // call PLT API at 0x11eda4
    const char* str = "texture";
    _ZN14MTFilterKernel16CMTDynamicFilter18GetUniformLocationEjPKc(...); // call internal at 0x11edb8
    glUniform1i(...); // call PLT API at 0x11edc0
    const char* str = "position";
    _ZN14MTFilterKernel16CMTDynamicFilter17GetAttribLocationEjPKc(...); // call internal at 0x11edd8
    glEnableVertexAttribArray(...); // call PLT API at 0x11eddc
    _ZN14MTFilterKernel16CMTDynamicFilter17GetAttribLocationEjPKc(...); // call internal at 0x11edec
    glVertexAttribPointer(...); // call PLT API at 0x11ee04
    const char* str = "texcoord";
    _ZN14MTFilterKernel16CMTDynamicFilter17GetAttribLocationEjPKc(...); // call internal at 0x11ee1c
    glEnableVertexAttribArray(...); // call PLT API at 0x11ee20
    _ZN14MTFilterKernel16CMTDynamicFilter17GetAttribLocationEjPKc(...); // call internal at 0x11ee30
    glVertexAttribPointer(...); // call PLT API at 0x11ee48
    glDrawArrays(...); // call PLT API at 0x11ee58
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x11ee84
}

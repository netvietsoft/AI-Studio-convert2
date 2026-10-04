// Function: MTFilterKernel::CMTDynamicFilter::CopyTextureContents(unsigned int, unsigned int)
// RVA: 0x11daac, Size: 500 bytes
int64_t _ZN14MTFilterKernel16CMTDynamicFilter19CopyTextureContentsEjj(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel16CMTDynamicFilter7BindFBOEj(...); // call internal at 0x11dadc
    const char* str = "#ifdef GL_ES
#ifdef GL_FRAGMENT_PRECISION_HIGH
precision highp float;
#else
precision mediump float;
#endif
#else
#define highp
";
    memcpy(...); // call PLT API at 0x11daf8
    const char* str = "attribute vec4 position;
attribute vec2 texcoord;
varying vec2 texcoordOut;
void main()
{
    texcoordOut = texcoord;
    gl_Pos";
    _ZN14MTFilterKernel7GLUtils20CreateProgram_SourceEPKcS2_(...); // call internal at 0x11db3c
    glUseProgram(...); // call PLT API at 0x11db44
    glViewport(...); // call PLT API at 0x11db54
    glActiveTexture(...); // call PLT API at 0x11db7c
    glBindTexture(...); // call PLT API at 0x11db88
    const char* str = "texture";
    _ZN14MTFilterKernel16CMTDynamicFilter18GetUniformLocationEjPKc(...); // call internal at 0x11db9c
    glUniform1i(...); // call PLT API at 0x11dba4
    const char* str = "position";
    _ZN14MTFilterKernel16CMTDynamicFilter17GetAttribLocationEjPKc(...); // call internal at 0x11dbbc
    glEnableVertexAttribArray(...); // call PLT API at 0x11dbc0
    _ZN14MTFilterKernel16CMTDynamicFilter17GetAttribLocationEjPKc(...); // call internal at 0x11dbd0
    glVertexAttribPointer(...); // call PLT API at 0x11dbe8
    const char* str = "texcoord";
    _ZN14MTFilterKernel16CMTDynamicFilter17GetAttribLocationEjPKc(...); // call internal at 0x11dc00
    glEnableVertexAttribArray(...); // call PLT API at 0x11dc04
    _ZN14MTFilterKernel16CMTDynamicFilter17GetAttribLocationEjPKc(...); // call internal at 0x11dc14
    glVertexAttribPointer(...); // call PLT API at 0x11dc2c
    glDrawArrays(...); // call PLT API at 0x11dc3c
    _ZN14MTFilterKernel16CMTDynamicFilter17GetAttribLocationEjPKc(...); // call internal at 0x11dc4c
    glDisableVertexAttribArray(...); // call PLT API at 0x11dc50
    _ZN14MTFilterKernel16CMTDynamicFilter17GetAttribLocationEjPKc(...); // call internal at 0x11dc60
    glDisableVertexAttribArray(...); // call PLT API at 0x11dc64
    glBindFramebuffer(...); // call PLT API at 0x11dc70
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x11dc9c
}

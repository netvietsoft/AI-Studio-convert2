// Function: MTFilterKernel::MTDrawArrayFilter::initShaderVarLocation()
// RVA: 0xed920, Size: 736 bytes
int64_t _ZN14MTFilterKernel17MTDrawArrayFilter21initShaderVarLocationEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "position";
    _ZN14MTFilterKernel15GPUImageProgram17GetAttribLocationEPKc(...); // call internal at 0xed960
    const char* str = "texcoord";
    _ZN14MTFilterKernel15GPUImageProgram17GetAttribLocationEPKc(...); // call internal at 0xed978
    const char* str = "texcoord2";
    _ZN14MTFilterKernel15GPUImageProgram17GetAttribLocationEPKc(...); // call internal at 0xed990
    const char* str = "mvpMatrix";
    _ZN14MTFilterKernel15GPUImageProgram18GetUniformLocationEPKc(...); // call internal at 0xed9a8
    const char* str = "inputImageTexture%d";
    sub_EDC00(...); // call internal at 0xeda0c
    _ZN14MTFilterKernel15GPUImageProgram18GetUniformLocationEPKc(...); // call internal at 0xeda18
    _Znwm(...); // call PLT API at 0xeda80
    _ZdlPv(...); // call PLT API at 0xedb28
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0xedb38
    const char* str = "FilterKernel";
    const char* str = "inputImageTexture GetUniformLocation failed index=%d";
    __android_log_print(...); // call PLT API at 0xedb5c
    return a0;
    sub_EF718(...); // call internal at 0xedbe0
    sub_C8A94(...); // call internal at 0xedbf8
    __stack_chk_fail(...); // call PLT API at 0xedbfc
}

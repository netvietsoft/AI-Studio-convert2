// Function: MTFilterKernel::CMTGaussianFilter::FindGLHandle()
// RVA: 0x120700, Size: 224 bytes
int64_t _ZN14MTFilterKernel17CMTGaussianFilter12FindGLHandleEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel16CMTDynamicFilter12FindGLHandleEv(...); // call internal at 0x12071c
    const char* str = "texelWidthOffset";
    glGetUniformLocation(...); // call PLT API at 0x120730
    const char* str = "texelHeightOffset";
    glGetUniformLocation(...); // call PLT API at 0x12074c
    const char* str = "position";
    glGetAttribLocation(...); // call PLT API at 0x120764
    const char* str = "texcoord";
    glGetAttribLocation(...); // call PLT API at 0x12077c
    glGetUniformLocation(...); // call PLT API at 0x120790
    glGetUniformLocation(...); // call PLT API at 0x1207a4
    const char* str = "inputImageTexture0";
    glGetUniformLocation(...); // call PLT API at 0x1207bc
    _ZN14MTFilterKernel17CMTGaussianFilter15refreshBlurSizeEv(...); // call internal at 0x1207d8
    return a0;
}

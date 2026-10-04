// Function: MTFilterKernel::CMTBokehBlurFilter::ScalingFilterToFBO(int, int, int, int)
// RVA: 0x122d88, Size: 228 bytes
int64_t _ZN14MTFilterKernel18CMTBokehBlurFilter18ScalingFilterToFBOEiiii(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glBindFramebuffer(...); // call PLT API at 0x122db0
    glViewport(...); // call PLT API at 0x122dc4
    glClear(...); // call PLT API at 0x122dcc
    _ZN14MTFilterKernel10CGLProgram3UseEv(...); // call internal at 0x122dd4
    glActiveTexture(...); // call PLT API at 0x122ddc
    glBindTexture(...); // call PLT API at 0x122de8
    const char* str = "inputImageTexture";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x122dfc
    const char* str = "position";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x122e24
    const char* str = "inputTextureCoordinate";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x122e4c
    glDrawArrays(...); // call PLT API at 0x122e68
}
